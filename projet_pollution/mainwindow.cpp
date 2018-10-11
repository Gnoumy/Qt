#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QUrl>
#include <QtNetwork>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QDebug>
#include <QString>
#include <QJsonArray>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //api Token:  82740759ffaf747ed45aad29febf758fffd33758
    //Requete  :  https://api.waqi.info/feed/shanghai/?token=82740759ffaf747ed45aad29febf758fffd33758



    QNetworkRequest request;
    QUrl url("https://api.waqi.info/feed/geo:48.866667;2.333333/?token=82740759ffaf747ed45aad29febf758fffd33758");
    //on initialise l'url.
    request.setUrl(url);
    //on lance une requête GET
    QNetworkReply *reponse = networkManager->get(request);  // GET

    connect(networkManager, SIGNAL(finished(QNetworkReply *)), this, SLOT(reponseUrl(QNetworkReply *)));


    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::reponseUrl(QNetworkReply *data)
{

    QJsonDocument jsonDoc = QJsonDocument::fromJson(data->readAll());

    qDebug()<<jsonDoc.object().value("data").toObject().toVariantMap()["aqi"].toString();
    qDebug()<<jsonDoc.object().value("data").toObject().toVariantMap()["city"].toMap()["name"].toString();

    ui->lineEdit_ville->insert(jsonDoc.object().value("data").toObject().toVariantMap()["city"].toMap()["name"].toString());
    ui->lcdNumber->display(jsonDoc.object().value("data").toObject().toVariantMap()["aqi"].toString());

}
