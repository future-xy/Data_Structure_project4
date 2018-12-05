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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "mygraphicsview.h"

QT_BEGIN_NAMESPACE

class Ui_Data_Structure_project4Class
{
public:
    QWidget *centralWidget;
    MyGraphicsView *Background;
    QPushButton *Translate;
    QPushButton *Test_Function;
    QPushButton *Quit;
    QTextBrowser *textBrowser;
    QPushButton *Start;
    QPushButton *Driving_Navigation;
    QPushButton *Walking_Navigation;
    QPushButton *Parking_lot;
    QPushButton *Restaurant;
    QPushButton *Smarket;
    QPushButton *WC;
    QPushButton *recommended3;
    QPushButton *recommended;
    QPushButton *recommend2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Data_Structure_project4Class)
    {
        if (Data_Structure_project4Class->objectName().isEmpty())
            Data_Structure_project4Class->setObjectName(QStringLiteral("Data_Structure_project4Class"));
        Data_Structure_project4Class->resize(1280, 720);
        Data_Structure_project4Class->setStyleSheet(QLatin1String("QTextBrowser { backfround-color: rgb(255,132,139,0);\n"
"border-radius: 3px; color: rgb(0,0,0);}"));
        centralWidget = new QWidget(Data_Structure_project4Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Background = new MyGraphicsView(centralWidget);
        Background->setObjectName(QStringLiteral("Background"));
        Background->setGeometry(QRect(0, 0, 1280, 720));
        Translate = new QPushButton(centralWidget);
        Translate->setObjectName(QStringLiteral("Translate"));
        Translate->setGeometry(QRect(20, 540, 119, 34));
        Test_Function = new QPushButton(centralWidget);
        Test_Function->setObjectName(QStringLiteral("Test_Function"));
        Test_Function->setGeometry(QRect(20, 450, 119, 34));
        Quit = new QPushButton(centralWidget);
        Quit->setObjectName(QStringLiteral("Quit"));
        Quit->setGeometry(QRect(20, 490, 119, 34));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(740, 30, 256, 192));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei"));
        font.setPointSize(15);
        textBrowser->setFont(font);
        textBrowser->setStyleSheet(QStringLiteral("background-color: rgba(237, 245, 255, 150);"));
        textBrowser->setFrameShadow(QFrame::Raised);
        textBrowser->setLineWidth(0);
        Start = new QPushButton(centralWidget);
        Start->setObjectName(QStringLiteral("Start"));
        Start->setGeometry(QRect(22, 22, 112, 30));
        Driving_Navigation = new QPushButton(centralWidget);
        Driving_Navigation->setObjectName(QStringLiteral("Driving_Navigation"));
        Driving_Navigation->setGeometry(QRect(22, 59, 57, 34));
        Walking_Navigation = new QPushButton(centralWidget);
        Walking_Navigation->setObjectName(QStringLiteral("Walking_Navigation"));
        Walking_Navigation->setGeometry(QRect(77, 59, 57, 34));
        Parking_lot = new QPushButton(centralWidget);
        Parking_lot->setObjectName(QStringLiteral("Parking_lot"));
        Parking_lot->setGeometry(QRect(21, 271, 112, 29));
        Restaurant = new QPushButton(centralWidget);
        Restaurant->setObjectName(QStringLiteral("Restaurant"));
        Restaurant->setGeometry(QRect(21, 342, 112, 29));
        Smarket = new QPushButton(centralWidget);
        Smarket->setObjectName(QStringLiteral("Smarket"));
        Smarket->setGeometry(QRect(21, 307, 112, 28));
        WC = new QPushButton(centralWidget);
        WC->setObjectName(QStringLiteral("WC"));
        WC->setGeometry(QRect(21, 378, 112, 28));
        recommended3 = new QPushButton(centralWidget);
        recommended3->setObjectName(QStringLiteral("recommended3"));
        recommended3->setGeometry(QRect(21, 184, 112, 29));
        recommended = new QPushButton(centralWidget);
        recommended->setObjectName(QStringLiteral("recommended"));
        recommended->setGeometry(QRect(21, 111, 112, 29));
        recommend2 = new QPushButton(centralWidget);
        recommend2->setObjectName(QStringLiteral("recommend2"));
        recommend2->setGeometry(QRect(21, 147, 112, 30));
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
        Quit->setText(QApplication::translate("Data_Structure_project4Class", "\345\217\226\346\266\210", Q_NULLPTR));
        Start->setText(QApplication::translate("Data_Structure_project4Class", "\345\274\200\345\247\213\350\247\204\345\210\222", Q_NULLPTR));
        Driving_Navigation->setText(QApplication::translate("Data_Structure_project4Class", "\351\251\276\350\275\246", Q_NULLPTR));
        Walking_Navigation->setText(QApplication::translate("Data_Structure_project4Class", "\346\255\245\350\241\214", Q_NULLPTR));
        Parking_lot->setText(QApplication::translate("Data_Structure_project4Class", "\345\201\234\350\275\246\345\234\272", Q_NULLPTR));
        Restaurant->setText(QApplication::translate("Data_Structure_project4Class", "\351\244\220\345\216\205", Q_NULLPTR));
        Smarket->setText(QApplication::translate("Data_Structure_project4Class", "\350\266\205\345\270\202", Q_NULLPTR));
        WC->setText(QApplication::translate("Data_Structure_project4Class", "\345\215\253\347\224\237\351\227\264", Q_NULLPTR));
        recommended3->setText(QApplication::translate("Data_Structure_project4Class", "\346\216\250\350\215\220\350\267\257\347\272\2773", Q_NULLPTR));
        recommended->setText(QApplication::translate("Data_Structure_project4Class", "\346\216\250\350\215\220\350\267\257\347\272\2771", Q_NULLPTR));
        recommend2->setText(QApplication::translate("Data_Structure_project4Class", "\346\216\250\350\215\220\350\267\257\347\272\2772", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Data_Structure_project4Class: public Ui_Data_Structure_project4Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATA_STRUCTURE_PROJECT4_H
