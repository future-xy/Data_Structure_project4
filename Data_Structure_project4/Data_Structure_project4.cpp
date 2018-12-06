#include "Data_Structure_project4.h"

#include <fstream>

#include <qtranslator.h>
#include <qsettings.h>
#include <cstdio>
#include <qdebug.h>
#include <qgraphicsitem.h>

using std::make_pair;

extern QTranslator *trans;
extern QString readSetting();



Data_Structure_project4::Data_Structure_project4(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	this->image = new QImage();
	QString filename = "map.png";
	_map = new Map;
	theStatus = Empty;

	if (image->load(filename))
	{
		scene = new QGraphicsScene;
		scene->addPixmap(QPixmap::fromImage(*image));
		ui.Background->setScene(scene);
		ui.Background->resize(1280, 720);
		ui.Background->show();
	}
	vector<Node> the_place = _map->getPlace();
	for (auto item : the_place)
	{
		QGraphicsEllipseItem *temp_item=new QGraphicsEllipseItem(item.coordinate.first, item.coordinate.second, 10, 10);
		temp_item->setBrush(QColor(200, 0, 0));
		scene->addItem(temp_item);
		places.push_back(temp_item);
	}
	ui.Background->setMouseTracking(true);
	ui.textBrowser->setVisible(false);
	the_parking_lot.load("parking_lot.png");
	the_restaurant.load("restaurant.png");
	the_smarket.load("smarket.png");
	the_WC.load("wc.png");
	QObject::connect(ui.Background, SIGNAL(mouseMovePoint(QPoint)),
		this, SLOT(on_mouseMovePoint(QPoint)));

	QObject::connect(ui.Background, SIGNAL(mouseClicked(QPoint)),
		this, SLOT(on_mouseClicked(QPoint)));
	//show place
}

Data_Structure_project4::~Data_Structure_project4()
{
	if (image != nullptr)
		delete image;
	if (_map != nullptr)
		delete _map;
	if (scene != nullptr)
		delete scene;
	for (auto item : mypath)
	{
		delete item;
	}
	for (auto item : points)
	{
		delete item;
	}
	for (auto item : places)
	{
		delete item;
	}
}

/*void Data_Structure_project4::on_mouseMovePoint(QPoint point)
{//鼠标移动事件，point是 GraphicsView的坐标,物理坐标
}*/

void Data_Structure_project4::on_mouseClicked(QPoint point)
{//鼠标单击事件
	QPointF pointScene = ui.Background->mapToScene(point);
	Coordinate cor = _map->MatchSite(make_pair(pointScene.x(), pointScene.y()));
	QPointF cur_cor(cor.first, cor.second);
	if (cor.first != -1 && cor.second != -1)
	{
		if (theStatus == Navigation)
		{
			path_to_save.push_back(cur_cor);
		}
		else
		{
			QString info = QString::fromStdString(_map->Info(cor));
			ui.textBrowser->setVisible(true);
			ui.textBrowser->setText(info);
		}
	}
}

void Data_Structure_project4::on_Start_clicked()
{
	theStatus = Navigation;
	path_to_save.clear();
}

void Data_Structure_project4::on_Driving_Navigation_clicked()
{
	vector<Coordinate> temp_path;
	for (auto it : path_to_save)
	{
		temp_path.push_back(make_pair(it.x(), it.y()));
	}
	if (temp_path.size() < 2)
		return;
	path_to_show.clear();
	path_to_show = _map->shortest_Navigation_Car(temp_path);
	for (auto item : mypath)
	{
		delete item;
	}
	mypath.clear();
	QPen temp_pen;
	temp_pen.setWidth(3);
	temp_pen.setColor(QColor(0, 0, 255));
	for (auto item = path_to_show.begin(); item + 1 != path_to_show.end(); ++item)
	{

		QGraphicsLineItem *temp_line = new QGraphicsLineItem(item->first, item->second, \
			(item + 1)->first, (item + 1)->second);

		temp_line->setPen(temp_pen);
		mypath.push_back(temp_line);
		scene->addItem(temp_line);
	}
}

void Data_Structure_project4::on_Walking_Navigation_clicked()
{
	vector<Coordinate> temp_path;
	for (auto it : path_to_save)
	{
		temp_path.push_back(make_pair(it.x(), it.y()));
	}
	if (temp_path.size() < 2)
		return;
	
	path_to_show.clear();
	path_to_show = _map->shortest_Navigation_Walk(temp_path);
	for (auto item : mypath)
	{
		delete item;
	}
	mypath.clear();
	QPen temp_pen;
	temp_pen.setWidth(3);
	temp_pen.setColor(QColor(0, 255, 0));
	for (auto item = path_to_show.begin(); item + 1 != path_to_show.end(); ++item)
	{

		QGraphicsLineItem *temp_line = new QGraphicsLineItem(item->first, item->second, \
			(item + 1)->first, (item + 1)->second);

		temp_line->setPen(temp_pen);
		mypath.push_back(temp_line);
		scene->addItem(temp_line);
	}
}

void Data_Structure_project4::on_Quit_clicked()
{
	for (auto item : mypath)
	{
		delete item;
	}
	mypath.clear();
;
	for (auto item : points)
	{
		delete item;
	}
	points.clear();
	path_to_save.clear();
	path_to_show.clear();
	theStatus = Empty;
	ui.textBrowser->clear();
	ui.textBrowser->setVisible(false);
}

void Data_Structure_project4::on_recommended_clicked()
{

}

void Data_Structure_project4::on_recommended2_clicked()
{

}

void Data_Structure_project4::on_recommended3_clicked()
{

}

void Data_Structure_project4::on_Parking_lot_clicked()
{
	ui.textBrowser->clear();
	ui.textBrowser->setVisible(false);
	for (auto item : points)
	{
		delete item;
	}
	points.clear();
	vector<Node> the_point = _map->getParking_lot();

	for (auto item : the_point)
	{
		QGraphicsPixmapItem *temp_item = new QGraphicsPixmapItem(the_parking_lot);
		temp_item->setX(item.coordinate.first);
		temp_item->setY(item.coordinate.second);
		scene->addItem(temp_item);
		points.push_back(temp_item);
	}
}

void Data_Structure_project4::on_Restaurant_clicked()
{
	ui.textBrowser->clear();
	ui.textBrowser->setVisible(false);
	for (auto item : points)
	{
		delete item;
	}
	points.clear();
	vector<Node> the_point = _map->getRestaurant();

	for (auto item : the_point)
	{
		QGraphicsPixmapItem *temp_item = new QGraphicsPixmapItem(the_restaurant);
		temp_item->setX(item.coordinate.first);
		temp_item->setY(item.coordinate.second);
		scene->addItem(temp_item);
		points.push_back(temp_item);
	}
}

void Data_Structure_project4::on_Smarket_clicked()
{
	ui.textBrowser->clear();
	ui.textBrowser->setVisible(false);
	for (auto item : points)
	{
		delete item;
	}
	points.clear();
	vector<Node> the_point = _map->getSmarket();

	for (auto item : the_point)
	{
		QGraphicsPixmapItem *temp_item = new QGraphicsPixmapItem(the_smarket);
		temp_item->setX(item.coordinate.first);
		temp_item->setY(item.coordinate.second);
		scene->addItem(temp_item);
		points.push_back(temp_item);
	}
}

void Data_Structure_project4::on_WC_clicked()
{
	ui.textBrowser->clear();
	ui.textBrowser->setVisible(false);
	for (auto item : points)
	{
		delete item;
	}
	points.clear();
	vector<Node> the_point = _map->getWC();

	for (auto item : the_point)
	{
		QGraphicsPixmapItem *temp_item = new QGraphicsPixmapItem(the_WC);
		temp_item->setX(item.coordinate.first);
		temp_item->setY(item.coordinate.second);
		scene->addItem(temp_item);
		points.push_back(temp_item);
	}
}

void Data_Structure_project4::on_Test_Function_clicked()
{
	ui.textBrowser->clear();
	ui.textBrowser->setVisible(false);
}

void Data_Structure_project4::on_Translate_clicked()
{
	if (trans != nullptr)
	{
		qApp->removeTranslator(trans);
		delete trans;
		trans = nullptr;
	}

	QString curLang = readSetting();
	trans = new QTranslator;
	QSettings settings("WWB-Qt", "data_structure_project4");
	if (curLang == "EN")
	{
		trans->load("data_structure_project4_zh.qm");
		settings.setValue("Language", "ZH");
	}
	else
	{
		trans->load("data_structure_project4_en.qm");
		settings.setValue("Language", "EN");
	}

	qApp->installTranslator(trans);
	ui.retranslateUi(this);
}
