#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMainWindow>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    /**
    * @brief centralWidget
    * @attention 在非ui情况下展示代码的实现
    *
    *QWidget *centralWidget = new QWidget(this);
    *setCentralWidget(centralWidget);
    *
    * 创建一个 QVBoxLayout 布局管理器
    *QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    * 创建一些控件
    *QLabel *label = new QLabel("这是一个示例文本", centralWidget);
    *label->setAlignment(Qt::AlignCenter); // 设置文本居中对齐
    *QPushButton *button = new QPushButton("按钮", centralWidget);
    * 将控件添加到布局管理器
    *layout->addWidget(label);
    *layout->addWidget(button);
    */





    ui->setupUi(this);
    //setCentralWidget(ui->widget);
    ui->calBT->setText("日历");

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_calBT_clicked()
{
    this->cal->show();
    cal->ColorDays();
}


void MainWindow::on_clockBT_clicked()
{
    clockHZJ *AclockWindow=new clockHZJ;
    AclockWindow->show();
}


void MainWindow::on_pushButton_clicked()
{
    dailyMSY *Aday=new dailyMSY;
    Aday->show();
}

