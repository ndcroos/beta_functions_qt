#include <iostream>
#include <cmath>
#include <string>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "beta.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui (new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Beta functions");
    //MainWindow::makePlot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::makePlot(){
    // generate some data:
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }
    // create graph and add it to our widget:
    // customPlot is the name used in the ui editor for the Qt widget.
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(-1, 1);
    ui->customPlot->yAxis->setRange(0, 1);


    ui->customPlot->replot();
}

void MainWindow::makePlot2(const double a, const double b){
    // generate some data:
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0; // x goes from 0 to 1. This is called normalization.
      y[i] = x[i]*x[i]; // let's plot a quadratic function

      y[i] = pow(x[i], a)*pow(1-x[i], b);
    }
    // create graph and add it to our widget:
    // customPlot is the name used in the ui editor for the Qt widget.
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(-1, 1);
    ui->customPlot->yAxis->setRange(0, 1);


    ui->customPlot->replot();
}

BetaF::BetaF(void){
    std::cout << "Object is being created." << std::endl;
}

void BetaF::filterUnacceptableValues(const double a, const double b){

    std::cout << "filterUnacceptableValues function called." << std::endl;

    if (a < 0 || b < 0){
        throw std::string("Check that constants are >= 0");
    }
    if (a + b <= 0){
        throw std::string("a + b must be > 0");
    }
    if (a + b > 10){
        throw std::string("a + b must be <= 10");
    }
}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "Clicked on button.";
    double param1 = MainWindow::readParam(ui->lineEdit1);
    double param2 = MainWindow::readParam(ui->lineEdit2);

    BetaF betaF;
    betaF.filterUnacceptableValues(param1, param2);
    MainWindow::makePlot2(param1, param2);
}


double MainWindow::readParam(QLineEdit *lineEdit){
    QString qString = lineEdit->text();
    double param = qString.toDouble();
    return param;
}
