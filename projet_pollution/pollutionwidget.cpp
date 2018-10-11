#include "pollutionwidget.h"
#include "ui_pollutionwidget.h"

#include <QtNetwork>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QUrl>
#include <QJsonDocument>
#include <QDebug>
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>

pollutionWidget::pollutionWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pollutionWidget)
{
    ui->setupUi(this);

    //api Token:  82740759ffaf747ed45aad29febf758fffd33758
    //Requete  :  https://api.waqi.info/feed/shanghai/?token=82740759ffaf747ed45aad29febf758fffd33758

    QNetworkRequest request;
    QUrl url("https://api.waqi.info/feed/geo:48.866667;2.333333/?token=82740759ffaf747ed45aad29febf758fffd33758");

    //on initialise l'url.
    request.setUrl(url);
    //on lance une requête GET
    networkManager->get(request);
    connect(networkManager, SIGNAL(finished(QNetworkReply *)), this, SLOT(reponseUrl(QNetworkReply *)));
//    connect(networkManager, SIGNAL(finished(QNetworkReply *)), this, SLOT(affichageGraphique()));
//    ui->stackedWidget->setCurrentIndex(0);


}

pollutionWidget::~pollutionWidget()
{
    delete ui;
}

void pollutionWidget::reponseUrl(QNetworkReply *data)
{



    QJsonDocument jsonDoc = QJsonDocument::fromJson(data->readAll());
    ui->label_affichageIndicePollution->setText(jsonDoc.object().value("data").toObject().toVariantMap()["aqi"].toString());
    ui->label_affichageStationMeteo->setText(jsonDoc.object().value("data").toObject().toVariantMap()["city"].toMap()["name"].toString());
}

void pollutionWidget::affichageGraphique()
{
//    ui->stackedWidget->setCurrentIndex(1);
    QPixmap pixmap(500,500);
    pixmap.fill(QColor("black"));
    QPainter painter(&pixmap);
    QPen pen;
    pen.setColor(Qt::red);
    painter.setPen(pen);

//    painter.drawLine(0,0,100,100);
    QRectF rectangle(40.0, 80.0, 240.0, 240.0);
    int startAngle = 30 * 16;
    int spanAngle = 120 * 16;
    painter.drawLine(0,0,500,500);
    painter.drawArc(rectangle, startAngle, spanAngle);



    ui->label->setPixmap(pixmap);
}
