#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMenu>
#include <QDate>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tableWidget = ui->tableWidget;
    listWidget = ui->listWidget;

    tableWidget->setColumnCount(3);
    tableWidget->setHorizontalHeaderLabels({"Race number", "Duration", "Date"});

    listWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(listWidget, &QListWidget::customContextMenuRequested, this, &MainWindow::showContextMenu);

    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::on_addButton_clicked);
    connect(ui->removeButton, &QPushButton::clicked, this, &MainWindow::on_removeButton_clicked);
    connect(ui->loadButton, &QPushButton::clicked, this, &MainWindow::on_loadButton_clicked);
    connect(ui->sortButton, &QPushButton::clicked, this, &MainWindow::on_sortButton_clicked);
    connect(ui->actionLoad, &QAction::triggered, this, &MainWindow::on_actionLoad_triggered);
    connect(ui->actionExit, &QAction::triggered, this, &MainWindow::on_actionExit_triggered);
    connect(ui->buttonApplyArraySize, &QPushButton::clicked, this, &MainWindow::on_buttonApplyArraySize_clicked);
    connect(ui->addListItemButton, &QPushButton::clicked, this, &MainWindow::on_addListItemButton_clicked);
    connect(ui->removeListItemButton, &QPushButton::clicked, this, &MainWindow::on_removeListItemButton_clicked);
    connect(ui->loadListButton, &QPushButton::clicked, this, &MainWindow::on_loadListButton_clicked);
    connect(ui->loadImagesButton, &QPushButton::clicked, this, &MainWindow::loadImagesFromFile);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Delete)
    {
        QList<QTableWidgetItem*> selectedItems = tableWidget->selectedItems();
        for (QTableWidgetItem *item : selectedItems)
        {
            tableWidget->removeRow(item->row());
        }
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton)
    {
        QMenu contextMenu(this);
        contextMenu.addAction("Add Row", this, SLOT(on_addButton_clicked()));
        contextMenu.addAction("Remove Row", this, SLOT(on_removeButton_clicked()));
        contextMenu.exec(event->globalPos());
    }
}

void MainWindow::showContextMenu(const QPoint &pos)
{
    QMenu contextMenu(this);
    contextMenu.addAction("Add Item", this, SLOT(on_addListItemButton_clicked()));
    contextMenu.addAction("Remove Item", this, SLOT(on_removeListItemButton_clicked()));
    contextMenu.exec(listWidget->mapToGlobal(pos));
}

void MainWindow::on_addButton_clicked()
{
    int rowCount = tableWidget->rowCount();
    tableWidget->insertRow(rowCount);
    tableWidget->setItem(rowCount, 0, new QTableWidgetItem(QString::number(rowCount + 1)));
    tableWidget->setItem(rowCount, 1, new QTableWidgetItem(QString::number((rowCount + 1) * 10)));
    tableWidget->setItem(rowCount, 2, new QTableWidgetItem(QDate::currentDate().toString()));
}

void MainWindow::on_removeButton_clicked()
{
    QList<QTableWidgetItem*> selectedItems = tableWidget->selectedItems();
    for (QTableWidgetItem *item : selectedItems)
    {
        tableWidget->removeRow(item->row());
    }
}

void MainWindow::on_loadButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Text Files (*.txt)"));
    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(&file);
            tableWidget->setRowCount(0); // clear existing rows
            while (!in.atEnd())
            {
                QString line = in.readLine();
                QStringList fields = line.split(",");
                int rowCount = tableWidget->rowCount();
                tableWidget->insertRow(rowCount);
                for (int i = 0; i < fields.size(); ++i)
                {
                    tableWidget->setItem(rowCount, i, new QTableWidgetItem(fields.at(i)));
                }
            }
            file.close();
        }
    }
}

void MainWindow::on_sortButton_clicked()
{
    int rowCount = tableWidget->rowCount();
    if (rowCount < 2) return;

    QList<QTableWidgetItem*> items;
    for (int row = 0; row < rowCount; ++row)
    {
        items.append(tableWidget->takeItem(row, 0));
    }

    quickSort(items, 0, items.size() - 1);

    for (int row = 0; row < rowCount; ++row)
    {
        tableWidget->setItem(row, 0, items[row]);
    }
}

void MainWindow::quickSort(QList<QTableWidgetItem*>& items, int left, int right)
{
    if (left >= right) return;
    int i = left, j = right;
    QTableWidgetItem* pivot = items[left];
    while (i <= j)
    {
        while (items[i]->text().toInt() < pivot->text().toInt()) i++;
        while (items[j]->text().toInt() > pivot->text().toInt()) j--;
        if (i <= j)
        {
            std::swap(items[i], items[j]);
            i++;
            j--;
        }
    }
    quickSort(items, left, j);
    quickSort(items, i, right);
}

void MainWindow::on_actionLoad_triggered()
{
    on_loadButton_clicked();
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_buttonApplyArraySize_clicked()
{
    bool ok;
    int size = ui->lineEditArraySize->text().toInt(&ok);
    if (ok && size > 0)
    {
        tableWidget->setRowCount(size);
        for (int i = 0; i < size; ++i)
        {
            tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(i + 1)));
            tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number((i + 1) * 10)));
            tableWidget->setItem(i, 2, new QTableWidgetItem(QDate::currentDate().toString()));
        }
    }
}

void MainWindow::on_addListItemButton_clicked()
{
    QListWidgetItem* item = new QListWidgetItem(QString::number(listWidget->count() + 1));
    listWidget->addItem(item);
}

void MainWindow::on_removeListItemButton_clicked()
{
    QList<QListWidgetItem*> selectedItems = listWidget->selectedItems();
    for (QListWidgetItem* item : selectedItems)
    {
        delete listWidget->takeItem(listWidget->row(item));
    }
}

void MainWindow::on_loadListButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Text Files (*.txt)"));
    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                QTextStream in(&file);
                listWidget->clear(); // clear existing items
                while (!in.atEnd())
                {
                    QString line = in.readLine();
                    listWidget->addItem(line);
                }
                file.close();
            }
    }
}

void MainWindow::loadImagesFromFile()
{
    QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Open Images"), "", tr("Images (*.png *.xpm *.jpg)"));
    for (const QString &fileName : fileNames)
    {
        QListWidgetItem *item = new QListWidgetItem(QIcon(fileName), fileName);
        listWidget->addItem(item);
    }
}
