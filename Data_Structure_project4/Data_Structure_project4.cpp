#include "Data_Structure_project4.h"

#include <qtranslator.h>
#include <qsettings.h>

using std::make_pair;

extern QTranslator *trans;
extern QString readSetting();



Data_Structure_project4::Data_Structure_project4(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	this->image = new QImage();
	QString filename = "map.png";
	//_map = new Map;
	theStatus = Empty;

	if (image->load(filename))
	{
		scene = new QGraphicsScene;
		scene->addPixmap(QPixmap::fromImage(*image));
		ui.Background->setScene(scene);
		ui.Background->resize(1280, 720);
		ui.Background->show();
	}

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
	Coordinate cor = _map->match(make_pair(pointScene.x(), pointScene.y());
	if (cor.first != -1 && cor.second != -1)
	{
		if (theStatus != Empty)
		{
			path_to_save.push_back(pointScene);
		}
		else
		{
			QString info = QString::fromStdString(_map->Info(cor));
			ui.textBrowser->setText(info);
		}
	}
	/*int x = pointScene.x();
	int y = pointScene.y();
	if (arr_point.empty())
	{
		ui.textBrowser->setVisible(true);
		ui.textBrowser->setText(QString::asprintf("Scene : %.0f,%.0f", pointScene.x(), pointScene.y()));
	}
	arr_point.push_back(make_pair(x, y));
	QPointF pointScene = ui.Background->mapToScene(point); //转换到Scene坐标
	ui.textBrowser->setText(QString::asprintf("Scene ：%.0f,%.0f", pointScene.x(), pointScene.y()));
	ui.textBrowser->setVisible(true);
	*/
}

void Data_Structure_project4::on_Start_clicked()
{
	theStatus = 
}

void Data_Structure_project4::on_Driving_Navigation_clicked()
{

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
