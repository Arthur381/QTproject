#ifndef SCHEDULEMSY_H
#define SCHEDULEMSY_H

#include <QWidget>
#include "coursemsy.h"
//把course中的表引进到这里面，将来在tablewidgt中显示
#include <QAbstractButton>
#include<QList>
#include <QSqlDatabase>//用于连接，创建数据库
#include <QSqlError>
#include <QSqlQuery>//专用于DML（数据操纵语言），DDL（数据定义语言）
#include <QSqlQueryModel>
#include <QtDebug>
#include<QMessageBox>

namespace Ui {
class scheduleMSY;
}

class scheduleMSY : public QWidget
{
    Q_OBJECT

public:
    explicit scheduleMSY(QWidget *parent = nullptr);

    void Print();
    ~scheduleMSY();

private:
    Ui::scheduleMSY *ui;
};

#endif // SCHEDULEMSY_H
