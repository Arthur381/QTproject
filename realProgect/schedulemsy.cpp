#include "schedulemsy.h"
#include "ui_schedulemsy.h"
#include "coursemsy.h"

#include <QPainter>
#include <QStyleOption>

scheduleMSY::scheduleMSY(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::scheduleMSY)
{
    ui->setupUi(this);
    ui->courseTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->courseTable->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止对表格内容进行修改
    ui->courseTable->setColumnWidth(0,100);
    ui->courseTable->setColumnWidth(1,79);
    ui->courseTable->setColumnWidth(2,79);
    ui->courseTable->setColumnWidth(3,79);
    ui->courseTable->setColumnWidth(4,79);
    ui->courseTable->setColumnWidth(5,79);
    ui->courseTable->setColumnWidth(6,79);
    ui->courseTable->setColumnWidth(7,79);
    ui->courseTable->setRowHeight(0,80);
    ui->courseTable->setRowHeight(1,80);
    ui->courseTable->setRowHeight(2,80);
    ui->courseTable->setRowHeight(3,80);
    ui->courseTable->setRowHeight(4,80);
    ui->courseTable->setRowHeight(5,80);
    ui->courseTable->setAlternatingRowColors(true);

    Print();
}

scheduleMSY::~scheduleMSY()
{
    delete ui;
}

void scheduleMSY::Print(){
    coursemsy* m_coursemsy=coursemsy::getinstance();
    auto cnt = m_coursemsy->countnum();
    QList<CEventInfo>listeve=m_coursemsy->getPage(0,cnt);
    ui->courseTable->clearContents();
    ui->courseTable->setRowCount(5);
    for(int i=0;i<listeve.size();i++){
        ui->courseTable->setItem(listeve[i].row-1,listeve[i].col-1,new QTableWidgetItem(listeve[i].courseName));
    }
}
/**
 *
 * @arg 课程表暂时先不设置背景
 *
 *
 *
 */
