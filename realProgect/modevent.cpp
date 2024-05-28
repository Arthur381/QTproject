#include "modevent.h"
#include "ui_modevent.h"
#include "calendarmc.h"
#include<QKeyEvent>
#include<QFile>
#include<QCoreApplication>
#include <QPainter>
#include"global.h"
#include <QStyleOption>

//现存的问题：List始终是空的，每次添加一个元素，就要打印出来；
//使用单例,每次重新初始化列表
ModEvent::ModEvent(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ModEvent)
{

    ui->setupUi(this);

    //ui->tableWidget->clear();
    calendarMC* m_ptrcalendar=calendarMC::getinstance();
    PrintP();//将数据显示在TableWidget上；

}


void ModEvent::PrintP(){
    calendarMC* m_ptrcalendar=calendarMC::getinstance();
    auto cnt = m_ptrcalendar->countNum();
    QList<AEventInfo> listeve=m_ptrcalendar->getPage(0,cnt);//仅仅跟踪到它指向的Qlist里面
    ui->tableWidgetInmod->clearContents();
    ui->tableWidgetInmod->setRowCount(cnt);
    for(int i=0;i<listeve.size();i++){
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(i));
        item->setTextAlignment(Qt::AlignCenter); // 设置水平和垂直居中对齐
        ui->tableWidgetInmod->setItem(i,0,item);
        ui->tableWidgetInmod->setItem(i,1,new QTableWidgetItem(listeve[i].name));
        ui->tableWidgetInmod->setItem(i,2,new QTableWidgetItem(listeve[i].date));
        ui->tableWidgetInmod->setItem(i,3,new QTableWidgetItem(listeve[i].atimes));
        ui->tableWidgetInmod->setItem(i,4,new QTableWidgetItem(listeve[i].mood));
        ui->tableWidgetInmod->setItem(i,5,new QTableWidgetItem(listeve[i].details));
    }
}


ModEvent::~ModEvent()
{
    delete ui;
}

void ModEvent::on_pushButton_add_clicked()//点击之后加入事项
{
    AEventInfo aeve;
    ;//创建实例化对象
    QString Sdate=ui->inputdate->text();
    //这一段是为了转化形式##############################################
    //qDebug()<<"Sdate"<<Sdate;
    QDate Tmpdate = QDate::fromString(Sdate, "yyyy/M/d");
    //qDebug()<<"Tmpdate"<<Tmpdate;
    //QString Findate=Tmpdate.toString();//这里是单词
    QString Findate = Tmpdate.toString("yyyy/MM/dd");
    //qDebug()<<"Findate"<<Findate;
    //#################################################################
    aeve.date=Findate;
    if(aeve.date==""){
        QMessageBox::critical(this,"输入错误","不能插入过去的时间");
        return;
    }
    aeve.name=ui->lineEditID->text();
    aeve.atimes=ui->inputtime->text();
    aeve.mood=ui->comboBox_moodchange->currentText();
    aeve.details=ui->WriteEve->text();
    calendarMC::getinstance()->AddEvent(aeve);//将数据加入到数据库中，并加入在相应的List中
    PrintP();//将数据显示在TableWidget上；
    calendarMC::getinstance()->ChangeOneDay(Tmpdate,aeve.mood);
}


void ModEvent::on_pushButton_delete_clicked()
{
    //创建实例化对象,单例
    QString Aname=ui->lineEdit_eve->text();//读取到标题
    qDebug()<<"delete Enter";
    calendarMC::getinstance()->DeleteEvent(Aname);
    PrintP();
}

void ModEvent::paintEvent(QPaintEvent *e)
{
    QStyleOptionFrame opt;
    opt.initFrom(this);  // 初始化 QStyleOptionFrame
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void ModEvent::changetheme(){
    if(ThemeStyle==0){


    }
    else if(ThemeStyle==1){



    }
    else if(ThemeStyle==2){

    }
}


