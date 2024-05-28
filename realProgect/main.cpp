#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include<QPixmap>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "realProgect_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    MainWindow w;
    w.setStyleSheet(
        "QMainWindow {"
        "    background-image: url(:/background/pku_mainbg.jpg);" // 设置背景图片
        "    background-position: center;" // 将图片放置在中心
        "    background-repeat: no-repeat;" // 禁止图片重复
        "    background-size: 100% 100%;" // 使图片拉伸以适应窗口大小
        "}"
        );
    //w.resize(900, 600);

    // 加载背景图片
    w.show();
    return a.exec();
}
