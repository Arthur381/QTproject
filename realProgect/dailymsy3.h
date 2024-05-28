#ifndef DAILYMSY3_H
#define DAILYMSY3_H

#include <QDialog>
#include<QList>
#include <QSqlDatabase>//用于连接，创建数据库
#include <QSqlError>
#include <QSqlQuery>//专用于DML（数据操纵语言），DDL（数据定义语言）
#include <QSqlQueryModel>
#include <QtDebug>


namespace Ui {
class dailymsy3;
}

class dailymsy3 : public QDialog
{
    Q_OBJECT

public:
    explicit dailymsy3(QWidget *parent = nullptr);
    ~dailymsy3();
    void modifyDatabase();

public slots:
    void changetheme();


private:
    Ui::dailymsy3 *ui;
};

#endif // DAILYMSY3_H
