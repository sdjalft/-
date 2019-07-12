#ifndef LITTLEENEMYPLANE_H
#define LITTLEENEMYPLANE_H

#include "enemyplane.h"
#include "randomizer.h"

class LittleEnemyPlane:public EnemyPlane
{
public:
    LittleEnemyPlane(double angle,double blood,double width,double height,double speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent = 0);
    ~LittleEnemyPlane();
    void advance(int);
    void doCollide();
    void fall();
    void shoot();
};

#endif
