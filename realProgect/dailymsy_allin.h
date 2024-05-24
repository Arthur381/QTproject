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


class dailymsy_allin : public QDialog
{
    Q_OBJECT

public:
    explicit dailymsy_allin(QWidget *parent = nullptr);


    void PrintP();

    int CountNum();

    void on_workTable_cellClicked(int row, int column);
    ~dailymsy_allin();


private slots:
    void on_missionAdd_clicked();

    void on_pushButton_clicked();

private:



private:
    Ui::dailymsy_allin *ui;
};

#endif // DAILYMSY_ALLIN_H
