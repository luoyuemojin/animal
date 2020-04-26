/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "chakanform.h"
#include "chuankouform.h"
#include "jiezhongform.h"
#include "jishuform.h"
#include "weightform.h"
#include "yimiaoform.h"
#include "zhuceform.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_0;
    QAction *action_1;
    QAction *action_2;
    QAction *action_3;
    QAction *action_4;
    QAction *action_5;
    QAction *action_6;
    QWidget *centralWidget;
    chuankouForm *widget;
    zhuceForm *widget_2;
    chakanForm *widget_3;
    JieZhongForm *widget_4;
    YiMiaoForm *widget_5;
    JishuForm *widget_6;
    WeightForm *widget_7;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_caozuo;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1000, 800);
        action_0 = new QAction(MainWindow);
        action_0->setObjectName(QStringLiteral("action_0"));
        QFont font;
        font.setPointSize(12);
        action_0->setFont(font);
        action_1 = new QAction(MainWindow);
        action_1->setObjectName(QStringLiteral("action_1"));
        action_1->setFont(font);
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QStringLiteral("action_2"));
        action_2->setFont(font);
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QStringLiteral("action_3"));
        action_3->setFont(font);
        action_4 = new QAction(MainWindow);
        action_4->setObjectName(QStringLiteral("action_4"));
        action_4->setFont(font);
        action_5 = new QAction(MainWindow);
        action_5->setObjectName(QStringLiteral("action_5"));
        action_5->setFont(font);
        action_6 = new QAction(MainWindow);
        action_6->setObjectName(QStringLiteral("action_6"));
        action_6->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new chuankouForm(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 1000, 800));
        widget_2 = new zhuceForm(centralWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(0, 0, 1000, 800));
        widget_3 = new chakanForm(centralWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(0, 0, 1000, 800));
        widget_4 = new JieZhongForm(centralWidget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(0, 0, 1000, 800));
        widget_5 = new YiMiaoForm(centralWidget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setGeometry(QRect(0, 0, 1000, 800));
        widget_6 = new JishuForm(centralWidget);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setGeometry(QRect(0, 0, 1000, 800));
        widget_7 = new WeightForm(centralWidget);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        widget_7->setGeometry(QRect(0, 0, 1000, 800));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 45));
        menuBar->setMaximumSize(QSize(1677215, 100));
        QFont font1;
        font1.setPointSize(15);
        menuBar->setFont(font1);
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu->setGeometry(QRect(339, 129, 167, 105));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        menu_caozuo = new QMenu(menuBar);
        menu_caozuo->setObjectName(QStringLiteral("menu_caozuo"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_caozuo->menuAction());
        menu->addAction(action_0);
        menu_2->addAction(action_1);
        menu_2->addAction(action_2);
        menu_3->addAction(action_3);
        menu_3->addAction(action_4);
        menu_caozuo->addAction(action_5);
        menu_caozuo->addAction(action_6);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        action_0->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243\346\223\215\344\275\234", 0));
        action_1->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\345\212\250\347\211\251", 0));
        action_2->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213\345\212\250\347\211\251\344\277\241\346\201\257", 0));
        action_3->setText(QApplication::translate("MainWindow", "\346\216\245\347\247\215\346\223\215\344\275\234", 0));
        action_4->setText(QApplication::translate("MainWindow", "\347\226\253\350\213\227\346\223\215\344\275\234", 0));
        action_5->setText(QApplication::translate("MainWindow", "\345\207\272\345\205\245\350\256\241\346\225\260", 0));
        action_6->setText(QApplication::translate("MainWindow", "\347\247\260\351\207\215", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\344\270\262\345\217\243\346\223\215\344\275\234", 0));
        menu_2->setTitle(QApplication::translate("MainWindow", "\345\212\250\347\211\251\346\223\215\344\275\234", 0));
        menu_3->setTitle(QApplication::translate("MainWindow", "\347\226\253\350\213\227\346\223\215\344\275\234", 0));
        menu_caozuo->setTitle(QApplication::translate("MainWindow", "\346\227\245\345\270\270\346\223\215\344\275\234", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
