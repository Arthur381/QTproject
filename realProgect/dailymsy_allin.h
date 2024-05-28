#ifndef DAILYMSY_ALLIN_H
#define DAILYMSY_ALLIN_H

#include <QDialog>
#include<QList>
#include <QSqlDatabase>//用于连接，创建数据库
#include <QSqlError>
#include <QSqlQuery>//专用于DML（数据操纵语言），DDL（数据定义语言）
#include <QSqlQueryModel>
#include <QTableWidget>
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

    ~dailymsy_allin();


public slots:
    void changetheme();
private slots:
    void on_missionAdd_clicked();

    void on_delectAll_clicked();

    void on_nextRow_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_imNum_textChanged(const QString &arg1);

    void on_emNum_textChanged(const QString &arg1);

    void on_workTable_itemClicked(QTableWidgetItem *item);

    void on_deleteMission_clicked();

private:



private:
    Ui::dailymsy_allin *ui;
};

#endif // DAILYMSY_ALLIN_H
