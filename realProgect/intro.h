#ifndef INTRO_H
#define INTRO_H

#include <QWidget>

namespace Ui {
class Intro;
}

class Intro : public QWidget
{
    Q_OBJECT

public:
    explicit Intro(QWidget *parent = nullptr);
    int CURRENT_PAGE=0;
    void Draw(int curret_page);
    void paintEvent(QPaintEvent *e);
    ~Intro();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Intro *ui;
};

#endif // INTRO_H
