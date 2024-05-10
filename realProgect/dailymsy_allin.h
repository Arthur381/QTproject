#ifndef DAILYMSY_ALLIN_H
#define DAILYMSY_ALLIN_H

#include <QDialog>

namespace Ui {
class dailymsy_allin;
}

class dailymsy_allin : public QDialog
{
    Q_OBJECT

public:
    explicit dailymsy_allin(QWidget *parent = nullptr);
    ~dailymsy_allin();

private slots:
    void on_missionAdd_clicked();

private:
    void CreatDataFunc();//创建SQLite数据库
    Ui::dailymsy_allin *ui;
};

#endif // DAILYMSY_ALLIN_H
