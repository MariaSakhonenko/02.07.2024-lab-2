/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad;
    QAction *actionExit;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QListWidget *listWidget;
    QHBoxLayout *arraySizeLayout;
    QLabel *labelArraySize;
    QLineEdit *lineEditArraySize;
    QPushButton *buttonApplyArraySize;
    QHBoxLayout *horizontalLayout;
    QPushButton *addButton;
    QPushButton *removeButton;
    QPushButton *loadButton;
    QPushButton *sortButton;
    QHBoxLayout *listWidgetLayout;
    QPushButton *addListItemButton;
    QPushButton *removeListItemButton;
    QPushButton *loadListButton;
    QPushButton *loadImagesButton;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName("actionLoad");
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName("tableWidget");

        verticalLayout->addWidget(tableWidget);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");

        verticalLayout->addWidget(listWidget);

        arraySizeLayout = new QHBoxLayout();
        arraySizeLayout->setObjectName("arraySizeLayout");
        labelArraySize = new QLabel(centralwidget);
        labelArraySize->setObjectName("labelArraySize");

        arraySizeLayout->addWidget(labelArraySize);

        lineEditArraySize = new QLineEdit(centralwidget);
        lineEditArraySize->setObjectName("lineEditArraySize");

        arraySizeLayout->addWidget(lineEditArraySize);

        buttonApplyArraySize = new QPushButton(centralwidget);
        buttonApplyArraySize->setObjectName("buttonApplyArraySize");

        arraySizeLayout->addWidget(buttonApplyArraySize);


        verticalLayout->addLayout(arraySizeLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");

        horizontalLayout->addWidget(addButton);

        removeButton = new QPushButton(centralwidget);
        removeButton->setObjectName("removeButton");

        horizontalLayout->addWidget(removeButton);

        loadButton = new QPushButton(centralwidget);
        loadButton->setObjectName("loadButton");

        horizontalLayout->addWidget(loadButton);

        sortButton = new QPushButton(centralwidget);
        sortButton->setObjectName("sortButton");

        horizontalLayout->addWidget(sortButton);


        verticalLayout->addLayout(horizontalLayout);

        listWidgetLayout = new QHBoxLayout();
        listWidgetLayout->setObjectName("listWidgetLayout");
        addListItemButton = new QPushButton(centralwidget);
        addListItemButton->setObjectName("addListItemButton");

        listWidgetLayout->addWidget(addListItemButton);

        removeListItemButton = new QPushButton(centralwidget);
        removeListItemButton->setObjectName("removeListItemButton");

        listWidgetLayout->addWidget(removeListItemButton);

        loadListButton = new QPushButton(centralwidget);
        loadListButton->setObjectName("loadListButton");

        listWidgetLayout->addWidget(loadListButton);

        loadImagesButton = new QPushButton(centralwidget);
        loadImagesButton->setObjectName("loadImagesButton");

        listWidgetLayout->addWidget(loadImagesButton);


        verticalLayout->addLayout(listWidgetLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionLoad);
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionLoad->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        labelArraySize->setText(QCoreApplication::translate("MainWindow", "Array Size:", nullptr));
        buttonApplyArraySize->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        removeButton->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        loadButton->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        sortButton->setText(QCoreApplication::translate("MainWindow", "Sort", nullptr));
        addListItemButton->setText(QCoreApplication::translate("MainWindow", "Add to List", nullptr));
        removeListItemButton->setText(QCoreApplication::translate("MainWindow", "Remove from List", nullptr));
        loadListButton->setText(QCoreApplication::translate("MainWindow", "Load List", nullptr));
        loadImagesButton->setText(QCoreApplication::translate("MainWindow", "Load Images", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
