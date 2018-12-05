#include "Data_Structure_project4.h"

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
	mypath = nullptr;
	ui.Background->setMouseTracking(true);
	ui.textBrowser->setVisible(false);
	
	QObject::connect(ui.Background, SIGNAL(mouseMovePoint(QPoint)),
		this, SLOT(on_mouseMovePoint(QPoint)));

	QObject::connect(ui.Background, SIGNAL(mouseClicked(QPoint)),
		this, SLOT(on_mouseClicked(QPoint)));
	//show place
}

Data_Structure_project4::~Data_Structure_project4()
{
	delete image;
	delete _map;
	delete scene;
}

void Data_Structure_project4::on_mouseMovePoint(QPoint point)
{//鼠标移动事件，point是 GraphicsView的坐标,物理坐标

	//labViewCord->setText(QString::asprintf("View 坐标：%d,%d", point.x(), point.y()));
	//ui.textBrowser->setText(QString::asprintf("View：%d,%d", point.x(), point.y()));
	//QPointF pointScene = ui.Background->mapToScene(point); //转换到Scene坐标
	//ui.textBrowser->setText(QString::asprintf("Scene ：%.0f,%.0f", pointScene.x(), pointScene.y()));
}

void Data_Structure_project4::on_mouseClicked(QPoint point)
{//鼠标单击事件
	QPointF pointScene = ui.Background->mapToScene(point);
	Coordinate cor = _map->MatchSite(make_pair(pointScene.x(), pointScene.y()));
	if (cor.first != -1 && cor.second != -1)
	{
		if (theStatus == Navigation)
		{
			path_to_save.push_back(pointScene);
		}
		else
		{
			QString info = QString::fromStdString(_map->Info(cor));
			ui.textBrowser->setText(info);
		}
	}
}

void Data_Structure_project4::on_Start_clicked()
{
	theStatus = Navigation;
}

void Data_Structure_project4::on_Driving_Navigation_clicked()
{
	ui.textBrowser->setVisible(true);
	vector<Coordinate> temp_path;
	for (auto it : path_to_save)
	{
		temp_path.push_back(make_pair(it.x(), it.y()));
	}
	if (temp_path.size() < 2)
		return;
	path_to_show.clear();
	path_to_show = _map->shortest_Navigation_Car(temp_path);
	if (mypath != nullptr)
		delete mypath;
	mypath = new QPainterPath;
	mypath->moveTo(path_to_show[0].first, path_to_show[0].second);

	ui.textBrowser->setText(QString::number(path_to_show.size()) + QString::number(temp_path.size()));
	for (int i = 1; i < path_to_show.size(); ++i)
	{
		mypath->lineTo(path_to_show[i].first, path_to_show[i].second);
	}
	scene->addPath(*mypath);
}

void Data_Structure_project4::on_Walking_Navigation_clicked()
{

}

void Data_Structure_project4::on_Quit_clicked()
{

}

void Data_Structure_project4::on_Parking_lot_clicked()
{

}

void Data_Structure_project4::on_Restaurant_clicked()
{

}

void Data_Structure_project4::on_Smarket_clicked()
{

}

void Data_Structure_project4::on_WC_clicked()
{

}

void Data_Structure_project4::on_Test_Function_clicked()
{

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
