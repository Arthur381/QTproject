#ifndef CHOOSETHEME_H
#define CHOOSETHEME_H

#include <QWidget>

namespace Ui {
class ChooseTheme;
}

class ChooseTheme : public QWidget
{
    Q_OBJECT

public:
    explicit ChooseTheme(QWidget *parent = nullptr);
    ~ChooseTheme();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ChooseTheme *ui;
};

#endif // CHOOSETHEME_H
