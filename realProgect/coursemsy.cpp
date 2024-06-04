#include "coursemsy.h"
#include"global.h"
#include "ui_coursemsy.h"
#include "schedulemsy.h"
//建立数据库存储所有数据
#include <QSqlDatabase>
#include <QSqlQuery>

coursemsy* coursemsy::ptrcoursemsy = nullptr;

coursemsy::coursemsy(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::coursemsy)
{
    ui->setupUi(this);

    ui->selectDay->addItem("1");
    ui->selectDay->addItem("2");
    ui->selectDay->addItem("3");
    ui->selectDay->addItem("4");
    ui->selectDay->addItem("5");
    ui->selectDay->addItem("6");
    ui->selectDay->addItem("7");


    ui->selectTime->addItem("1");
    ui->selectTime->addItem("2");
    ui->selectTime->addItem("3");
    ui->selectTime->addItem("4");
    ui->selectTime->addItem("5");
    // ui->selectTime->addItem("6");
    // ui->selectTime->addItem("7");
    // ui->selectTime->addItem("8");
    // ui->selectTime->addItem("9");
    // ui->selectTime->addItem("10");
    // ui->selectTime->addItem("11");

    QFont font1("YouYuan",15);
    ui->label_20->setFont(font1);

    setWindowTitle(QStringLiteral("课程表"));
    setWindowIcon(QIcon(":/icon/coursemsy1.jpg"));
    QFont font3("YouYuan",15);
    ui->label_19->setFont(font3);
    ui->label_18->setFont(font3);

    QFont font2("FZShuTi",11);
    ui->label->setFont(font2);
    ui->label_6->setFont(font2);
    ui->label_2->setFont(font2);
    ui->label_3->setFont(font2);
    ui->label_4->setFont(font2);
    ui->label_5->setFont(font2);
    ui->label_6->setFont(font2);
    ui->label_7->setFont(font2);
    ui->label_8->setFont(font2);
    ui->label_9->setFont(font2);
     ui->label_11->setFont(font2);
      ui->label_12->setFont(font2);
       ui->label_15->setFont(font2);



    /*
    ui->selectTime->addItem("第一节");
    ui->selectTime->addItem("第二节");
    ui->selectTime->addItem("午休时间");
    ui->selectTime->addItem("第三节");
    ui->selectTime->addItem("第四节");
    ui->selectTime->addItem("晚饭时间");
    ui->selectTime->addItem("第五节");
    ui->selectTime->addItem("第六节");
*/

    CreatDataFunc();
    CreatTableFunc();
    changetheme();
}

coursemsy::~coursemsy()
{
    delete ui;
}

void coursemsy::CreatDataFunc(){//创建SQLite数据库
    //1.添加数据库驱动
    sqldb=QSqlDatabase::addDatabase("QSQLITE","msyconnection");
    //2.设置数据库名称
    sqldb.setDatabaseName("CourseShow.db");
    //3.打开数据库是否成功
    if(sqldb.open()==true){
        //QMessageBox::information(0,"正确","恭喜你，数据库打开成功",QMessageBox::Ok);
    }
    else{
        //QMessageBox::critical(0,"错误","数据库打开失败",QMessageBox::Ok);
    }
}

void coursemsy::CreatTableFunc(){//创建sqlite数据表
    QSqlDatabase db=QSqlDatabase::database("msyconnection");
    if(!db.isOpen()){
        qDebug()<<"error";
        return;
    }
    QSqlQuery sql(db);

    QString strsql=QString("create table courseDemo("
                             "id int primary key not null,"
                             "col int not null,"
                             "row int not null,"
                             "courseName text not null,"
                             "unique(col,row))");

    //执行SQL语句
    if(sql.exec(strsql)==false){
       // QMessageBox::critical(0,"错误","数据表创建失败",QMessageBox::Ok);
    }
    else{
       //QMessageBox::information(0,"正确","恭喜你，数据表创建成功",QMessageBox::Ok);
    }
}

void coursemsy::on_pushButton_clicked()//显示课程表的
{
    scheduleMSY *Aschedulemsy=new scheduleMSY;
    Aschedulemsy->show();
}

int coursemsy::countnum(){
    QSqlQuery sql(sqldb);
    sql.exec("select * from courseDemo");
    int uiCnt=0;
    while(sql.next()){
        uiCnt=sql.value(0).toUInt();//有可能会有bug
    }
    return uiCnt;
}

bool coursemsy::addone(CEventInfo info){
    QSqlDatabase db=QSqlDatabase::database("msyconnection");
    if(!db.isOpen()){
        qDebug()<<"error";
    }

    QSqlQuery sqlquery(db);

    QString text=ui->inputName->text();
    if (text.isEmpty()) {
        QMessageBox::warning(this, "失败", "请输入课程名称后再尝试");
        return false;
    }
    else{
    QString strsql=QString("INSERT INTO courseDemo VALUES(%1,%2,%3,'%4')").
                     arg(info.row*8+info.col).arg(info.col).arg(info.row).arg(info.courseName);
    if(sqlquery.exec(strsql)!=true){
        QMessageBox::critical(0,"失败","插入新课程失败!可能是时间重复。",QMessageBox::Ok);
    }
    else{
        QMessageBox::information(0,"Success","插入新课程成功。",QMessageBox::Ok);
        ui->inputName->clear();
        // ui->selectDay->clear();
        // ui->selectTime->clear();
    }
    }
    return true;
}

QList<CEventInfo> coursemsy::getPage(int page,int uicnt){//根本目的是得到列表
    QList<CEventInfo> l;
    QSqlQuery sql(sqldb);
    QString strsql=QString("select * from courseDemo order by id limit %1 offset %2")
                         .arg(uicnt).arg(page*uicnt);
    sql.exec(strsql);
    CEventInfo info;
    while(sql.next()){
        info.col=sql.value(1).toInt();
        info.row=sql.value(2).toInt();
        info.courseName=sql.value(3).toString();
        l.push_back(info);
    }
    return l;
}


void coursemsy::on_pushButton_2_clicked()//将课程添加到课程表中去
{
    CEventInfo info;
    info.col=ui->selectDay->currentText().toUInt();
    info.row=ui->selectTime->currentText().toUInt();
    info.courseName=ui->inputName->text();
    coursemsy::getinstance()->addone(info);//将数据加入到数据库中，并加入在相应的List中
    //PrintP();//将数据显示在TableWidget上；
}

bool coursemsy::delone(CEventInfo info){
    QSqlQuery sqlquery(sqldb);
    QString tex=QString("select * from courseDemo where col=%1 and row=%2").
                     arg(info.col).arg(info.row);
    qDebug()<<info.col;
    qDebug()<<info.row;
    if(sqlquery.exec(tex)!=true){
        QMessageBox::critical(0,"失败","此处尚未插入课程!",QMessageBox::Ok);
    }
    else{
    QString strsql=QString("delete from courseDemo where col=%1 and row=%2").//此处不完善，要加上两个条件才好
                     arg(info.col).arg(info.row);
        if(sqlquery.exec(strsql)!=true){
            QMessageBox::critical(0,"失败","删除课程失败!",QMessageBox::Ok);
        }
        else{
            QMessageBox::information(0,"成功","删除课程成功。",QMessageBox::Ok);
        }
    }
    return true;
}

void coursemsy::on_delCourse_clicked()
{
    CEventInfo info;
    info.col=ui->selectDay->currentText().toUInt();
    info.row=ui->selectTime->currentText().toUInt();
    info.courseName=ui->inputName->text();
    coursemsy::getinstance()->delone(info);
}

void coursemsy::changetheme(){
    ui->label->setStyleSheet(
        "background-color: rgba(255,255,255, 0.565);"
        "font: 18pt '幼圆';"// 设置按钮文本的字体为 10 点大小
        "qproperty-alignment: 'AlignCenter';"  // 样式表中设置文本居中对齐
        "font-weight: bold;"  // 设置字体加粗
        );
    ui->label_11->setStyleSheet(
        "background-color: rgba(255,255,255, 0.565);"
        "font: 14pt '幼圆';"// 设置按钮文本的字体为 10 点大小
        "qproperty-alignment: 'AlignCenter';"  // 样式表中设置文本居中对齐
        );
    ui->label_12->setStyleSheet(
        "background-color: rgba(255,255,255, 0.565);"
        "font: 14pt '幼圆';"// 设置按钮文本的字体为 10 点大小
        "qproperty-alignment: 'AlignCenter';"  // 样式表中设置文本居中对齐
        );
    ui->label_15->setStyleSheet(
        "background-color: rgba(255,255,255, 0.565);"
        "font: 14pt '幼圆';"// 设置按钮文本的字体为 10 点大小
        "qproperty-alignment: 'AlignCenter';"  // 样式表中设置文本居中对齐
        );

    ui->label_2->setStyleSheet(
        "background-color: rgba(255,255,255, 0.565);"
        "font: 18pt '幼圆';"// 设置按钮文本的字体为 10 点大小
        "qproperty-alignment: 'AlignCenter';"  // 样式表中设置文本居中对齐
        "font-weight: bold;"  // 设置字体加粗
        );

    ui->label_3->setStyleSheet(
        "background-color: rgba(255,255,255, 0.565);"
        "font: 18pt '幼圆';"// 设置按钮文本的字体为 10 点大小
        "qproperty-alignment: 'AlignCenter';"  // 样式表中设置文本居中对齐
        "font-weight: bold;"  // 设置字体加粗
        );
    ui->label_4->setStyleSheet(
        "background-color: rgba(255,255,255, 0.565);"
        "font: 18pt '幼圆';"// 设置按钮文本的字体为 10 点大小
        "qproperty-alignment: 'AlignCenter';"  // 样式表中设置文本居中对齐
        "font-weight: bold;"  // 设置字体加粗
        );
    ui->label_5->setStyleSheet(
        "background-color: rgba(255,255,255, 0.565);"
        "font: 18pt '幼圆';"// 设置按钮文本的字体为 10 点大小
        "qproperty-alignment: 'AlignCenter';"  // 样式表中设置文本居中对齐
        "font-weight: bold;"  // 设置字体加粗
        );
    ui->label_6->setStyleSheet(
        "background-color: rgba(255,255,255, 0.565);"
        "font: 18pt '幼圆';"// 设置按钮文本的字体为 10 点大小
        "qproperty-alignment: 'AlignCenter';"  // 样式表中设置文本居中对齐
        "font-weight: bold;"  // 设置字体加粗
        );
    ui->label_7->setStyleSheet(
        "background-color: rgba(255,255,255, 0.565);"
        "font: 18pt '幼圆';"// 设置按钮文本的字体为 10 点大小
        "qproperty-alignment: 'AlignCenter';"  // 样式表中设置文本居中对齐
        "font-weight: bold;"  // 设置字体加粗
        );
    ui->label_8->setStyleSheet(
        "background-color: rgba(255,255,255, 0.565);"
        "font: 14pt '幼圆';"// 设置按钮文本的字体为 10 点大小
        "qproperty-alignment: 'AlignCenter';"  // 样式表中设置文本居中对齐
        );
    ui->label_9->setStyleSheet(
        "background-color: rgba(255,255,255, 0.565);"
        "font: 14pt '幼圆';"// 设置按钮文本的字体为 10 点大小
        "qproperty-alignment: 'AlignCenter';"  // 样式表中设置文本居中对齐
        );
    /**
         *
         *三个比较特殊的label
         *
         */
    ui->label_18->setStyleSheet(
        "background-color: rgba(255,255,255, 0);"
        "font: 14pt '幼圆';"// 设置按钮文本的字体为 10 点大小
        "qproperty-alignment: 'AlignCenter';"  // 样式表中设置文本居中对齐
        );
    ui->label_19->setStyleSheet(
        "background-color: rgba(255,255,255, 0);"
        "font: 14pt '幼圆';"// 设置按钮文本的字体为 10 点大小
        "qproperty-alignment: 'AlignCenter';"  // 样式表中设置文本居中对齐
        );
    ui->label_20->setStyleSheet(
        "background-color: rgba(255,255,255, 0);"
        "font: 14pt '幼圆';"// 设置按钮文本的字体为 10 点大小
        "qproperty-alignment: 'AlignCenter';"  // 样式表中设置文本居中对齐
        );

    /**
         * 设置背景
         */
    if(ThemeStyle==0){

        this->setStyleSheet(
            "QDialog{"
            "    background-image: url(:/PKU/sda.jpg);" // 设置背景图片
            "    background-position: center;" // 将图片放置在中心
            "    background-repeat: no-repeat;" // 禁止图片重复
            "    background-size: 100% 100%;" // 使图片拉伸以适应窗口大小
            "}"

            );

    }
    else if(ThemeStyle==1){
        this->setStyleSheet(
            "QDialog{"
            "    background-image: url(:/happydog/course.jpg);" // 设置背景图片
            "    background-position: center;" // 将图片放置在中心
            "    background-repeat: no-repeat;" // 禁止图片重复
            "    background-size: 100% 100%;" // 使图片拉伸以适应窗口大小
            "}"
        );


    }
    else if(ThemeStyle==2){

    }
    emit themechanged();
}
