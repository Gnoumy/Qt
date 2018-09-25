#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QFile>
#include "apropos.h"

#include <QMainWindow>

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
    aPropos *fenetre = new aPropos(this);
private slots:
    void ouvrirFichier();
    void aide();
    void listeFichier();
};

#endif // MAINWINDOW_H
