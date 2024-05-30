#include "sec_clock.h"
#include "ui_sec_clock.h"
#include"global.h"
#include<QStyleOptionFrame>
#include<QPainter>

static int i;//打点计数

sec_clock::sec_clock(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::sec_clock)
{
    ui->setupUi(this);
    setWindowTitle(QStringLiteral("计时器"));
    setWindowIcon(QIcon(":/icon/hzj2.jpg"));
    connect(&timer,SIGNAL(timeout()),this,SLOT(timeout_slot()));

    time.setHMS(0,0,0,0);//时间初始化
    ui->showtime->setText("00:00:00:000");

    connect(&timer_cur, SIGNAL(timeout()), this, SLOT(showcurtime()));
    timer_cur.start(1000);
    ui->curtime->setText("0000-00-00 00:00:00");

    QFont font1("YouYuan",20),font2("YouYuan",10);
    ui->label->setFont(font1);
    ui->curtime->setFont(font1);
    ui->showpoints->setFont(font2);
    changetheme();
}

sec_clock::~sec_clock()
{
    delete ui;
}


void sec_clock::showcurtime(){
    curDTime = QDateTime::currentDateTime();
    ui->curtime->setText(curDTime.toString("yyyy-MM-dd HH:mm:ss"));
}

void sec_clock::timeout_slot(){
    time=time.addMSecs(32);
    ui->showtime->setText(time.toString("HH:mm:ss.zzz"));
}

void sec_clock::on_start_clicked()
{
    timer.start(30);
}

void sec_clock::on_pause_clicked()
{
    timer.stop();
}

void sec_clock::on_clear_clicked()
{
    //
    timer.stop();
    time.setHMS(0,0,0,0);//时间初始化
    ui->showtime->setText("00:00:00:000");
    //
    ui->showpoints->clear();
    i=0;
}

void sec_clock::on_setpoint_clicked()
{
    QString temp;
    i++;
    temp=QString::asprintf("%0*d:  ",2,i);
    ui->showpoints->append(temp+time.toString("HH:mm:ss.zzz"));
}

void sec_clock::paintEvent(QPaintEvent *e)
{
    QStyleOptionFrame opt;
    opt.initFrom(this);  // 初始化 QStyleOptionFrame
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void sec_clock::changetheme(){
    if(ThemeStyle==0){
        this->setStyleSheet(
            "QWidget#sec_clock{"
            "    background-image: url(:/PKU/hg.png);" // 设置背景图片
            "    background-position: center;" // 将图片放置在中心
            "    background-repeat: no-repeat;" // 禁止图片重复
            "    background-size: 100% 100%;" // 使图片拉伸以适应窗口大小
            "}"
            );
    }
    else if(ThemeStyle==1){


    }
    else if(ThemeStyle==2){


    }

}
