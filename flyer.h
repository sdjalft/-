#ifndef FLYER_H
#define FLYER_H

#include <QtWidgets>
#include "global.h"

typedef  enum{UP,DOWN,LEFT,RIGHT} CHECK_FLAG;
typedef  QList<QPixmap> QPixmaps;

class Flyer: public QGraphicsObject
{
    Q_OBJECT
public:
    Flyer(double width,double height,double speed,const QPixmaps &pixs,QGraphicsScene *scene,QGraphicsItem *parent=0)
        :QGraphicsObject(parent),m_width(width),m_height(height),m_speed(speed),m_pixpos(0),m_step(0){
        for (int i=0;i<pixs.size();i++) {
            QPixmap temp(pixs.at(i)),t;
            t=temp.scaled(m_width,m_height,Qt::KeepAspectRatioByExpanding);
            m_pixs.append(t);
        }
        scene->addItem(this);
    }
    virtual ~Flyer(){}
    virtual int name() const=0;
    virtual void posLost()=0;
    virtual void doCollide()=0;
    virtual void fall()=0;
    bool checkPos(CHECK_FLAG flag)
    {
        bool ok=false;
        switch (flag){
            case UP:
                if (scenePos().ry()>=-m_height)
                    ok=true;
                break;
            case DOWN:
                if(scenePos().ry()<=SCENEHEIGHT)
                    ok=true;
                break;
            case LEFT:
                if(scenePos().rx()>=-m_width)
                    ok=true;
                break;
            case RIGHT:
                if(scenePos().rx()<=SCENEWIDTH)
                    ok=true;
                break;
        }
        return  ok;
    }
protected:
    double m_width,m_height,m_speed,m_pixpos;
    uint m_step;
    QPixmaps m_pixs;
};

#endif // FLYER_H
