#include "playerplane.h"
#include "randomizer.h"
PLAYERPLANE::PLAYERPLANE(qreal blood, qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent):
    plane(blood, w, h, speed, pixs, scene, parent),
     m_bullet(Randomizer::creat(3)), W(false), A(false), S(false), D(false) {
    this->grabKeyboard();
    setPos((scene->width() - m_width)/2, scene->height() - m_height);
    setFlag(QGraphicsItem::ItemIsFocusable);
}

PLAYERPLANE::~PLAYERPLANE() {

}

QRectF PLAYERPLANE::boundingRect() const
{
    return m_pixs.at(0).rect();
}

QPainterPath PLAYERPLANE::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void PLAYERPLANE::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(0, 0, m_pixs.at(m_pixpos));
}

int PLAYERPLANE::name() const {
    return PLAYERPLANENAME;
}

void PLAYERPLANE::advance(int) {
    if (W && checkPos(UP)) {
        m_pixpos = 0;
        QPointF pos = scenePos();
        pos.ry() -= m_speed;
        setPos(pos);
    }
    if (S && checkPos(DOWN)) {
        m_pixpos = 1;
        QPointF pos = scenePos();
        pos.ry() += m_speed;
        setPos(pos);
    }
    if (A && checkPos(LEFT)) {
        m_pixpos = 2;
        QPointF pos = scenePos();
        pos.rx() -= m_speed;
        setPos(pos);
    }
    if (D && checkPos(RIGHT)) {
        m_pixpos = 3;
        QPointF pos = scenePos();
        pos.rx() += m_speed;
        setPos(pos);
    }
    if (!W && !S && !A && !D) m_pixpos = 0;
    doCollide();
}

void PLAYERPLANE::posLost() {

}

void PLAYERPLANE::doCollide()
{
    foreach (QGraphicsItem *t, collidingItems()) {
        if (t->type() != UnFlyer::TYPE) {
            Flyer *flyer = static_cast<Flyer*>(t);
            switch (flyer->name()) {
            case ENEMYPLANENAME:
                strike();
                if (m_blood == 0) {
                    m_bullet = 0;
                    fall();
                }
                break;
            case ENEMYBULLETNAME:
                            flyer->fall();
                            strike();
                            if (m_blood == 0) {
                                m_bullet = 0;
                                fall();
                            }
                            break;
            }
        }

    }
}

void PLAYERPLANE::fall()
{
    setFlag(QGraphicsItem::ItemIsMovable, false);
    setFlag(QGraphicsItem::ItemIsFocusScope, false);
    setVisible(false);
    deleteLater();
    emit sig_fall();
}

void PLAYERPLANE::strike() {
    m_blood--;
    emit sig_blood(m_blood);
}

void PLAYERPLANE::shoot()
{
    BulletFactory::PlayerBullets bullets = BulletFactory::pcreator(m_bullet, scene());
    QPointF pos = scenePos();
    pos.rx() += m_width / 2 - PLAYERBULLETSIZE / 2;
    foreach (PlayerBullet* bullet, bullets) {
        bullet->setPos(pos);
    }
}

void PLAYERPLANE::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_W:
        event->accept();
        W = true;
        break;
    case Qt::Key_S:
        event->accept();
        S = true;
        break;
    case Qt::Key_A:
        event->accept();
        A = true;
        break;
    case Qt::Key_D:
        event->accept();
        D = true;
        break;
    case Qt::Key_J:
        shoot();
        break;
    default:
        event->ignore();
        break;
    }
}

void PLAYERPLANE::keyReleaseEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_W:
        event->accept();
        W = false;
        break;
    case Qt::Key_S:
        event->accept();
        S = false;
        break;
    case Qt::Key_A:
        event->accept();
        A = false;
        break;
    case Qt::Key_D:
        event->accept();
        D = false;
        break;
    default:
        event->ignore();
        break;
    }
}
