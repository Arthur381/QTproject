#ifndef DAILYMSY2_H
#define DAILYMSY2_H

#include <QDialog>
#include<QList>
#include <QSqlDatabase>//用于连接，创建数据库
#include <QSqlError>
#include <QSqlQuery>//专用于DML（数据操纵语言），DDL（数据定义语言）
#include <QSqlQueryModel>
#include <QtDebug>

namespace Ui {
class dailymsy2;
}

class dailymsy2 : public QDialog
{
    Q_OBJECT

public:
    explicit dailymsy2(QWidget *parent = nullptr);
    ~dailymsy2();
    void Print();
    void modifyDatabase();
    //QSqlDatabase sqldb=QSqlDatabase::addDatabase("QSQLITE");//创建qt和数据库连接

private:
    Ui::dailymsy2 *ui;
};

#endif // DAILYMSY2_H
