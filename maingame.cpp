#include "maingame.h"
#include "ui_maingame.h"
#include <QTimer>
#include <QPainter>
#include <QPixmap>
#include <QLabel>
#include <QDebug>

control::control(QWidget *parent) : QGraphicsView(parent){
    m_scene = new QGraphicsScene;
    m_scene->setSceneRect(0, 0, SCENEWIDTH, SCENEHEIGHT);
    setScene(m_scene);
    setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    m_timer = new QTimer;
    connect(m_timer, SIGNAL(timeout()), this, SLOT(slt_updata()));
    init();
}
void control::init(){
    QPixmaps t;
    t.append(QPixmap(playerplane));
    m_player = new PLAYERPLANE(PLAYERPLANEBLOOD, PLAYERPLANESIZE, PLAYERPLANESIZE, PLAYERPLANESPEED, t, m_scene);
    m_player->setFocus();

}
maingame::maingame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::maingame)
{
    ui->setupUi(this);
    picLabel = new QLabel(this);
    picLabel->setFixedSize(600,9000);
    QTimer *timer = new QTimer(this);
    timer->stop();
    timer->setInterval(100);
    connect(timer, SIGNAL(timeout()), this, SLOT(imageup()));
    timer->start(0);
}

void maingame::imageup(){
    ya+=1;
    picLabel->move(picLabel->x(),ya);
}

maingame::~maingame()
{
    delete ui;
}

void maingame::paintEvent(QPaintEvent *){
//    QPainter painter(this);
//    QPixmap pix;
//    pix.load(":/new/prefix1/mission1.png");
//    painter.drawPixmap(picLabel->x(),ya,picLabel->width(),picLabel->height(),pix);
}

void control::slt_updata()
{
    m_scene->advance();
}
