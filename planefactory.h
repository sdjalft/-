#ifndef PLANEFACTORY_H
#define PLANEFACTORY_H

//#include "boss.h"
#include "littleenemyplane.h"
#include "randomizer.h"

class PlaneFactory
{
public:
    typedef QList<LittleEnemyPlane*>  LittleEnemyPlanes;
    static  LittleEnemyPlanes fcreator(uint flag, QGraphicsScene *scene);
};

#endif // PLANEFACTORY_H
