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
    ui->courseTable->setColumnWidth(0,50);
    ui->courseTable->setColumnWidth(1,50);
    ui->courseTable->setColumnWidth(2,50);
    ui->courseTable->setColumnWidth(3,50);
    ui->courseTable->setColumnWidth(4,50);
    ui->courseTable->setColumnWidth(5,50);
    ui->courseTable->setColumnWidth(6,50);
    ui->courseTable->setColumnWidth(7,50);
    ui->courseTable->setRowHeight(0,20);
    ui->courseTable->setRowHeight(1,20);
    ui->courseTable->setRowHeight(2,20);
    ui->courseTable->setRowHeight(3,20);
    ui->courseTable->setRowHeight(4,20);
    ui->courseTable->setRowHeight(5,20);
    ui->courseTable->setRowHeight(6,20);
    ui->courseTable->setRowHeight(7,20);
    ui->courseTable->setRowHeight(8,20);
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
    ui->courseTable->setRowCount(12);
    for(int i=0;i<listeve.size();i++){
        ui->courseTable->setItem(listeve[i].row-1,listeve[i].col-1,new QTableWidgetItem(listeve[i].courseName));
    }
}
