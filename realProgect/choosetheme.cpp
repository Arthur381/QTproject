#include "choosetheme.h"
#include "ui_choosetheme.h"
#include <QFile>
#include"hoverbutton.h"
#include<iostream>

ChooseTheme::ChooseTheme(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChooseTheme)
{
    ui->setupUi(this);

    QPixmap pix1(":image\\16.png");
    QPixmap pix2(":image\\17.png");
    QPixmap pix3(":image\\18.png");
    QPixmap pix4(":image\\19.png");
    ////////!!!!!!!
    pix1 = pix1.scaled(ui->laPKU->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    pix2 = pix2.scaled(ui->laHP->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    pix3 = pix3.scaled(ui->laHPDOG->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    pix4 = pix4.scaled(ui->laQIDAI->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->laPKU->setPixmap(pix1);
    ui->laHP->setPixmap(pix2);
    ui->laHPDOG->setPixmap(pix3);
    ui->laQIDAI->setPixmap(pix4);
    ui->laPKU->show();
    ui->laHP->show();
    ui->laHPDOG->show();
    ui->laQIDAI->show();


    setWindowTitle(QStringLiteral("选择一个你喜欢的主题吧~"));
    setWindowIcon(QIcon(":/icon/changetheme.png"));
    ui->themeHP->setStyleSheet(
        "QPushButton {"
        "    background-color: rgba(166, 215, 255, 0.865);"
        "    border: 0px solid rgba(115, 177, 166, 0.865);"//设置边框
        "    color:rgb(5, 12, 12);"// 设置按钮文本的颜色为黑色（RGB值为5, 12, 12）
        "    border-radius: 24;"// 设置按钮的边框半径为6像素，使其圆角化
        "    font: 14pt '华文新魏';"// 设置按钮文本的字体为 10 点大小的楷体
        "}"
        "QPushButton:hover {"
        "    background-color: rgba(255, 250, 198, 0.865);"
        "    font: 18pt '华文新魏';"// 设置按钮文本的字体为 10 点大小的楷体
        "    transition: all 0.1s ease;"
        "}"
        );
    ui->PKU->setStyleSheet(
        "QPushButton {"
        "    background-color: rgba(166, 215, 255, 0.865);"
        "    border: 0px solid rgba(115, 177, 166, 0.865);"//设置边框
        "    color:rgb(5, 12, 12);"// 设置按钮文本的颜色为黑色（RGB值为5, 12, 12）
        "    border-radius: 24;"// 设置按钮的边框半径为6像素，使其圆角化
        "    font: 14pt '华文新魏';"// 设置按钮文本的字体为 10 点大小的楷体
        "}"
        "QPushButton:hover {"
        "    background-color:rgba(255, 250, 198, 0.865);"
        "    font: 18pt '华文新魏';"// 设置按钮文本的字体为 10 点大小的楷体
        "    transition: all 0.1s ease;"
        "}"
        );
    ui->HappyDog->setStyleSheet(
        "QPushButton {"
        "    background-color: rgba(166, 215, 255, 0.865);"
        "    border: 0px solid rgba(115, 177, 166, 0.865);"//设置边框
        "    color:rgb(5, 12, 12);"// 设置按钮文本的颜色为黑色（RGB值为5, 12, 12）
        "    border-radius: 24;"// 设置按钮的边框半径为6像素，使其圆角化
        "    font: 14pt '华文新魏';"// 设置按钮文本的字体为 10 点大小的楷体
        "}"
        "QPushButton:hover {"
        "    background-color: rgba(255, 250, 198, 0.865);"
        "    font: 18pt '华文新魏';"// 设置按钮文本的字体为 10 点大小的楷体
        "    transition: all 0.1s ease;"
        "}"
        );
    connect(ui->themeHP, &QPushButton::clicked, this, &ChooseTheme::changebegin);
}

ChooseTheme::~ChooseTheme()
{
    delete ui;
}




void ChooseTheme::changebegin()
{
    ThemeStyle=1;
    emit themeChanged();

}


void ChooseTheme::on_PKU_clicked()
{
    ThemeStyle=0;
    emit themeChanged();
}

