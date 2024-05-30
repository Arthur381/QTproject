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


    //connect(ui->pushButton, &HoverButton::changeSize, this, &ChooseTheme::animateSize);
    ui->themeHP->setStyleSheet(
        "QPushButton {"
        "    background-color: lightgray;"
        "    border: none;"
        "    min-width:100px;"//设置最小宽度
        "    border: 2px solid rgba(115, 177, 166, 0.865);"//设置边框
        "    color:rgb(5, 12, 12);"// 设置按钮文本的颜色为黑色（RGB值为5, 12, 12）
        "    border-radius: 6;"// 设置按钮的边框半径为6像素，使其圆角化
        "    font: 10pt '楷体';"// 设置按钮文本的字体为 10 点大小的楷体
        "}"
        "QPushButton:hover {"
        "    background-color: lightyellow;"
        "    min-width:200px;"
        "    font: 18pt '楷体';"// 设置按钮文本的字体为 10 点大小的楷体
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

