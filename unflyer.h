#ifndef UNFLYER_H
#define UNFLYER_H

#include <QtWidgets>
#include "global.h"

class UnFlyer:public QGraphicsObject{
    Q_OBJECT
public:
    UnFlyer(QGraphicsItem *parent = 0);
        ~UnFlyer();
        enum {TYPE=UserType+1};
        int type() const;
};

#endif
