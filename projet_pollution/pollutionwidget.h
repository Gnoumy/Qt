#ifndef POLLUTION_WIDGET_H
#define POLLUTION_WIDGET_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>

namespace Ui {
class pollutionWidget;
}

class pollutionWidget : public QWidget
{
    Q_OBJECT

public:
    explicit pollutionWidget(QWidget *parent = 0);
    QNetworkAccessManager *networkManager = new QNetworkAccessManager(this);
    ~pollutionWidget();

private:
    Ui::pollutionWidget *ui;
private slots:
    void reponseUrl(QNetworkReply *data);
    void affichageGraphique();
};

#endif // POLLUTION_WIDGET_H
