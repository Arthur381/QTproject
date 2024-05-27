#ifndef DAILYMSY5_H
#define DAILYMSY5_H

#include <QDialog>
#include<QList>
#include <QSqlDatabase>//用于连接，创建数据库
#include <QSqlError>
#include <QSqlQuery>//专用于DML（数据操纵语言），DDL（数据定义语言）
#include <QSqlQueryModel>
#include <QtDebug>


namespace Ui {
class dailymsy5;
}

class dailymsy5 : public QDialog
{
    Q_OBJECT

public:
    explicit dailymsy5(QWidget *parent = nullptr);
    ~dailymsy5();
    void modifyDatabase();

private:
    Ui::dailymsy5 *ui;
};

#endif // DAILYMSY5_H
