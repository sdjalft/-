#include "gameover.h"
#include "ui_gameover.h"
#include "global.h"


gameover::gameover(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gameover)
{
    ui->setupUi(this);
//    QLabel sdj;
//    QFont sdj1;
//    sdj.setText("100");
//    sdj1.setPointSize(30);
//    sdj1.setFamily("汉仪霹雳体简");
//    sdj.setFont(sdj1);
//    QPalette sdj2;
//    sdj2.setColor(QPalette::WindowText,Qt::yellow);
//    sdj.setPalette(sdj2);
//    sdj.setGeometry(QRect(20, 20, 150, 30));
    QPixmap pixmap(":/new/prefix1/background1.jpg");
    QPalette palette=this->palette();
    palette.setBrush(QPalette::Background,QBrush(pixmap));
    this->setPalette(palette);
    ui->label_2->setText(QString::number(scores));
}

gameover::~gameover()
{
    delete ui;
}

void gameover::on_pushButton_clicked()
{
    hide();
    Space *abc=new Space();
    abc->show();
}

