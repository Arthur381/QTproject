#include "calendarmc.h"
#include "ui_calendarmc.h"
#include "modevent.h"
#include "countdowndaysmc.h"
#include "win_cal_viewmc.h"
#include "QDate"
#include<QDebug>
#include <QWidget>
#include <QPainter>
#include <QStyleOption>
#include <QTextCharFormat>
#include<qpainter.h>
#include<QKeyEvent>
#include<QFile>
#include<QCoreApplication>

calendarMC* calendarMC::ptrcalendar = nullptr;//在类外初始化

calendarMC::calendarMC(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::calendarMC)
    ,TToday(2000,1,1)
{
    ui->setupUi(this);
    TToday=QDate::currentDate();
    connect(ui->calendarWidget,SIGNAL(clicked(QDate)),this,SLOT(clickedSlot(QDate)));
    //创建且打开数据库,调用函数
    //ui->calendarWidget->setFont(QFont("Timers",8,QFont::Bold));
    CreatDataFunc();
    CreatTableFunc();
}

calendarMC::~calendarMC()
{
    delete ui;
}

void calendarMC::ChangeOneDay(const QDate date,const QString mood){
    /**
     * @brief specialDayFormat
     *
     * 根据moodString给指定位置上色
     *
     *
     */
    QTextCharFormat specialDayFormat;
    if(mood=="delete"){
        specialDayFormat.setBackground(Qt::white);
    }
    else if(mood=="开心"){
        specialDayFormat.setBackground(Qt::yellow);
    }
    else if(mood=="自信满满"){
        specialDayFormat.setBackground(Qt::red);
    }
    else if(mood=="焦虑"){
        specialDayFormat.setBackground(Qt::lightGray);
    }
    else if(mood=="无法形容"){
        specialDayFormat.setBackground(Qt::transparent);
    }
    else if(mood=="紧张"){
        specialDayFormat.setBackground(Qt::blue);
    }
    else if(mood=="激动"){
        specialDayFormat.setBackground(Qt::magenta);
    }
    else if(mood=="伤心"){
        specialDayFormat.setBackground(Qt::green);
    }
    else if(mood=="波澜不惊"){
        specialDayFormat.setBackground(Qt::cyan);
    }
    //specialDayFormat.setBackground(Qt::red); // 设置背景色为红色
    //specialDayFormat.setForeground(Qt::white); // 设置文本颜色为白色

    // 要标记的特定日期
    //QDate specialDate(2024, 5, 15);

    // 设置特定日期的文本格式
    qDebug()<<"oneday";
    ui->calendarWidget->setDateTextFormat(date, specialDayFormat);

}

void calendarMC::paintEvent(QPaintEvent *e)
{
    QStyleOptionFrame opt;
    opt.initFrom(this);  // 初始化 QStyleOptionFrame
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}


void calendarMC::ColorDays(){
/**
 *
 *在开始时调用，查看数据库中的事件，并且在这一天根据心情改变格子的颜色
 *
 */
    calendarMC* m_ptrcalendar=calendarMC::getinstance();
    auto cnt = m_ptrcalendar->countNum();//需要标记的次数
    QList<AEventInfo> listeve=m_ptrcalendar->getPage(0,cnt);//仅仅跟踪到它指向的Qlist里面
    for(int i=0;i<listeve.size();i++){
        QDate date = QDate::fromString(listeve[i].date,"yyyy/MM/dd");
        ChangeOneDay(date,listeve[i].mood);//将每一个改变颜色；
    }
}

void calendarMC::CreatDataFunc(){//sqldb实际上是一个静态变量
    //1.添加驱动
    sqldb=QSqlDatabase::addDatabase("QSQLITE");
    //2.名称
    sqldb.setDatabaseName("Event_cal.db");
    //3.数据库打开是否成功
    if(sqldb.open()!=true){
        QMessageBox::critical(0,"抱歉","数据库打开失败!",QMessageBox::Ok);
    }

}

QList<AEventInfo> calendarMC::getPage(int page,int uicnt){//根本目的是得到列表
    QList<AEventInfo> l;
    QSqlQuery sql(sqldb);
    QString strsql=QString("select * from event order by id limit %1 offset %2")
                         .arg(uicnt).arg(page*uicnt);
    sql.exec(strsql);
    int id;
    AEventInfo info;
    while(sql.next()){
        id=sql.value(0).toInt();
        info.name=sql.value(1).toString();
        info.date=sql.value(2).toString();
        //qDebug()<<info.date;
        info.atimes=sql.value(3).toString();
        info.mood=sql.value(4).toString();
        info.details=sql.value(5).toString();
        l.push_back(info);
    }
    return l;
}

QList<AEventInfo> calendarMC::selectPage(int page,int uicnt){//根本目的是得到列表
    QList<AEventInfo> l;
    /**
     * @brief sql
     *
     *筛选出未发生的事件然后，根据相隔的天数由近到远排序，最后输出到一个新的TableWidget中
    */
    // 构造查询语句，选择指定页面的事件数据
    QString strsql = QString("SELECT * FROM event WHERE date > :nowdate order by date");//直接排好序
    // 执行查询
    QSqlQuery sql(sqldb);
    sql.prepare(strsql);
    //强行规定形式，保证可排序
    sql.bindValue(":nowdate", TToday.toString("yyyy/MM/dd"));
    // 遍历查询结果
    qDebug()<<TToday.toString("yyyy/MM/dd");
    if(sql.exec()){
        while (sql.next()) {
            AEventInfo info;
            //qDebug()<<"date_val"<<sql.value(2).toString();
            info.name = sql.value(1).toString();
            info.date=sql.value(2).toString();
            info.atimes = sql.value(3).toString();
            info.mood = sql.value(4).toString();
            info.details = sql.value(5).toString();
            l.push_back(info);
            //qDebug()<<"if execute";
        }
    }
    else{
        QSqlError error = sql.lastError();
        qDebug() << "Database error:" << error.text();
    }

    return l;
}



void calendarMC::CreatTableFunc(){
    //创建SQL

    QSqlQuery createquery;
    QString strsql=QString("create table event("
                             "id int not null,"
                             "name text primary key not null,"
                             "date text not null,"
                             "atime text not null,"
                             "mood text not null,"
                             "details text not null)");

    //执行SQL
    if(createquery.exec(strsql)!=true){//已经创建
        //QMessageBox::critical(0,"抱歉","数据表创建失败!",QMessageBox::Ok);
    }
    else{
        QMessageBox::information(0,"Success","数据表创建成功。",QMessageBox::Ok);
    }
}

int calendarMC::countNum(){//统计行数
    QSqlQuery sql(sqldb);
    sql.exec("select count(id) from event;");
    int uiCnt=0;
    while(sql.next()){
        uiCnt=sql.value(0).toUInt();//有可能会有bug
    }
    return uiCnt;
}


bool calendarMC::AddEvent(AEventInfo newEve){

    QSqlQuery sqlquery(sqldb);
    quint32 id=calendarMC::countNum()+1;
    //qDebug()<<"id:"<<id;
    if(newEve.details==""){
        QMessageBox::critical(0,"失败","数据表插入新数据失败!详细信息不能为空！",QMessageBox::Ok);
        return true;
    }
    QString strs=QString("INSERT INTO event VALUES(%1,'%2','%3','%4','%5','%6')").
                   arg(id).arg(newEve.name).arg(newEve.date).arg(newEve.atimes).arg(newEve.mood).arg(newEve.details);

    if(sqlquery.exec(strs)!=true){
        QMessageBox::critical(0,"失败","数据表插入新数据失败!可能是标题重复。",QMessageBox::Ok);
    }
    else{
        QMessageBox::information(0,"Success","插入新事项成功。",QMessageBox::Ok);
        //getinstance()->getEventList().push_back(newEve);//加入在类内列表中,!!!不需要QLIst了！！！
    }
    return true;
}

bool calendarMC::iffind(QString name_){
    QSqlQuery sql(sqldb);
    QString queryString = "SELECT COUNT(*) FROM event WHERE name = :name";
    sql.prepare(queryString);

    sql.bindValue(":name", name_);

    // 执行 SQL 查询
    if (!sql.exec()) {
        qDebug() << "Error executing query:" << sql.lastError().text();
        return false;
    }

    // 获取查询结果
    if (sql.next()) {
        qDebug()<<"delete search"<<sql.value(1).toInt();
        int count = sql.value(0).toInt();
        if(count>0){
            QDate date = QDate::fromString(sql.value(2).toString(),"yyyy/MM/dd");
            calendarMC::getinstance()->ChangeOneDay(date,"delete");
            return true;
        }

    }

    return false;

}


bool calendarMC::DeleteEvent(QString name_){//输入序号之后删除一个事件；
    //为了取消标记，应该先找到，再删除
    QSqlQuery sql(sqldb);
    qDebug()<<"return:"<<calendarMC::iffind(name_)<<"name:"<<name_;
    if(calendarMC::iffind(name_)){
        QMessageBox::information(0,"Success","删除事项成功。",QMessageBox::Ok);
    }
    else{
        QMessageBox::critical(0,"失败","删除事项失败，您输入的事项不存在!",QMessageBox::Ok);
    }
    QString dequery="delete from event where name==:name";
    sql.prepare(dequery);
    sql.bindValue(":name", name_);
    // 执行 SQL 删除查询
    if (!sql.exec()) {
        qDebug() << "Error executing query:" << sql.lastError().text();
        return false;
    }
    // 如果删除成功，返回 true

    return true;
}



//void calendarMC::QueryTableFunc(){}

void calendarMC::on_Modify_clicked()
{
    ModEvent* eve=new ModEvent;
    eve->show();
}


void calendarMC::on_countdowndays_clicked()
{
    CountDownDaysMC* days=new CountDownDaysMC;
    days->show();
}

//单击信号
void calendarMC::clickedSlot(const QDate date)
{
    //为了能把这一天的日期传给新的窗口，需要实现单例化
    win_cal_viewMC* small_win=win_cal_viewMC::getinstance();
    QList<AEventInfo> sssList;
    QSqlQuery sql(sqldb);
    QString strsql = QString("SELECT * FROM event WHERE date = :cdate");//直接排好序
    sql.prepare(strsql);
    sql.bindValue(":cdate",date.toString("yyyy/MM/dd"));
    qDebug()<<"input"<< date;
    // 遍历查询结果
    if(sql.exec()){
        while (sql.next()) {
            AEventInfo info;
            //qDebug()<<"date_val"<<sql.value(2).toString();
            info.name = sql.value(1).toString();
            info.date=sql.value(2).toString();
            info.atimes = sql.value(3).toString();
            info.mood = sql.value(4).toString();
            info.details = sql.value(5).toString();
            sssList.push_back(info);
            qDebug()<<"if execute";
        }
    }
    else{
        QMessageBox::critical(0,"抱歉","查询失败",QMessageBox::Ok);
    }
    if(sssList.size()==0){
        QMessageBox::information(0,"这一天空空如也","加入日程或写点日记吧！",QMessageBox::Ok);
    }
    else{
        qDebug()<<sssList.size();
        small_win->show();//仍然是单例
        small_win->FindAndPrint(sssList);
    }
}
