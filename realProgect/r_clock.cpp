#include "r_clock.h"
#include "ui_r_clock.h"
#include <QPushButton>
#include <QMessageBox>
#include <QLabel>
#include <QMovie>
#include"global.h"
#include<QStyleOptionFrame>
#include<QPainter>

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

    QFont font1("YouYuan",30);
    ui->label_5->setFont(font1);

    changetheme();
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

void r_clock::paintEvent(QPaintEvent *e)
{
    QStyleOptionFrame opt;
    opt.initFrom(this);  // 初始化 QStyleOptionFrame
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void r_clock::changetheme(){
    if(ThemeStyle==0){
        /*this->setStyleSheet(
            "QWidget#r_clock{"
            "    background-image: url(:/PKU/symbol.png);" // 设置背景图片
            "    background-position: center;" // 将图片放置在中心
            "    background-repeat: no-repeat;" // 禁止图片重复
            "    background-size: 100% 100%;" // 使图片拉伸以适应窗口大小
            "}"
        );*/
        ui->pushButton->setStyleSheet(
            "QPushButton {"
            "    background-color: rgba(231, 113, 26, 0.865);"
            "    border: 0px solid rgba(115, 177, 166, 0.865);"//设置边框
            "    color:rgb(5, 12, 12);"// 设置按钮文本的颜色为黑色（RGB值为5, 12, 12）
            "    border-radius: 24;"// 设置按钮的边框半径为6像素，使其圆角化
            "    font: 14pt '楷体';"// 设置按钮文本的字体为 10 点大小的楷体
            "}"
            );
        ui->pause->setStyleSheet(
            "QPushButton {"
            "    background-color: rgba(171, 175, 33, 0.865);"
            "    border: 0px solid rgba(115, 177, 166, 0.865);"//设置边框
            "    color:rgb(5, 12, 12);"// 设置按钮文本的颜色为黑色（RGB值为5, 12, 12）
            "    border-radius: 24;"// 设置按钮的边框半径为6像素，使其圆角化
            "    font: 14pt '楷体';"// 设置按钮文本的字体为 10 点大小的楷体
            "}"
            );
        ui->end->setStyleSheet(
            "QPushButton {"
            "    background-color: rgba(213, 177, 39, 0.865);"
            "    border: 0px solid rgba(115, 177, 166, 0.865);"//设置边框
            "    color:rgb(5, 12, 12);"// 设置按钮文本的颜色为黑色（RGB值为5, 12, 12）
            "    border-radius: 24;"// 设置按钮的边框半径为6像素，使其圆角化
            "    font: 14pt '楷体';"// 设置按钮文本的字体为 10 点大小的楷体
            "}"
            );




    }
    else if(ThemeStyle==1){


    }
    else if(ThemeStyle==2){


    }

}
