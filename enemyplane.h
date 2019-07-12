#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H

#define ROTATE 57.26

#include "plane.h"
#include "bulletfactory.h"

class EnemyPlane:public plane
{
public:
    EnemyPlane(double angle, double blood, double width, double height, double speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent=0);
    ~EnemyPlane();
        QRectF boundingRect() const;
        QPainterPath shape() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        int name() const;
        void posLost();
        void strike();
    protected:
        double m_angle, x_speed, y_speed;
};

#endif
