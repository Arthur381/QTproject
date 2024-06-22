#include "intro.h"
#include "ui_intro.h"

#include <qpainter.h>
#include <qstyleoption.h>

Intro::Intro(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Intro)
{
    ui->setupUi(this);
    setWindowTitle(QStringLiteral("介绍一下PKU自律指南吧~"));
    CURRENT_PAGE=0;
    Draw(CURRENT_PAGE);
    setWindowIcon(QIcon(":/icon/changetheme.png"));
}

void Intro::paintEvent(QPaintEvent *e)
{
    QStyleOptionFrame opt;
    opt.initFrom(this);  // 初始化 QStyleOptionFrame
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

Intro::~Intro()
{
    delete ui;
}

void Intro::Draw(int current_page){
    if(current_page==0){
        this->setStyleSheet(
            "QWidget#Intro{"
            "    background-image: url(:/icon/0(1).jpg);" // 设置背景图片
            "    background-position: center;" // 将图片放置在中心
            "    background-repeat: no-repeat;" // 禁止图片重复
            "    background-size: 100% 100%;" // 使图片拉伸以适应窗口大小
            "}"
            "QPushButton {"
            "    background-color: rgba(239, 135, 135, 0.717);"
            "    border: 0px solid rgba(115, 177, 166, 0.865);"//设置边框
            "    color:rgb(5, 12, 12);"// 设置按钮文本的颜色为黑色（RGB值为5, 12, 12）
            "    border-radius: 24;"// 设置按钮的边框半径为6像素，使其圆角化
            "    font: 10pt '幼圆';"// 设置按钮文本的字体为 10 点大小的楷体
            "}"

            );
    }
    else if(current_page==1){
        this->setStyleSheet(
            "QWidget#Intro{"
            "    background-image: url(:/icon/1(1).jpg);" // 设置背景图片
            "    background-position: center;" // 将图片放置在中心
            "    background-repeat: no-repeat;" // 禁止图片重复
            "    background-size: 100% 100%;" // 使图片拉伸以适应窗口大小
            "}"
            "QPushButton {"
            "    background-color: rgba(239, 135, 135, 0.717);"
            "    border: 0px solid rgba(115, 177, 166, 0.865);"//设置边框
            "    color:rgb(5, 12, 12);"// 设置按钮文本的颜色为黑色（RGB值为5, 12, 12）
            "    border-radius: 24;"// 设置按钮的边框半径为6像素，使其圆角化
            "    font: 10pt '幼圆';"// 设置按钮文本的字体为 10 点大小的楷体
            "}"

            );
    }
    else if(current_page==2){
        this->setStyleSheet(
            "QWidget#Intro{"
            "    background-image: url(:/icon/2(1).jpg);" // 设置背景图片
            "    background-position: center;" // 将图片放置在中心
            "    background-repeat: no-repeat;" // 禁止图片重复
            "    background-size: 100% 100%;" // 使图片拉伸以适应窗口大小
            "}"

            "QPushButton {"
            "    background-color: rgba(239, 135, 135, 0.717);"
            "    border: 0px solid rgba(115, 177, 166, 0.865);"//设置边框
            "    color:rgb(5, 12, 12);"// 设置按钮文本的颜色为黑色（RGB值为5, 12, 12）
            "    border-radius: 24;"// 设置按钮的边框半径为6像素，使其圆角化
            "    font: 10pt '幼圆';"// 设置按钮文本的字体为 10 点大小的楷体
            "}"
            );
    }
    else if(current_page==3){
        this->setStyleSheet(
            "QWidget#Intro{"
            "    background-image: url(:/icon/3(1).jpg);" // 设置背景图片
            "    background-position: center;" // 将图片放置在中心
            "    background-repeat: no-repeat;" // 禁止图片重复
            "    background-size: 100% 100%;" // 使图片拉伸以适应窗口大小
            "}"
            "QPushButton {"
            "    background-color: rgba(239, 135, 135, 0.717);"
            "    border: 0px solid rgba(115, 177, 166, 0.865);"//设置边框
            "    color:rgb(5, 12, 12);"// 设置按钮文本的颜色为黑色（RGB值为5, 12, 12）
            "    border-radius: 24;"// 设置按钮的边框半径为6像素，使其圆角化
            "    font: 10pt '幼圆';"// 设置按钮文本的字体为 10 点大小的楷体
            "}"
            );
    }
}

void Intro::on_pushButton_clicked()
{
    CURRENT_PAGE=(CURRENT_PAGE+1)%4;
    Draw(CURRENT_PAGE);

}


