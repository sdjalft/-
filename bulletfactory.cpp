#include "bulletfactory.h"
BulletFactory::PlayerBullets BulletFactory::pcreator(uint flag, QGraphicsScene *scene)
{
    PlayerBullets temp;
//    if (flag == 3) {
//        QPixmaps t;
//        t.append(QPixmap(playerbullet0));
//        for (int i = 0; i < 12; i++) {
//            temp.append(new PlayerBullet(0 + 30 * i, PLAYERBULLETSIZE, PLAYERBULLETSIZE, PLAYERBULLETSPEED, t, scene));
//        }
//    }
    if (flag >= 0) {
        QPixmaps t;
        t.append(QPixmap(playerbullet0));
        temp.append(new PlayerBullet(90, PLAYERBULLETSIZE, PLAYERBULLETSIZE, PLAYERBULLETSPEED, t, scene));
    }
    if (flag >= 1) {
        QPixmaps t;
        t.append(QPixmap(playerbullet1));
        for (int i = 0; i < 2; i++) {
            temp.append(new PlayerBullet(80 + 20 * i, PLAYERBULLETSIZE, PLAYERBULLETSIZE, PLAYERBULLETSPEED, t, scene));
        }
    }
    if (flag >= 2) {
        QPixmaps t;
        t.append(QPixmap(playerbullet2));
        for (int i = 0; i < 2; i++) {
            temp.append(new PlayerBullet(40 + 20 * i, PLAYERBULLETSIZE, PLAYERBULLETSIZE, PLAYERBULLETSPEED, t, scene));
        }
        for (int i = 0; i < 2; i++) {
            temp.append(new PlayerBullet(120 + 20 * i, PLAYERBULLETSIZE, PLAYERBULLETSIZE, PLAYERBULLETSPEED, t, scene));
        }
    }
    return temp;
}
 
BulletFactory::EnemyBullets BulletFactory::ecreator(uint flag, QGraphicsScene *scene)
{
    EnemyBullets temp;
    QPixmaps t, t1, t2;
    switch (flag) {
    case 0:
        break;
    case 1:
        t.append(QPixmap(LittleEnemyPlanesbullet0));
        temp.append(new EnemyBullet(90, LittleEnemyPlanesBULLETSIZE1, LittleEnemyPlanesBULLETSIZE1, LittleEnemyPlanesBULLETSPEED1, t, scene));
        break;
    case 2:
        t.append(QPixmap(LittleEnemyPlanesbullet1));
        for (int i = 0; i < 3; i++) {
            temp.append(new EnemyBullet(80 + 10 * i, LittleEnemyPlanesBULLETSIZE2, LittleEnemyPlanesBULLETSIZE2, LittleEnemyPlanesBULLETSPEED2, t, scene));
        }
        break;
    case 3:
        t.append(QPixmap(LittleEnemyPlanesbullet2));
        for (int i = 0; i < 4; i++) {
            temp.append(new EnemyBullet(0 + 90 * i, LittleEnemyPlanesBULLETSIZE3, LittleEnemyPlanesBULLETSIZE3, LittleEnemyPlanesBULLETSPEED3, t, scene));
        }
        break;

    }
    return temp;
}

