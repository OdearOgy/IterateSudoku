#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTableView>
#include <QStandardItem>
#include <QStandardItemModel>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QWidget *tuyn_anun = new QWidget();
    QVBoxLayout *tuyn_layout = new QVBoxLayout();
    QLabel  *tuyn_label = new QLabel();
    QPushButton *tuyn_button = new QPushButton();
    QTableView  *tuyn_grid = new QTableView();
    int m_grid[9][9];
    int m_gridForGame[9][9];

    QStandardItem *m_tableItems = new QStandardItem[81];
    QStandardItemModel *m_tableItemsModel = new QStandardItemModel(9,9);


public slots:
    void checkSlot();

};




#endif // MAINWINDOW_H
