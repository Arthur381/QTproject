#ifndef HOVERBUTTON_H
#define HOVERBUTTON_H

#include <QPushButton>
#include <QPropertyAnimation>

class HoverButton : public QPushButton
{
    Q_OBJECT

public:
    explicit HoverButton(QWidget *parent = nullptr);


protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
    void animateSize(QSize size);

};


#endif // HOVERBUTTON_H
