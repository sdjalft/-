#include "littleenemyplane.h"

LittleEnemyPlane::LittleEnemyPlane(double angle, double blood, double width, double higth, double speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent):
    EnemyPlane(angle, blood, width, higth, speed, pixs, scene, parent) {

}

LittleEnemyPlane::~LittleEnemyPlane() {
    scores+=50;
}

void LittleEnemyPlane::advance(int)
{
    m_step++;
    if (m_step % LittleEnemyPlanesSHOOTSTEP == 0) {
        shoot();
    }
    if (m_step == LittleEnemyPlanesSHOOTSTEP * 10) m_step = 0;
    QPointF pos = scenePos();
    if (!checkPos(DOWN) || !checkPos(LEFT) || !checkPos(RIGHT)) {
        posLost();
        return;
    }
    if (!checkPos(UP)) {
        y_speed = -y_speed;
    }
    pos.ry() += y_speed;
    pos.rx() += x_speed;
    setPos(pos);
    doCollide();
}

void LittleEnemyPlane::doCollide()
{
    foreach (QGraphicsItem *t, collidingItems()) {
        if (t->type() != UnFlyer::TYPE) {
            Flyer *flyer = static_cast<Flyer*>(t);
            if (flyer->name() == PLAYERBULLETNAME) {
                flyer->fall();
                strike();
                if (m_blood == 0) fall();
            }
            if (flyer->name() == BOMBNAME) {
                m_blood = 0;
                fall();
            }
        }
    }
}

void LittleEnemyPlane::fall()
{
    setVisible(false);
    deleteLater();
    emit sig_score(LittleEnemyPlanesSCORE);
}

void LittleEnemyPlane::shoot()
{
    int temp = Randomizer::creat(3);
    if (temp == 0) temp = 3;
    BulletFactory::EnemyBullets bullets = BulletFactory::ecreator(temp, scene());
    QPointF pos = scenePos();
    pos.rx() += m_width - LittleEnemyPlanesBULLETSIZE1;
    pos.ry() += m_height;
    foreach (EnemyBullet* bullet, bullets) {
        bullet->setPos(pos);
    }
}
