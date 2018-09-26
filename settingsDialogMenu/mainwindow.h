#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "configpolice.h"
#include <QMainWindow>
#include <QSettings>

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
    ConfigPolice *fenetre ;

private slots:
    void afficherConfig();
    void maFont(QFont);
};

#endif // MAINWINDOW_H
