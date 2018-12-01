#include "Data_Structure_project4.h"

#include <qtranslator.h>
#include <qsettings.h>

extern QTranslator *trans;
extern QString readSetting();


Data_Structure_project4::Data_Structure_project4(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	this->image = new QImage();
	QString filename = ".\\images\\map.png";
	_map = new Map;

	if (image->load(filename))
	{
		scene = new QGraphicsScene;
		scene->addPixmap(QPixmap::fromImage(*image));
		ui.Background->setScene(scene);
		ui.Background->resize(1280, 720);
		ui.Background->show();
	}

	//show place
}

Data_Structure_project4::~Data_Structure_project4()
{
	delete image;
	delete _map;
	delete scene;
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
