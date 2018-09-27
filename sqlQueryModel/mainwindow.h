#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QString>
#include <QMainWindow>
#include <QSqlQueryModel>
#include <QModelIndex>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QSqlQueryModel *model = new QSqlQueryModel(this);
private slots:
    void afficherVilles(QString);
    void afficherInfos(QModelIndex);
};

#endif // MAINWINDOW_H
