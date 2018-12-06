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

enum Status { Empty, Navigation };

class Data_Structure_project4 : public QMainWindow
{
	Q_OBJECT

public:
	Data_Structure_project4(QWidget *parent = Q_NULLPTR);
	~Data_Structure_project4();

private:
	Ui::Data_Structure_project4Class ui;
	QGraphicsScene *scene;
	QImage *image;
	Map *_map;
	std::vector<QGraphicsLineItem *> mypath;
	QPixmap the_parking_lot, the_WC, the_restaurant, the_smarket;
	std::vector<QGraphicsPixmapItem* > points;
	std::vector<QGraphicsEllipseItem*> places;
	std::vector<Coordinate> path_to_show;
	std::vector<QPointF> path_to_save;
	Status theStatus;

private slots:
//	void on_mouseMovePoint(QPoint point);
	void on_mouseClicked(QPoint point);

	void on_Start_clicked();
	void on_Driving_Navigation_clicked();
	void on_Walking_Navigation_clicked();
	void on_Quit_clicked();

	void on_recommended_clicked();
	void on_recommended2_clicked();
	void on_recommended3_clicked();
	
	void on_Parking_lot_clicked();
	void on_Smarket_clicked();
	void on_Restaurant_clicked();
	void on_WC_clicked();

	void on_Test_Function_clicked();
	void on_Translate_clicked();
};

#endif // !DATA_STRUCTURE_PROJECT4_H
