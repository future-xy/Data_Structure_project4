#pragma once

#ifndef DATA_STRUCTURE_PROJECT4_H
#define DATA_STRUCTURE_PROJECT4_H

#include <QtWidgets/QMainWindow>
#include <qgraphicsview.h>
#include <qgraphicsscene.h>
#include <qlabel.h>
#include <qimage.h>
#include <qfiledialog.h>

#include "ui_Data_Structure_project4.h"
#include "Map.h"

class Data_Structure_project4 : public QMainWindow
{
	Q_OBJECT

public:
	Data_Structure_project4(QWidget *parent = Q_NULLPTR);
	~Data_Structure_project4();

private:
	Ui::Data_Structure_project4Class ui;
	QImage *image;
	Map *_map;

private slots:
	void on_Navigation_clicked();
	void on_Quit_clicked();
	
	void on_Parking_lot_clicked();
	void on_Smarket_clicked();
	void on_Restaurant_clicked();
	void on_WC_clicked();

	void on_Test_Function_clicked();
	void on_Translate_clicked();
};

#endif // !DATA_STRUCTURE_PROJECT4_H
