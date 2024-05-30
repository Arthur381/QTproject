#include "schedulemsy.h"
#include "ui_schedulemsy.h"
#include "coursemsy.h"

#include <QPainter>
#include <QStyleOption>

scheduleMSY::scheduleMSY(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::scheduleMSY)
{
    setWindowTitle(QStringLiteral("请查收你的课程表~"));
     setWindowIcon(QIcon(":/icon/coursemsy2.png"));
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
    ui->courseTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    Print();
    colored();

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
void scheduleMSY::colored(){
    // 遍历表格并设置背景颜色


    QMap<int, QColor> courseColors = {
        {0, QColor(255, 182, 193)}, // Light Pink
        {1, QColor(173, 216, 230)}, // Light Blue
        {2, QColor(144, 238, 144)}, // Light Green
        {3, QColor(255, 255, 102)}, // Light Yellow
        {4, QColor(255, 192, 203)}, // Pink
        {5, QColor(135, 206, 250)}, // Light Sky Blue
        {6, QColor(255, 222, 173)}, // Navajo White
        {7, QColor(152, 251, 152)}, // Pale Green
        {8, QColor(255, 192, 203)}, // Pink
        {9, QColor(135, 206, 250)}, // Light Sky Blue
        {10, QColor(255, 222, 173)}, // Navajo White
        {11, QColor(152, 251, 152)}, // Pale Green
        {12, QColor(255, 192, 203)}, // Pink
        {13, QColor(135, 206, 250)}, // Light Sky Blue
        {14, QColor(255, 222, 173)}, // Navajo White
        {15, QColor(152, 251, 152)}, // Pale Green
        // 更多课程及颜色
    };
    QMap<QString,int> searchcourses={};

    int current_course_number=0;
    for (int row = 0; row < ui->courseTable->rowCount(); ++row) {
        for (int col = 0; col < ui->courseTable->columnCount(); ++col) {
            QTableWidgetItem *item = ui->courseTable->item(row, col);

            if(item){
                item->setTextAlignment(Qt::AlignCenter);
                if (searchcourses.contains(item->text())) {//这是一个第一次出现的课
                    item->setBackground(courseColors[searchcourses[item->text()]]);
                }
                else {//这个课已经出现过
                    searchcourses[item->text()]=current_course_number;
                    current_course_number++;
                    item->setBackground(courseColors[searchcourses[item->text()]]);


                }
            }
        }
    }
    qDebug()<<current_course_number;
}
