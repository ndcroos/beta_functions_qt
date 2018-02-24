#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void makePlot();
    void makePlot2(const double a, const double b);
    void on_pushButton_clicked();

    double readParam(QLineEdit *lineEdit);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
