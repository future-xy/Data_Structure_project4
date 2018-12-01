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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Data_Structure_project4Class
{
public:
    QWidget *centralWidget;
    QGraphicsView *Background;
    QPushButton *Translate;
    QPushButton *Test_Function;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *Parking_lot;
    QPushButton *Smarket;
    QPushButton *Restaurant;
    QPushButton *WC;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QPushButton *Navigation;
    QPushButton *Quit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Data_Structure_project4Class)
    {
        if (Data_Structure_project4Class->objectName().isEmpty())
            Data_Structure_project4Class->setObjectName(QStringLiteral("Data_Structure_project4Class"));
        Data_Structure_project4Class->resize(1280, 720);
        centralWidget = new QWidget(Data_Structure_project4Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Background = new QGraphicsView(centralWidget);
        Background->setObjectName(QStringLiteral("Background"));
        Background->setGeometry(QRect(0, 0, 1280, 720));
        Translate = new QPushButton(centralWidget);
        Translate->setObjectName(QStringLiteral("Translate"));
        Translate->setGeometry(QRect(20, 440, 112, 34));
        Test_Function = new QPushButton(centralWidget);
        Test_Function->setObjectName(QStringLiteral("Test_Function"));
        Test_Function->setGeometry(QRect(20, 360, 112, 34));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 140, 114, 165));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        Parking_lot = new QPushButton(layoutWidget);
        Parking_lot->setObjectName(QStringLiteral("Parking_lot"));

        verticalLayout_2->addWidget(Parking_lot);

        Smarket = new QPushButton(layoutWidget);
        Smarket->setObjectName(QStringLiteral("Smarket"));

        verticalLayout_2->addWidget(Smarket);

        Restaurant = new QPushButton(layoutWidget);
        Restaurant->setObjectName(QStringLiteral("Restaurant"));

        verticalLayout_2->addWidget(Restaurant);

        WC = new QPushButton(layoutWidget);
        WC->setObjectName(QStringLiteral("WC"));

        verticalLayout_2->addWidget(WC);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 20, 114, 79));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Navigation = new QPushButton(layoutWidget1);
        Navigation->setObjectName(QStringLiteral("Navigation"));

        verticalLayout->addWidget(Navigation);

        Quit = new QPushButton(layoutWidget1);
        Quit->setObjectName(QStringLiteral("Quit"));

        verticalLayout->addWidget(Quit);

        Data_Structure_project4Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Data_Structure_project4Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 30));
        Data_Structure_project4Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Data_Structure_project4Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Data_Structure_project4Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Data_Structure_project4Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Data_Structure_project4Class->setStatusBar(statusBar);

        retranslateUi(Data_Structure_project4Class);

        QMetaObject::connectSlotsByName(Data_Structure_project4Class);
    } // setupUi

    void retranslateUi(QMainWindow *Data_Structure_project4Class)
    {
        Data_Structure_project4Class->setWindowTitle(QApplication::translate("Data_Structure_project4Class", "Data_Structure_project4", Q_NULLPTR));
        Translate->setText(QApplication::translate("Data_Structure_project4Class", "English", Q_NULLPTR));
        Test_Function->setText(QApplication::translate("Data_Structure_project4Class", "\345\233\276\345\203\217\350\257\206\345\210\253", Q_NULLPTR));
        Parking_lot->setText(QApplication::translate("Data_Structure_project4Class", "\345\201\234\350\275\246\345\234\272", Q_NULLPTR));
        Smarket->setText(QApplication::translate("Data_Structure_project4Class", "\350\266\205\345\270\202", Q_NULLPTR));
        Restaurant->setText(QApplication::translate("Data_Structure_project4Class", "\351\244\220\345\216\205", Q_NULLPTR));
        WC->setText(QApplication::translate("Data_Structure_project4Class", "\345\215\253\347\224\237\351\227\264", Q_NULLPTR));
        Navigation->setText(QApplication::translate("Data_Structure_project4Class", "\345\274\200\345\247\213\345\257\274\350\210\252", Q_NULLPTR));
        Quit->setText(QApplication::translate("Data_Structure_project4Class", "\351\200\200\345\207\272\345\257\274\350\210\252", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Data_Structure_project4Class: public Ui_Data_Structure_project4Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATA_STRUCTURE_PROJECT4_H
