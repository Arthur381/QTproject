#include "alarm.h"
#include "ui_alarm.h"
#include <QPushButton>
#include"global.h"
#include <QMessageBox>
#include <QDebug>
#include <QCheckBox>
#include<QStyleOptionFrame>
#include<QPainter>

static bool cs1,cs2,cs3,cs4,cs5;
static bool con1,con2,con3,con4,con5;

alarm::alarm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::alarm)
{

    setWindowTitle(QStringLiteral("闹钟"));
    setWindowIcon(QIcon(":/icon/hzj4.jpg"));

    cs1=cs2=cs3=cs4=cs5=0;
    con1=con2=con3=con4=con5=1;
    ui->setupUi(this);
    ui->time1->setDisplayFormat("hh:mm:ss");
    ui->time2->setDisplayFormat("hh:mm:ss");
    ui->time3->setDisplayFormat("hh:mm:ss");
    ui->time4->setDisplayFormat("hh:mm:ss");
    ui->time5->setDisplayFormat("hh:mm:ss");
    //show current time
    connect(&timer_cur, SIGNAL(timeout()), this, SLOT(showcurtime()));
    timer_cur.start(1000);
    ui->curtime->setText("0000-00-00 00:00:00");
    timerunner.start(1000);
    connect(&timerunner,SIGNAL(timeout()), this, SLOT(checktime()));
    changetheme();

    QFont font1("YouYuan",20);
    ui->label->setFont(font1);
    ui->label_2->setFont(font1);
    ui->label_3->setFont(font1);


}

alarm::~alarm()
{
    delete ui;
}

void alarm::paintEvent(QPaintEvent *e)
{
    QStyleOptionFrame opt;
    opt.initFrom(this);  // 初始化 QStyleOptionFrame
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void alarm::checktime(){
    QDateTime present_time = QDateTime::currentDateTime();
    QString timeText = present_time.toString("hh:mm:ss");
    if(cs1){
        QString settime1=ui->time1->text();
        if(timeText==settime1){
            QMessageBox::information(this,"tip",ui->line1->text());
            if(con1){
                ui->time1->setReadOnly(false);
                ui->check1->setText("启用");
            }
        }
    }
    if(cs2){
        QString settime2=ui->time2->text();
        if(timeText==settime2){
            QMessageBox::information(this,"tip",ui->line2->text());
            if(con2){
                ui->time2->setReadOnly(false);
                ui->check2->setText("启用");
            }
        }
    }
    if(cs3){
        QString settime3=ui->time3->text();
        if(timeText==settime3){
            QMessageBox::information(this,"tip",ui->line3->text());
            if(con3){
                ui->time3->setReadOnly(false);
                ui->check3->setText("启用");
            }
        }
    }
    if(cs4){
        QString settime4=ui->time4->text();
        if(timeText==settime4){
            QMessageBox::information(this,"tip",ui->line4->text());
            if(con4){
                ui->time4->setReadOnly(false);
                ui->check4->setText("启用");
            }
        }
    }
    if(cs5){
        QString settime5=ui->time5->text();
        if(timeText==settime5){
            QMessageBox::information(this,"tip",ui->line5->text());
            if(con5){
                ui->time5->setReadOnly(false);
                ui->check5->setText("启用");
            }
        }
    }
}

void alarm::showcurtime(){
    curDTime = QDateTime::currentDateTime();
    ui->curtime->setText(curDTime.toString("yyyy-MM-dd HH:mm:ss"));
}


void alarm::on_set1_clicked()
{
    if(con1){
        ui->set1->setText("重复");
        con1=0;
    }else{
        ui->set1->setText("仅一次");
        con1=1;
    }
}

void alarm::on_set2_clicked()
{
    if(con2){
        ui->set2->setText("重复");
        con2=0;
    }else{
        ui->set2->setText("仅一次");
        con2=1;
    }
}

void alarm::on_set3_clicked()
{
    if(con3){
        ui->set3->setText("重复");
        con3=0;
    }else{
        ui->set3->setText("仅一次");
        con3=1;
    }
}

void alarm::on_set4_clicked()
{
    if(con4){
        ui->set4->setText("重复");
        con4=0;
    }else{
        ui->set4->setText("仅一次");
        con4=1;
    }
}

void alarm::on_set5_clicked()
{
    if(con5){
        ui->set5->setText("重复");
        con5=0;
    }else{
        ui->set5->setText("仅一次");
        con5=1;
    }
}

void alarm::on_check1_clicked()
{
    cs1=!cs1;
    if(cs1==1){
        ui->time1->setReadOnly(true);
        ui->check1->setText("停用");
    }else{
        ui->time1->setReadOnly(false);
        ui->check1->setText("启用");
    }
}

void alarm::on_check2_clicked()
{
    cs2=1-cs2;
    if(cs2==1){
        ui->time2->setReadOnly(true);
        ui->check2->setText("停用");
    }else{
        ui->time2->setReadOnly(false);
        ui->check2->setText("启用");
    }
}

void alarm::on_check3_clicked()
{
    cs3=1-cs3;
    if(cs3==1){
        ui->time3->setReadOnly(true);
        ui->check3->setText("停用");
    }else{
        ui->time3->setReadOnly(false);
        ui->check3->setText("启用");
    }
}

void alarm::on_check4_clicked()
{
    cs4=1-cs4;
    if(cs4==1){
        ui->time4->setReadOnly(true);
        ui->check4->setText("停用");
    }else{
        ui->time4->setReadOnly(false);
        ui->check4->setText("启用");
    }
}


void alarm::on_check5_clicked()
{
    cs5=1-cs5;
    if(cs5==1){
        ui->time5->setReadOnly(true);
        ui->check5->setText("停用");
    }else{
        ui->time5->setReadOnly(false);
        ui->check5->setText("启用");
    }
}

void alarm::changetheme(){
    if(ThemeStyle==0){
        QPixmap pixmain3(":PKU/mini5.png");
        pixmain3 = pixmain3.scaled(ui->l1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        ui->l1->setPixmap(pixmain3); // 显示 QLabel
        ui->l1->show();

        this->setStyleSheet(
            "QWidget#alarm{"
            "    background-image: url(:/PKU/yh.png);" // 设置背景图片
            "    background-position: center;" // 将图片放置在中心
            "    background-repeat: no-repeat;" // 禁止图片重复
            "    background-size: 100% 100%;" // 使图片拉伸以适应窗口大小
            "}"
            );
    }
    else if(ThemeStyle==1){
        QPixmap pixmain3(":happydog/time.jpg");
        pixmain3 = pixmain3.scaled(ui->l1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        ui->l1->setPixmap(pixmain3); // 显示 QLabel
        ui->l1->show();

        this->setStyleSheet(
            "QWidget#alarm{"
            "    background-image: url(:happydog/time.jpg);" // 设置背景图片
            "    background-position: center;" // 将图片放置在中心
            "    background-repeat: no-repeat;" // 禁止图片重复
            "    background-size: 100% 100%;" // 使图片拉伸以适应窗口大小
            "}"
            );

    }
    else if(ThemeStyle==2){


    }

}
