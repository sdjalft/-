#include "maingame.h"
#include "mainwindow.h"
#include "space.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pixmap(":/new/prefix1/background1.jpg");
    QPalette palette=this->palette();
    palette.setBrush(QPalette::Background,QBrush(pixmap));
    this->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    close();
}



void MainWindow::on_pushButton_2_clicked()
{
    hide();
    Space *abc=new Space();
    abc->show();
}
