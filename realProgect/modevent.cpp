#include "modevent.h"
#include "ui_modevent.h"
#include "calendarmc.h"
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
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(cnt);
    for(int i=0;i<listeve.size();i++){
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(i)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(listeve[i].name));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(listeve[i].date));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(listeve[i].atimes));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(listeve[i].mood));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(listeve[i].details));
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
}


void ModEvent::on_pushButton_delete_clicked()
{
    //创建实例化对象,单例
    QString Aname=ui->lineEdit_eve->text();
    calendarMC::getinstance()->DeleteEvent(Aname);
    PrintP();
}




