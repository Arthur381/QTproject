#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //添加一个注释试一试同步效果
    //
    //
    //在本地改变之后再次上传
    MainWindow w;
    w.show();
    return a.exec();
}
