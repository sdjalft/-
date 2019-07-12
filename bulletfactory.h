#ifndef BULLETFACTORY_H
#define BULLETFACTORY_H
 
#include "playerbullet.h"
#include "enemybullet.h"
 
class BulletFactory
{
public:
    typedef QList<PlayerBullet*> PlayerBullets;
    typedef QList<EnemyBullet*> EnemyBullets;
    static PlayerBullets pcreator(uint flag, QGraphicsScene *scene);
    static EnemyBullets ecreator(uint flag, QGraphicsScene *scene);
};
 
#endif // BULLETFACTORY_H

