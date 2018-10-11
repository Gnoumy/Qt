#ifndef POLLUTION_WIDGET_H
#define POLLUTION_WIDGET_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>

namespace Ui {
class pollution_widget;
}

class pollution_widget : public QWidget
{
    Q_OBJECT

public:
    explicit pollution_widget(QWidget *parent = 0);
    ~pollution_widget();
    QNetworkAccessManager *networkManager = new QNetworkAccessManager(this);

private:
    Ui::pollution_widget *ui;
    void reponseUrl(QNetworkReply *data);
};

#endif // POLLUTION_WIDGET_H
