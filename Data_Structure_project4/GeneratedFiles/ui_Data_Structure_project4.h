/********************************************************************************
** Form generated from reading UI file 'Data_Structure_project4.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATA_STRUCTURE_PROJECT4_H
#define UI_DATA_STRUCTURE_PROJECT4_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Data_Structure_project4Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Data_Structure_project4Class)
    {
        if (Data_Structure_project4Class->objectName().isEmpty())
            Data_Structure_project4Class->setObjectName(QStringLiteral("Data_Structure_project4Class"));
        Data_Structure_project4Class->resize(600, 400);
        menuBar = new QMenuBar(Data_Structure_project4Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        Data_Structure_project4Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Data_Structure_project4Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Data_Structure_project4Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(Data_Structure_project4Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Data_Structure_project4Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Data_Structure_project4Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Data_Structure_project4Class->setStatusBar(statusBar);

        retranslateUi(Data_Structure_project4Class);

        QMetaObject::connectSlotsByName(Data_Structure_project4Class);
    } // setupUi

    void retranslateUi(QMainWindow *Data_Structure_project4Class)
    {
        Data_Structure_project4Class->setWindowTitle(QApplication::translate("Data_Structure_project4Class", "Data_Structure_project4", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Data_Structure_project4Class: public Ui_Data_Structure_project4Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATA_STRUCTURE_PROJECT4_H
