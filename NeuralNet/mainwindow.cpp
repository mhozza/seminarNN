#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createNN()
{

}

void MainWindow::loadW()
{

}

void MainWindow::saveW()
{

}

void MainWindow::loadTrainData()
{

}

void MainWindow::loadTestData()
{

}

void MainWindow::runTraining()
{

}

void MainWindow::runTesting()
{

}
