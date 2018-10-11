#include "mypushbutton.h"
#include <QPushButton>
#include <QPainter>
#include <QPaintEvent>
MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
{

}

void MyPushButton::paintEvent(QPaintEvent *event)
{
    QPushButton::paintEvent(event);
    QPainter painter(this);
    painter.drawLine(0,0,100,100);
}
