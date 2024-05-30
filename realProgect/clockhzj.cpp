#include "clockhzj.h"
#include "ui_clockhzj.h"
#include <QPainter>
#include <QStyleOption>
#include "sec_clock.h"
#include "alarm.h"
#include "r_clock.h"
#include "global.h"
#include <QDebug>
#include <QPainter>
#include <QLabel>
#include <QWidget>

clockHZJ::clockHZJ(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::clockHZJ)
{
    ui->setupUi(this);
    this->changetheme();

    setWindowTitle(QStringLiteral("时间管理"));

    //setWindowIcon("");
    QFont font1("YouYuan",25);
    ui->label->setFont(font1);
    ui->curtime->setFont(font1);

    ui->alarms->raise();
    ui->rsec_clo->raise();
    ui->sec_clock->raise();
    //set pictures
    QPixmap pix1(":image/rtt.png");
    QPixmap pix2(":image/stt.png");
    QPixmap pix3(":image/ala.png");
    pix1 = pix1.scaled(ui->la1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    pix2 = pix2.scaled(ui->la2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    pix3 = pix3.scaled(ui->la3->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->la1->setPixmap(pix1);
    ui->la2->setPixmap(pix2);
    ui->la3->setPixmap(pix3);
    ui->la1->show();
    ui->la2->show();
    ui->la3->show();


    ui->alarms->setStyleSheet("QPushButton { background-color: rgba(0, 0, 0, 0); }");
    ui->rsec_clo->setStyleSheet("QPushButton { background-color: rgba(0, 0, 0, 0); }");
    ui->sec_clock->setStyleSheet("QPushButton { background-color: rgba(0, 0, 0, 0); }");


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
