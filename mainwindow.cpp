#include "mainwindow.h"
#include <QWidget>
#include "boardgenerator.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setCentralWidget(tuyn_anun);
    tuyn_anun->setLayout(tuyn_layout);
    tuyn_layout->addWidget(tuyn_label);
    tuyn_layout->addWidget(tuyn_button);
    tuyn_layout->addWidget(tuyn_grid);
    tuyn_label->setText("Sudoku!");
    tuyn_button->setText("Check");
    tuyn_label->setAlignment(Qt::AlignCenter);
    tuyn_grid->setModel(m_tableItemsModel);
    boardGenerator bordGenerator;

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            m_gridForGame[i][j] = bordGenerator.getBoardForGame(i,j);
        }
    }
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            m_tableItems[9*i+j].setText("");
            m_tableItems[9*i+j].setFlags(Qt::ItemIsEditable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        }
    }
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            m_grid[i][j] = bordGenerator.getBoard(i,j);
        }
    }
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            m_tableItems[9*i+j].setTextAlignment(Qt::AlignCenter);
            m_tableItemsModel->setItem(i,j,&m_tableItems[9*i+j]);

            if(m_gridForGame[i][j] != 0){
                m_tableItems[9*i+j].setForeground(Qt::black);

                m_tableItems[9*i+j].setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                m_tableItems[9*i+j].setText(QString::number(m_gridForGame[i][j]));
            }else{
                m_tableItems[9*i+j].setForeground(Qt::blue);
            }
        }
    }
    connect(tuyn_button, SIGNAL (clicked()), this, SLOT (checkSlot()));

}

void MainWindow::checkSlot() {
    for (int i = 0; i < 9; ++i) {

        for (int j = 0; j < 9; ++j) {
            if (m_grid[i][j] == m_gridForGame[i][j]) {
                m_tableItems[9 * i + j].setFlags(Qt::ItemIsEditable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);

            } else {

            }
        }
    }

}
MainWindow::~MainWindow()
{


}
