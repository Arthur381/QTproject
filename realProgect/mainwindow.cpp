#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_calBT_clicked()
{
    this->cal->show();
}


void MainWindow::on_clockBT_clicked()
{
    clockHZJ *AclockWindow=new clockHZJ;
    AclockWindow->show();
}


void MainWindow::on_pushButton_clicked()
{
    dailyMSY *Aday=new dailyMSY;
    Aday->show();
}

