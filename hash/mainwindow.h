#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QHash>

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
    QHash<QString, int> personne;
private slots:
    void afficherAge();
};

#endif // MAINWINDOW_H
