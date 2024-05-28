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
//这里面不能include"win_cal_viewmc.h"

/*
功能说明：
1.插入事项的日子在日历中如果能显示（如颜色）则尽可能完成。
2.点击Qt日历中的一天，展开这一天的日程。（如果这一天没有则显示无日程）。
3.日历，修改事项和倒数日共同使用一个数据库，方便数据的修改和查询。
4.可以学习创建一个表。
//单击查看有事件标记的那一天
//当然，我需要先实现事件标记；暂时决定根据，心情不同使用不同的颜色标记；
……
*/

namespace Ui {
class calendarMC;
}

struct AEventInfo
{
    QString name;
    QString date;//为了可以比较大小，严格要求YYYY//MM//DD的形式
    QString atimes;
    QString mood;
    QString details;
};



class calendarMC : public QWidget
{
    Q_OBJECT

public:
    static calendarMC *ptrcalendar;//类内声明的静态指针
    static calendarMC *getinstance(){//单例化，希望eves也单例化
        if(nullptr==ptrcalendar){
            ptrcalendar=new calendarMC;
        }
        return ptrcalendar;
    }

    ~calendarMC();

signals:
    void themeChanged();//在更改主题之后，传递更改完成的信号
private slots:
    void on_Modify_clicked();
    void on_countdowndays_clicked();
    void clickedSlot(const QDate date);//单击查看有事件标记的那一天
    //当然，我需要先实现事件标记；暂时决定根据，心情不同使用不同的颜色标记；

private:
    explicit calendarMC(QWidget *parent = nullptr);
    void CreatDataFunc();//创建SQLite数据库
    void CreatTableFunc();//创建sqlite数据表
    void QueryTableFunc();//查询
    QSqlDatabase sqldb;//创建qt和数据库连接
    QSqlQueryModel sqimodel;//存储结果集
    //QList<AEventInfo> eves;//行的列表

public:
    bool AddEvent(AEventInfo newEve);
    bool DeleteEvent(QString name);
    int countNum();
    //QList<AEventInfo> getEventList() const {//找到列表
    //    return eves; // 假设 eventList 是 calendarMC 类中的成员变量，存储了事件列表
    //}
    bool iffind(QString name);
    QList<AEventInfo> getPage(int page,int uicnt);//从数据库中读取列表
    QList<AEventInfo> selectPage(int page,int uint);//从数据库中选择出未发生的数据；

    void ChangeOneDay(const QDate date,const QString mood);//在删除和添加时仅仅改变一天的颜色；
    QDate TToday;//当天的日期
    void ColorDays();//打开窗口时改变许多天的颜色
    virtual void paintEvent(QPaintEvent *e);


public slots:
    void changetheme();
private:
    Ui::calendarMC *ui;


};

#endif // CALENDARMC_H
