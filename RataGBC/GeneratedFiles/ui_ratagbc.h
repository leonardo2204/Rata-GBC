/********************************************************************************
** Form generated from reading UI file 'ratagbc.ui'
**
** Created: Fri 9. Mar 02:41:11 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RATAGBC_H
#define UI_RATAGBC_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include "telaGBC.h"

QT_BEGIN_NAMESPACE

class Ui_RataGBCClass
{
public:
    QAction *actionAbrir;
    QAction *actionSair;
    QAction *actionOpenFile;
    QWidget *centralWidget;
    QListWidget *listWidget;
    QListWidget *listWidget_2;
    QPushButton *runBtn;
    QPushButton *stopBtn;
    QPushButton *stepBtn;
    QLineEdit *lineEdit;
    telaGBC *telaGame;
    QMenuBar *menuBar;
    QMenu *menuArquivo;
    QMenu *menuSobre;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RataGBCClass)
    {
        if (RataGBCClass->objectName().isEmpty())
            RataGBCClass->setObjectName(QString::fromUtf8("RataGBCClass"));
        RataGBCClass->resize(584, 557);
        actionAbrir = new QAction(RataGBCClass);
        actionAbrir->setObjectName(QString::fromUtf8("actionAbrir"));
        actionSair = new QAction(RataGBCClass);
        actionSair->setObjectName(QString::fromUtf8("actionSair"));
        actionOpenFile = new QAction(RataGBCClass);
        actionOpenFile->setObjectName(QString::fromUtf8("actionOpenFile"));
        centralWidget = new QWidget(RataGBCClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 20, 331, 381));
        listWidget->setMaximumSize(QSize(331, 381));
        listWidget_2 = new QListWidget(centralWidget);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setGeometry(QRect(390, 210, 161, 192));
        runBtn = new QPushButton(centralWidget);
        runBtn->setObjectName(QString::fromUtf8("runBtn"));
        runBtn->setGeometry(QRect(390, 420, 75, 23));
        stopBtn = new QPushButton(centralWidget);
        stopBtn->setObjectName(QString::fromUtf8("stopBtn"));
        stopBtn->setGeometry(QRect(470, 420, 75, 23));
        stepBtn = new QPushButton(centralWidget);
        stepBtn->setObjectName(QString::fromUtf8("stepBtn"));
        stepBtn->setGeometry(QRect(390, 450, 75, 23));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(470, 450, 81, 20));
        telaGame = new telaGBC(centralWidget);
        telaGame->setObjectName(QString::fromUtf8("telaGame"));
        telaGame->setGeometry(QRect(390, 30, 160, 144));
        RataGBCClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(RataGBCClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 584, 21));
        menuArquivo = new QMenu(menuBar);
        menuArquivo->setObjectName(QString::fromUtf8("menuArquivo"));
        menuSobre = new QMenu(menuBar);
        menuSobre->setObjectName(QString::fromUtf8("menuSobre"));
        RataGBCClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(RataGBCClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        RataGBCClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(RataGBCClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        RataGBCClass->setStatusBar(statusBar);

        menuBar->addAction(menuArquivo->menuAction());
        menuBar->addAction(menuSobre->menuAction());
        menuArquivo->addAction(actionAbrir);
        menuArquivo->addAction(actionSair);

        retranslateUi(RataGBCClass);
        QObject::connect(actionSair, SIGNAL(triggered()), RataGBCClass, SLOT(close()));

        QMetaObject::connectSlotsByName(RataGBCClass);
    } // setupUi

    void retranslateUi(QMainWindow *RataGBCClass)
    {
        RataGBCClass->setWindowTitle(QApplication::translate("RataGBCClass", "RataGBC", 0, QApplication::UnicodeUTF8));
        actionAbrir->setText(QApplication::translate("RataGBCClass", "Abrir...", 0, QApplication::UnicodeUTF8));
        actionSair->setText(QApplication::translate("RataGBCClass", "Sair", 0, QApplication::UnicodeUTF8));
        actionOpenFile->setText(QApplication::translate("RataGBCClass", "openFile", 0, QApplication::UnicodeUTF8));
        runBtn->setText(QApplication::translate("RataGBCClass", "Run", 0, QApplication::UnicodeUTF8));
        stopBtn->setText(QApplication::translate("RataGBCClass", "Stop", 0, QApplication::UnicodeUTF8));
        stepBtn->setText(QApplication::translate("RataGBCClass", "Step", 0, QApplication::UnicodeUTF8));
        menuArquivo->setTitle(QApplication::translate("RataGBCClass", "Arquivo", 0, QApplication::UnicodeUTF8));
        menuSobre->setTitle(QApplication::translate("RataGBCClass", "Sobre", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RataGBCClass: public Ui_RataGBCClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RATAGBC_H
