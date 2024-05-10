#ifndef CALENDARMC_H
#define CALENDARMC_H

#include <QWidget>
#include <QSqlDatabase>//用于连接，创建数据库
#include <QSqlError>
#include <QSqlQuery>//专用于DML（数据操纵语言），DDL（数据定义语言）
#include <QSqlQueryModel>
#include <QtDebug>
#include<QMessageBox>

namespace Ui {
class calendarMC;
}

class calendarMC : public QWidget
{
    Q_OBJECT

public:
    explicit calendarMC(QWidget *parent = nullptr);
    ~calendarMC();

private slots:
    void on_Modify_clicked();

    void on_countdowndays_clicked();


private:
    void CreatDataFunc();//创建SQLite数据库
    void CreatTableFunc();//创建sqlite数据表

    QSqlDatabase sqldb;//创建qt和数据库连接
    QSqlQueryModel sqimodel;//存储结果集

private:
    Ui::calendarMC *ui;
};

#endif // CALENDARMC_H
