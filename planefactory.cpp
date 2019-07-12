#include "planefactory.h"


PlaneFactory::LittleEnemyPlanes PlaneFactory::fcreator(uint flag, QGraphicsScene *scene)
{
     LittleEnemyPlanes temp;
    for (uint i = 0; i < flag; i++) {
        QPixmaps t;
        int x = Randomizer::creat(5);
        if (x == 1) {t.append(QPixmap(LittleEnemyPlanes1));}
        else if (x == 2) {t.append(QPixmap(LittleEnemyPlanes2));}
        else if (x == 3) {t.append(QPixmap(LittleEnemyPlanes4));}
        else if (x == 4) {t.append(QPixmap(LittleEnemyPlanes5));}
        else if (x == 0) {t.append(QPixmap(LittleEnemyPlanes3));}
        int angle = Randomizer::creat(180);
        temp.append(new LittleEnemyPlane(angle, LittleEnemyPlanesHP, LittleEnemyPlanesSIZE, LittleEnemyPlanesSIZE, LittleEnemyPlanesSPEED, t, scene));
    }
    return temp;
}
