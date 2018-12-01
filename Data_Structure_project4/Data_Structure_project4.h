#pragma once

#ifndef DATA_STRUCTURE_PROJECT4_H
#define DATA_STRUCTURE_PROJECT4_H

#include <QtWidgets/QMainWindow>
#include "ui_Data_Structure_project4.h"

class Data_Structure_project4 : public QMainWindow
{
	Q_OBJECT

public:
	Data_Structure_project4(QWidget *parent = Q_NULLPTR);

private:
	Ui::Data_Structure_project4Class ui;
};

#endif // !DATA_STRUCTURE_PROJECT4_H
