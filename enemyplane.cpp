#include "enemyplane.h"
#include "global.h"

EnemyPlane::EnemyPlane(double angle, double blood, double width, double hight, double speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent)
    :plane(blood,width,hight,speed,pixs,scene,parent), m_angle(angle),
    x_speed(::cos(m_angle / ROTATE) * m_speed),
    y_speed(::sin(m_angle / ROTATE) * m_speed) {

}

EnemyPlane::~EnemyPlane() {

}

QRectF EnemyPlane::boundingRect() const
{
    return m_pixs.at(0).rect();
}

QPainterPath EnemyPlane::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void EnemyPlane::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(0, 0, m_pixs.at(m_pixpos));
}

int EnemyPlane::name() const
{
    return ENEMYPLANENAME;
}

void EnemyPlane::posLost()
{
    setVisible(false);
    deleteLater();
}

void EnemyPlane::strike() {
    m_blood--;
}
