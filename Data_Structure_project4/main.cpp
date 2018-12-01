#include "Data_Structure_project4.h"

#include <QtWidgets/QApplication>
#include <qtranslator.h>
#include <qsettings.h>

QTranslator *trans = nullptr;

QString readSetting();

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	trans = new QTranslator;
	QString curLang = readSetting();
	if (curLang == "EN")
		trans->load("Data_Structure_project4_en.qm");
	else
		trans->load("Data_Structure_project4_zh.qm");
	a.installTranslator(trans);

	Data_Structure_project4 w;
	w.show();
	return a.exec();
}

QString readSetting()
{
	QString organization = "WWB-Qt";
	QString appName = "Data_Structure_project4";
	QSettings  settings(organization, appName);
	QString Language = settings.value("Language", "EN").toString();
	return  Language;
}