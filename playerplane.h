#ifndef PLAYERPLANE_H
#define PLAYERPLANE_H

#include "plane.h"
#include "bulletfactory.h"
#include <QKeyEvent>
#include <QRectF>

class PLAYERPLANE:public plane
{
public:
    PLAYERPLANE(double blood,double width,double hight,double speed,const QPixmaps &pixs,QGraphicsScene *scene, QGraphicsItem *parent=0);
    QRectF boundingRect() const;
    ~PLAYERPLANE();
    QPainterPath shape() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
    int name() const;
    void advance(int);
    void posLost();
    void doCollide();
    void fall();
    void strike();
    void shoot();
public:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
private:
    int m_bullet;
    bool W,A,S,D;
};



#endif // PLAYERPLANE_H
