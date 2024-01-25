#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPaintEvent>
#include <QPainter>
#include <QPaintDevice>
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ptrAddPackage = new AddPackage();
    ptrFindTourist = new FindTourist();
    ptrRegisterTourist = new RegisterTourist();
    ptrFindPackage = new FindPackage();

}

void MainWindow::paintEvent(QPaintEvent *pe)
{
    QPixmap pixmap;
    pixmap.load(":/images/pexels-chevanon-photography-333525.jpg");
    QPainter paint(this);
    int widWidth = this->ui->centralwidget->width();
    int widHeight = this->ui->centralwidget->height();
    pixmap = pixmap.scaled(widWidth, widHeight);
    paint.drawPixmap(0, 0, pixmap);
    QWidget::paintEvent(pe);
}
MainWindow::~MainWindow()
{
    delete ptrAddPackage;
    delete ptrFindTourist;
    delete ptrRegisterTourist;
    delete ptrFindPackage;
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ptrAddPackage->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    ptrRegisterTourist->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    ptrFindPackage->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    ptrFindTourist->show();
}

