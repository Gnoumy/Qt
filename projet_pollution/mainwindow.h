#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkReply>

#include "pollution_widget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QNetworkAccessManager *networkManager = new QNetworkAccessManager(this);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void reponseUrl(QNetworkReply *data);
};

#endif // MAINWINDOW_H
