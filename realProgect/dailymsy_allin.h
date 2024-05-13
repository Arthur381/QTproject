#ifndef DAILYMSY_ALLIN_H
#define DAILYMSY_ALLIN_H

#include <QDialog>
#include<QList>
#include <QSqlDatabase>//用于连接，创建数据库
#include <QSqlError>
#include <QSqlQuery>//专用于DML（数据操纵语言），DDL（数据定义语言）
#include <QSqlQueryModel>
#include <QtDebug>

namespace Ui {
class dailymsy_allin;
}

struct BEventInfo
{
    QString id;
    QString thingsname;
    QString im;
    QString em;
};

class dailymsy_allin : public QDialog
{
    Q_OBJECT

public:
    explicit dailymsy_allin(QWidget *parent = nullptr);
    static dailymsy_allin *ptrdailymsy_allin;//类内声明的静态指针

    static dailymsy_allin *getinstance(){//单例化
        if(nullptr==ptrdailymsy_allin){
            ptrdailymsy_allin=new dailymsy_allin;
        }
        return ptrdailymsy_allin;
    }
    QList<BEventInfo> getPage(int page,int uicnt);//从数据库中读取列表
    ~dailymsy_allin();


private slots:
    void on_missionAdd_clicked();

private:
    void CreatDataFunc();//创建SQLite数据库
    void CreatTableFunc();//创建sqlite数据表

    QSqlDatabase sqldb;//创建qt和数据库连接
    QSqlQueryModel sqimodel;//存储结果集


private:
    Ui::dailymsy_allin *ui;
};

#endif // DAILYMSY_ALLIN_H
