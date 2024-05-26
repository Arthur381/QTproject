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
    ui->calBT->setStyleSheet(
        "QPushButton {"
        "    background-color: lightgray;"
        "    border: 2px solid rgba(115, 177, 166, 0.865);"//设置边框
        "    color:rgb(5, 12, 12);"// 设置按钮文本的颜色为黑色（RGB值为5, 12, 12）
        "    border-radius: 6;"// 设置按钮的边框半径为6像素，使其圆角化
        "    font: 10pt '楷体';"// 设置按钮文本的字体为 10 点大小的楷体
        "}"
        "QPushButton:hover {"
        "    background-color: lightyellow;"
        "    font: 18pt '楷体';"// 设置按钮文本的字体为 10 点大小的楷体
        "    transition: all 0.1s ease;"
        "}"
        );
    ui->style->setStyleSheet(        "QPushButton {"
        "    background-color: lightgray;"

        "    border: 2px solid rgba(115, 177, 166, 0.865);"//设置边框
        "    color:rgb(5, 12, 12);"// 设置按钮文本的颜色为黑色（RGB值为5, 12, 12）
        "    border-radius: 6;"// 设置按钮的边框半径为6像素，使其圆角化
        "    font: 10pt '楷体';"// 设置按钮文本的字体为 10 点大小的楷体
        "}"
        "QPushButton:hover {"
        "    background-color: lightyellow;"
        "    font: 18pt '楷体';"// 设置按钮文本的字体为 10 点大小的楷体
        "    transition: all 0.1s ease;"
        "}"
        );

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
 //   coursemsy *Acoursemsy=new coursemsy;
   // Acoursemsy->show();
    coursemsy::getinstance()->show();
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

