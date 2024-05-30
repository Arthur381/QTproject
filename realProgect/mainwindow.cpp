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
#include<QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->calBT->setText("日历");
    this->changetheme();
    connect(this,&MainWindow::themeChanged,this->cal,&calendarMC::changetheme);
}




MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_calBT_clicked()
{
    this->cal->show();
    cal->ColorDays();
}
void MainWindow::on_clockBT_clicked()//闹钟系列
{
    clockHZJ *AclockWindow=new clockHZJ;
    connect(this,&MainWindow::themeChanged,AclockWindow,&clockHZJ::changetheme);
    AclockWindow->show();
}
void MainWindow::on_pushButton_clicked()
{
    connect(this,&MainWindow::themeChanged,dailyMSY::getinstance(),&dailyMSY::changetheme);
    dailyMSY::getinstance()->show();
}
void MainWindow::on_TTBT_clicked()//课程表
{
    connect(this,&MainWindow::themeChanged,coursemsy::getinstance(),&coursemsy::changetheme);
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
    connect(ChoT, &ChooseTheme::themeChanged, this, &MainWindow::changetheme);
    ChoT->show();
}

void MainWindow::changetheme(){
    if(ThemeStyle==0){
        /**
 * @brief setstyle_on_zero_PKU
 *
 *
 */
        QPixmap pixmain(":image/1.png");
        pixmain = pixmain.scaled(ui->mainlabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        ui->mainlabel->setPixmap(pixmain); // 显示 QLabel
        ui->mainlabel->show();

        QPixmap pixmain3(":PKU/mini5.png");
        pixmain3 = pixmain3.scaled(ui->label3->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        ui->label3->setPixmap(pixmain3); // 显示 QLabel
        ui->label3->show();

        /**
         * 设置窗口背景
         *
         */

        this->setStyleSheet(
            "QMainWindow {"
            "    background-image: url(:/background/pku_mainbg.jpg);" // 设置背景图片
            "    background-position: center;" // 将图片放置在中心
            "    background-repeat: no-repeat;" // 禁止图片重复
            "    background-size: 100% 100%;" // 使图片拉伸以适应窗口大小
            "}"
            );
        ui->readme->setStyleSheet(
            "QPushButton {"
            "    background-color: rgba(247, 22, 60, 0.865);"
            "    border: 0px solid rgba(115, 177, 166, 0.865);"//设置边框
            "    color:rgb(5, 12, 12);"// 设置按钮文本的颜色为黑色（RGB值为5, 12, 12）
            "    border-radius: 24;"// 设置按钮的边框半径为6像素，使其圆角化
            "    font: 14pt '华文新魏';"// 设置按钮文本的字体为 10 点大小的楷体
            "}"
            "QPushButton:hover {"
            "    background-color: rgba(251, 205, 205, 0.84);"
            "    font: 18pt '华文新魏';"// 设置按钮文本的字体为 10 点大小的楷体
            "    transition: all 0.1s ease;"
            "}"
            );
        ui->TTBT->setStyleSheet(
            "QPushButton {"
            "    background-color: rgba(247, 22, 60, 0.865);"
            "    border: 0px solid rgba(115, 177, 166, 0.865);"//设置边框
            "    color:rgb(5, 12, 12);"// 设置按钮文本的颜色为黑色（RGB值为5, 12, 12）
            "    border-radius: 24;"// 设置按钮的边框半径为6像素，使其圆角化
            "    font: 14pt '华文新魏';"// 设置按钮文本的字体为 10 点大小的楷体
            "}"
            "QPushButton:hover {"
            "    background-color: rgba(251, 205, 205, 0.84);"
            "    font: 18pt '华文新魏';"// 设置按钮文本的字体为 10 点大小的楷体
            "    transition: all 0.1s ease;"
            "}"
            );
        ui->clockBT->setStyleSheet(
            "QPushButton {"
            "    background-color: rgba(247, 22, 60, 0.865);"
            "    border: 0px solid rgba(115, 177, 166, 0.865);"//设置边框
            "    color:rgb(5, 12, 12);"// 设置按钮文本的颜色为黑色（RGB值为5, 12, 12）
            "    border-radius: 24;"// 设置按钮的边框半径为6像素，使其圆角化
            "    font: 14pt '华文新魏';"// 设置按钮文本的字体为 10 点大小的楷体
            "}"
            "QPushButton:hover {"
            "    background-color: rgba(251, 205, 205, 0.84);"
            "    font: 18pt '华文新魏';"// 设置按钮文本的字体为 10 点大小的楷体
            "    transition: all 0.1s ease;"
            "}"
            );
        /**
     *
     *
     *配色的第二部分
     *
     *
     */
        //ui->calBT->setIcon(QIcon(":/PKU/mini2.png"));
        //ui->calBT->setIconSize(QSize(100, 100));
        //ui->calBT->setFixedSize(100, 50);
        ui->calBT->setStyleSheet(
            "QPushButton {"
            "    background-color: rgba(239, 135, 135, 0.717);"
            "    border: 0px solid rgba(115, 177, 166, 0.865);"//设置边框
            "    color:rgb(5, 12, 12);"// 设置按钮文本的颜色为黑色（RGB值为5, 12, 12）
            "    border-radius: 24;"// 设置按钮的边框半径为6像素，使其圆角化
            "    font: 14pt '华文新魏';"// 设置按钮文本的字体为 10 点大小的楷体
            "}"
            "QPushButton:hover {"
            "    background-color: rgba(244, 54, 54, 0.84);"
            "    font: 18pt '华文新魏';"// 设置按钮文本的字体为 10 点大小的楷体
            "    transition: all 0.1s ease;"
            "}"
            );
        ui->pushButton->setStyleSheet(
            "QPushButton {"
            "    background-color: rgba(239, 135, 135, 0.717);"
            "    border: 0px solid rgba(115, 177, 166, 0.865);"//设置边框
            "    color:rgb(5, 12, 12);"// 设置按钮文本的颜色为黑色（RGB值为5, 12, 12）
            "    border-radius: 24;"// 设置按钮的边框半径为6像素，使其圆角化
            "    font: 14pt '华文新魏';"// 设置按钮文本的字体为 10 点大小的楷体
            "}"
            "QPushButton:hover {"
            "    background-color: rgba(244, 54, 54, 0.84);"
            "    font: 18pt '华文新魏';"// 设置按钮文本的字体为 10 点大小的楷体
            "    transition: all 0.1s ease;"
            "}"
            );
        ui->style->setStyleSheet(
            "QPushButton {"
            "    background-color: rgba(239, 135, 135, 0.717);"
            "    border: 0px solid rgba(115, 177, 166, 0.865);"//设置边框
            "    color:rgb(5, 12, 12);"// 设置按钮文本的颜色为黑色（RGB值为5, 12, 12）
            "    border-radius: 24;"// 设置按钮的边框半径为6像素，使其圆角化
            "    font: 14pt '华文新魏';"// 设置按钮文本的字体为 10 点大小的楷体
            "}"
            "QPushButton:hover {"
            "    background-color: rgba(244, 54, 54, 0.84);"
            "    font: 18pt '华文新魏';"// 设置按钮文本的字体为 10 点大小的楷体
            "    transition: all 0.1s ease;"
            "}"
            );
    }
    else if(ThemeStyle==1){
        this->setStyleSheet(
            "QMainWindow {"
            "    background-image: url(:/background/current.jpg);" // 设置背景图片
            "    background-position: center;" // 将图片放置在中心
            "    background-repeat: no-repeat;" // 禁止图片重复
            "    background-size: 100% 100%;" // 使图片拉伸以适应窗口大小
            "}"
            );


    }
    else if(ThemeStyle==2){






    }
    /**
     * @主题更改完成之后发送信号
     *
     */
    emit themeChanged();
}
