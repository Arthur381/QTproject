#ifndef DAILYMSY_H
#define DAILYMSY_H

#include <QWidget>
#include<QSqlDatabase>
#include <QAbstractButton>

namespace Ui {
class dailyMSY;
}

struct BEventInfo
{
    int id;
    QString thingsname;
    int im;
    int em;
};


class dailyMSY : public QWidget
{
    Q_OBJECT

public:
    explicit dailyMSY(QWidget *parent = nullptr);
    static dailyMSY *ptrdailymsy_allin;//类内声明的静态指针

    static dailyMSY *getinstance(){//单例化
        if(nullptr==ptrdailymsy_allin){
            ptrdailymsy_allin=new dailyMSY;
        }
        return ptrdailymsy_allin;
    }

    ~dailyMSY();
    int CountNum();
    bool addOne(BEventInfo info);
    QList<BEventInfo> getPage(int page,int uicnt);//从数据库中读取列表
    QSqlDatabase sqldb;//创建qt和数据库连接

private:
    Ui::dailyMSY *ui;
    void CreatDataFunc();//创建SQLite数据库
    void CreatTableFunc();//创建sqlite数据表


    //QSqlQueryModel sqimodel;//存储结果集

public slots:

private slots:
    void on_iNote_clicked();
    void on_allIn_clicked();
    void on_nine_clicked();
    void on_iAnde_clicked();
    void on_eNoti_clicked();
};


#endif // DAILYMSY_H
