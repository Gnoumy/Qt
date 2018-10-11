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


    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


