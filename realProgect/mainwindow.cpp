#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include"dailymsy.h"
#include"coursemsy.h"
#include"calendarmc.h"
#include "intro.h"
#include <QMainWindow>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QWidget>
#include<QKeyEvent>
#include<QFile>
#include<QCoreApplication>
#include <QPainter>
#include <QStyleOption>
#include "choosetheme.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->calBT->setText("日历");

}

MainWindow::~MainWindow()
{
    delete ui;
}


/**
 * @brief MainWindow::keyPressEvent//通过键盘刷新，方便检测颜色变化
 * @param event
 *
 */
/*void MainWindow::setAW()
{

    QFile f;
    auto str=QCoreApplication::applicationDirPath();
    f.setFileName(str+"//"+"MWBqss.css");
    //qDebug()<<str+"//"+"MWBqss.css";
    f.open(QIODevice::ReadOnly);
    QString str1=f.readAll();
    this->setStyleSheet(str1);
}*/







void MainWindow::on_calBT_clicked()
{
    this->cal->show();
    cal->ColorDays();


}


void MainWindow::on_clockBT_clicked()
{
    clockHZJ *AclockWindow=new clockHZJ;
    AclockWindow->show();
}


void MainWindow::on_pushButton_clicked()
{
    dailyMSY::getinstance()->show();
}


void MainWindow::on_TTBT_clicked()//课程表
{
    coursemsy *Acoursemsy=new coursemsy;
    Acoursemsy->show();
}


void MainWindow::on_readme_clicked()
{
    Intro *intro=new Intro;
    intro->show();
}


void MainWindow::on_style_clicked()
{
    ChooseTheme * ChoT=new ChooseTheme;
    ChoT->show();
}

