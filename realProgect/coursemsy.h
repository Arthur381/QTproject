#ifndef COURSEMSY_H
#define COURSEMSY_H

#include <QDialog>

namespace Ui {
class coursemsy;
}

class coursemsy : public QDialog
{
    Q_OBJECT

public:
    explicit coursemsy(QWidget *parent = nullptr);
    ~coursemsy();

private slots:
    void on_pushButton_clicked();

private:
    Ui::coursemsy *ui;
};

#endif // COURSEMSY_H
