#ifndef PLANE_H
#define PLANE_H

#include "flyer.h"
#include "unflyer.h"

class plane:public Flyer
{
    Q_OBJECT
public:
    plane(uint blood,double width,double height,double speed,const QPixmaps &pixs,QGraphicsScene *scene, QGraphicsItem *parent=0)
        :Flyer(width,height,speed,pixs,scene,parent),m_blood(blood){

    }
    virtual ~plane(){}
    virtual void strike()=0;
    virtual void shoot()=0;
protected:
    uint m_blood;
signals:
    void sig_score(int score);
    void sig_blood(int blood);
    void sig_fall();
};

#endif // PLANE_H
