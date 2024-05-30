#include "intro.h"
#include "ui_intro.h"

Intro::Intro(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Intro)
{
    ui->setupUi(this);
    setWindowTitle(QStringLiteral("介绍一下PKU自律指南吧~"));
     setWindowIcon(QIcon(":/icon/changetheme.png"));
}

Intro::~Intro()
{
    delete ui;
}
