#include "r_clock.h"
#include "ui_r_clock.h"
#include <QPushButton>
#include <QMessageBox>
#include <QLabel>
#include <QMovie>
#include"global.h"

static bool if_pause;

r_clock::r_clock(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::r_clock)
{
    ui->setupUi(this);
    //设置输入时间范围
    ui->sb_hour->setMinimum(0);
    ui->sb_hour->setMaximum(99);
    ui->sb_min->setMinimum(0);
    ui->sb_min->setMaximum(59);
    ui->sb_sec->setMinimum(0);
    ui->sb_sec->setMaximum(59);
    //插入动图
    QMovie *shalou = new QMovie(":image\\shalou.gif");
    ui->label_shalou->setMovie(shalou);
    shalou->setScaledSize(ui->label_shalou->size());
    shalou->start();

    //初始化
    total = 0;
    if_pause=1;

    p_timer = new QTimer(this);
    connect(p_timer,SIGNAL(timeout()),this,SLOT(update()));

    //时间随输入变化
    connect(ui->sb_hour, SIGNAL(valueChanged(int)), this, SLOT(hourChanged()));
    connect(ui->sb_min, SIGNAL(valueChanged(int)), this, SLOT(minChanged()));
    connect(ui->sb_sec, SIGNAL(valueChanged(int)), this, SLOT(secChanged()));
    display_number();
}

r_clock::~r_clock()
{
    delete ui;
}
//每秒更新时间
void r_clock::update(){
    total-=1;
    display_number();

    if(total==0)
    {
        p_timer->stop();

        QMessageBox::information(this,"tip","时间到了哦！");
        //使按键可以再次被调整
        ui->sb_hour->setDisabled(0);
        ui->pushButton->setDisabled(0);
        ui->sb_min->setDisabled(0);
        ui->sb_sec->setDisabled(0);
    }
}
//显示剩下的时间
void r_clock::display_number(){
    ui->hour1->setText(QString::number(total/36000));
    ui->hour2->setText(QString::number((total/3600)%10));
    ui->min1->setText(QString::number((total%3600)/600));
    ui->min2->setText(QString::number(((total%3600)/60)%10));
    ui->sec1->setText(QString::number((total%60)/10));
    ui->sec2->setText(QString::number(((total%60)%10)));
};

void r_clock::on_pushButton_clicked()
{
    total = ui->sb_hour->value()*3600+ui->sb_min->value()*60+ui->sb_sec->value();
    p_timer->start(1000);
    //开始后按键不可调整
    ui->sb_hour->setDisabled(1);
    ui->pushButton->setDisabled(1);
    ui->sb_min->setDisabled(1);
    ui->sb_sec->setDisabled(1);
}
//时间与输入同步
void r_clock::hourChanged(){
    ui->hour1->setText(QString::number(ui->sb_hour->value()/10));
    ui->hour2->setText(QString::number(ui->sb_hour->value()%10));
}
void r_clock::minChanged(){
    ui->min1->setText(QString::number(ui->sb_min->value()/10));
    ui->min2->setText(QString::number(ui->sb_min->value()%10));
}
void r_clock::secChanged(){
    ui->sec1->setText(QString::number(ui->sb_sec->value()/10));
    ui->sec2->setText(QString::number(ui->sb_sec->value()%10));
}
//立即结束
void r_clock::on_end_clicked()
{
    total=1;
    ui->hour1->setText(QString::number(0));
    ui->hour2->setText(QString::number(0));
    ui->min1->setText(QString::number(0));
    ui->min2->setText(QString::number(0));
    ui->sec1->setText(QString::number(0));
    ui->sec2->setText(QString::number(0));
}
//暂停与继续
void r_clock::on_pause_clicked()
{
    if(if_pause){
        p_timer->stop();
        ui->pause->setText("继续");
        if_pause=0;
    }else{
        p_timer->start();
        ui->pause->setText("暂停");
        if_pause=1;
    }
}

void r_clock::changetheme(){
    if(ThemeStyle==0){

    }
    else if(ThemeStyle==1){


    }
    else if(ThemeStyle==2){


    }

}
