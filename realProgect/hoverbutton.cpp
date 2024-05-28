#include "hoverbutton.h"
#include <QEvent>
#include"choosetheme.h"
#include <QPushButton>
#include <QApplication>
#include <QEnterEvent>
#include <QPropertyAnimation>
#include <iostream>
#include <QTimer>
#include<QThread>
#include <QEventLoop>
HoverButton::HoverButton(QWidget *parent)//构造函数
    : QPushButton(parent)
{
    setFixedSize(100, 50);
    installEventFilter(this);//安装过滤器

}

bool HoverButton::eventFilter(QObject *obj, QEvent *event)//手动添加过滤器
{
    if (obj == this) {
        if (event->type() == QEvent::Enter) {
            //std::cout << "entered!" << std::endl;
            animateSize(QSize(200, 100));
        } else if (event->type() == QEvent::Leave) {
            animateSize(QSize(140, 70));
        }
    }
    return QPushButton::eventFilter(obj, event);
}


void HoverButton::animateSize(QSize size)
{
    //std::cout << "Change!" << std::endl;  // 调试输出
    QSize newSize = size;
    // 获取当前几何位置
    QRect startRect =geometry();
    QPoint center = startRect.center();
    QRect endRect(center.x() - newSize.width() / 2,
                  center.y() - newSize.height() / 2,
                  newSize.width(),
                  newSize.height());

    //qDebug() << "Start Rect: " << startRect << " End Rect: " << endRect;  // 调试输出

    // 创建动画对象
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    // 设置动画持续时间
    animation->setDuration(400);
    // 设置起始值
    animation->setStartValue(startRect);
    // 设置结束值
    animation->setEndValue(endRect);
    // 启动动画，并在结束后自动删除
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

