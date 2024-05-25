#ifndef COURSEMSY_H
#define COURSEMSY_H

#include <QDialog>
#include <QAbstractButton>
#include<QList>
#include <QSqlDatabase>//用于连接，创建数据库
#include <QSqlError>
#include <QSqlQuery>//专用于DML（数据操纵语言），DDL（数据定义语言）
#include <QSqlQueryModel>
#include <QtDebug>
#include<QMessageBox>

namespace Ui {
class coursemsy;
}

struct CEventInfo
{
    int col;//周几
    int row;//第几节
    QString courseName;
};

class coursemsy : public QDialog
{
    Q_OBJECT

public:
    explicit coursemsy(QWidget *parent = nullptr);
    static coursemsy *ptrcoursemsy;//类内声明的静态指针

    static coursemsy *getinstance(){//单例化
        if(nullptr==ptrcoursemsy){
            ptrcoursemsy=new coursemsy;
        }
        return ptrcoursemsy;
    }
    int countnum();

    QList<CEventInfo> getPage(int page,int uicnt);//从数据库中读取列表
    QSqlDatabase sqldb;//创建qt和数据库连接

    ~coursemsy();

public:
    bool addone(CEventInfo info);
    bool delone(CEventInfo info);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_delCourse_clicked();

private:
    Ui::coursemsy *ui;
    void CreatDataFunc();//创建SQLite数据库
    void CreatTableFunc();//创建sqlite数据表

};

#endif // COURSEMSY_H
