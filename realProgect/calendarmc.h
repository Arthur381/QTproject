#ifndef CALENDARMC_H
#define CALENDARMC_H

#include <QWidget>
#include<QList>
#include <QSqlDatabase>//用于连接，创建数据库
#include <QSqlError>
#include <QSqlQuery>//专用于DML（数据操纵语言），DDL（数据定义语言）
#include <QSqlQueryModel>
#include <QtDebug>
#include<QMessageBox>
#include <QDateTime>


/*
功能说明：
1.插入事项的日子在日历中如果能显示（如颜色）则尽可能完成。
2.点击Qt日历中的一天，展开这一天的日程。（如果这一天没有则显示无日程）。
3.日历，修改事项和倒数日共同使用一个数据库，方便数据的修改和查询。
4.可以学习创建一个表。
……
*/

namespace Ui {
class calendarMC;
}

struct AEventInfo
{
    QString name;
    QString date;
    QString atimes;
    QString mood;
    QString details;
};



class calendarMC : public QWidget
{
    Q_OBJECT

public:
    static calendarMC *ptrcalendar;//类内声明的静态指针
    static calendarMC *getinstance(){
        if(nullptr==ptrcalendar){
            ptrcalendar=new calendarMC;
        }
        return ptrcalendar;
    }

    ~calendarMC();

private slots:
    void on_Modify_clicked();
    void on_countdowndays_clicked();


private:
    explicit calendarMC(QWidget *parent = nullptr);
    void CreatDataFunc();//创建SQLite数据库
    void CreatTableFunc();//创建sqlite数据表
    void QueryTableFunc();//查询
    QSqlDatabase sqldb;//创建qt和数据库连接
    QSqlQueryModel sqimodel;//存储结果集
    QList<AEventInfo> eves;//行的列表

public:
    bool AddEvent(AEventInfo newEve);
    bool DeleteEvent(QString name);
    int countNum();
    QList<AEventInfo> getEventList() const {
        return eves; // 假设 eventList 是 calendarMC 类中的成员变量，存储了事件列表
    }
    bool iffind(QString name);


private:
    Ui::calendarMC *ui;
};

#endif // CALENDARMC_H
