#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QPaintEvent>

class MyPushButton : public QPushButton
{
    Q_OBJECT

public:
    explicit MyPushButton(QWidget *parent = 0);
private:
    void paintEvent(QPaintEvent *);
signals:

public slots:

};

#endif // MYPUSHBUTTON_H
