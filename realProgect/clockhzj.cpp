#include "clockhzj.h"
#include "ui_clockhzj.h"
#include <QPainter>
#include <QStyleOption>
#include "sec_clock.h"
#include "alarm.h"
#include "r_clock.h"
#include"global.h"
#include<QDebug>
#include <QPainter>

clockHZJ::clockHZJ(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::clockHZJ)
{
    ui->setupUi(this);
    this->changetheme();

    setWindowTitle(QStringLiteral("时间管理"));

    QFont font1("YouYuan",25);
    ui->label->setFont(font1);

    /**
     * @brief connect
     *
     * !!!!!
     * 如果ui编辑界面的样式表已经设置但是注释了，还是会有冲突导致无法实现
     *
     */
    connect(&timer_cur, SIGNAL(timeout()), this, SLOT(showcurtime()));
    timer_cur.start(1000);
    ui->curtime->setText("0000-00-00 00:00:00");
}



clockHZJ::~clockHZJ()
{
    delete ui;
}

void clockHZJ::showcurtime(){
    curDTime = QDateTime::currentDateTime();
    ui->curtime->setText(curDTime.toString("yyyy-MM-dd HH:mm:ss"));
}

void clockHZJ::on_sec_clock_clicked()
{
    sec_clock *sec=new sec_clock;
    connect(this, &clockHZJ::themeChanged, sec, &sec_clock::changetheme);
    sec->show();
}


void clockHZJ::on_rsec_clo_clicked()
{
    r_clock *rck=new r_clock;
    connect(this, &clockHZJ::themeChanged, rck, &r_clock::changetheme);
    rck->show();
}


void clockHZJ::on_alarms_clicked()
{
    alarm *ala=new alarm;
    connect(this, &clockHZJ::themeChanged, ala, &alarm::changetheme);
    ala->show();
}
/**
 * @brief clockHZJ::paintEvent
 * @param QWIdget 专有
 */
void clockHZJ::paintEvent(QPaintEvent *e)
{
    QStyleOptionFrame opt;
    opt.initFrom(this);  // 初始化 QStyleOptionFrame
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}


void clockHZJ::changetheme(){
    if(ThemeStyle==0){
        this->setStyleSheet(//这里需要使用diy
            "QWidget#clockHZJ{"
            "    background-image: url(:/PKU/width.jpg);" // 设置背景图片
            "    background-position: center;" // 将图片放置在中心
            "    background-repeat: no-repeat;" // 禁止图片重复
            "    background-size: 100% 100%;" // 使图片拉伸以适应窗口大小
            "}"
            );
        ui->alarms->setStyleSheet(
            "QPushButton {"
            "    background-color: rgba(247, 22, 60, 0.865);"
            "    border: 0px solid rgba(115, 177, 166, 0.865);"//设置边框
            "    color:rgb(5, 12, 12);"// 设置按钮文本的颜色为黑色（RGB值为5, 12, 12）
            "    border-radius: 24;"// 设置按钮的边框半径为6像素，使其圆角化
            "    font: 10pt '幼圆';"// 设置按钮文本的字体为 10 点大小的楷体
            "}"
            );
        ui->rsec_clo->setStyleSheet(
            "QPushButton {"
            "    background-color: rgba(247, 22, 60, 0.865);"
            "    border: 0px solid rgba(115, 177, 166, 0.865);"//设置边框
            "    color:rgb(5, 12, 12);"// 设置按钮文本的颜色为黑色（RGB值为5, 12, 12）
            "    border-radius: 24;"// 设置按钮的边框半径为6像素，使其圆角化
            "    font: 10pt '幼圆';"// 设置按钮文本的字体为 10 点大小的楷体
            "}");
        ui->sec_clock->setStyleSheet(
            "QPushButton {"
            "    background-color: rgba(247, 22, 60, 0.865);"
            "    border: 0px solid rgba(115, 177, 166, 0.865);"//设置边框
            "    color:rgb(5, 12, 12);"// 设置按钮文本的颜色为黑色（RGB值为5, 12, 12）
            "    border-radius: 24;"// 设置按钮的边框半径为6像素，使其圆角化
            "    font: 10pt '幼圆';"// 设置按钮文本的字体为 10 点大小的楷体
            "}"
            );

    }
    else if(ThemeStyle==1){
        this->setStyleSheet(
            "QWidget{"
            "    background-image: url(:/background/pku_mainbg.jpg);" // 设置背景图片
            "    background-position: center;" // 将图片放置在中心
            "    background-repeat: no-repeat;" // 禁止图片重复
            "    background-size: 100% 100%;" // 使图片拉伸以适应窗口大小
            "}"
            );
    }
    else if(ThemeStyle==2){
        this->setStyleSheet(
            "QWidget{"
            "    background-image: url(:/background/pku_mainbg.jpg);" // 设置背景图片
            "    background-position: center;" // 将图片放置在中心
            "    background-repeat: no-repeat;" // 禁止图片重复
            "    background-size: 100% 100%;" // 使图片拉伸以适应窗口大小
            "}"
            );
    }
    emit themeChanged();
}
