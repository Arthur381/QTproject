#ifndef DAILYMSY4_H
#define DAILYMSY4_H

#include <QDialog>
#include<QList>
#include <QSqlDatabase>//用于连接，创建数据库
#include <QSqlError>
#include <QSqlQuery>//专用于DML（数据操纵语言），DDL（数据定义语言）
#include <QSqlQueryModel>
#include <QtDebug>


namespace Ui {
class dailymsy4;
}

class dailymsy4 : public QDialog
{
    Q_OBJECT

public:
    explicit dailymsy4(QWidget *parent = nullptr);
    ~dailymsy4();
    void Print();
    QSqlDatabase sqldb=QSqlDatabase::addDatabase("QSQLITE");//创建qt和数据库连接

private:
    Ui::dailymsy4 *ui;
};

#endif // DAILYMSY4_H
