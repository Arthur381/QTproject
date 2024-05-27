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

    //connect(ui->pushButton, &HoverButton::changeSize, this, &ChooseTheme::animateSize);
    ui->pushButton->setStyleSheet(
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
}

ChooseTheme::~ChooseTheme()
{
    delete ui;
}



