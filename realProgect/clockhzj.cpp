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
    sec->show();
}


void clockHZJ::on_rsec_clo_clicked()
{
    r_clock *rck=new r_clock;
    rck->show();
}


void clockHZJ::on_alarms_clicked()
{
    alarm *ala=new alarm;
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
        this->setStyleSheet(
            "QWidget#clockHZJ{"
            "    background-image: url(:/background/current.jpg);" // 设置背景图片
            "    background-position: center;" // 将图片放置在中心
            "    background-repeat: no-repeat;" // 禁止图片重复
            "    background-size: 100% 100%;" // 使图片拉伸以适应窗口大小
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
