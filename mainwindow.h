#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QListWidget>
#include <QKeyEvent>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private slots:
    void on_addButton_clicked();
    void on_removeButton_clicked();
    void on_loadButton_clicked();
    void on_sortButton_clicked();
    void on_actionLoad_triggered();
    void on_actionExit_triggered();
    void on_buttonApplyArraySize_clicked();
    void showContextMenu(const QPoint &pos);
    void on_addListItemButton_clicked();
    void on_removeListItemButton_clicked();
    void on_loadListButton_clicked();
    void loadImagesFromFile();

private:
    Ui::MainWindow *ui;
    QTableWidget *tableWidget;
    QListWidget *listWidget;

    void quickSort(QList<QTableWidgetItem*>& items, int left, int right);
};

#endif // MAINWINDOW_H
