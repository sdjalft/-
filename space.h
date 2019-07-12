#ifndef SPACE_H
#define SPACE_H

#include "planefactory.h"
#include "bulletfactory.h"
#include "playerplane.h"
#include "randomizer.h"


class Space : public QGraphicsView
{
    Q_OBJECT
public:
    Space(QWidget *parent = 0);
//    void paintEvent(QPaintEvent *);
    void init();
    void enemys();
private:
    QGraphicsScene *m_scene;
    QPixmap *pix;
    int ya=-8000;
    QTimer *m_timer;
    PLAYERPLANE *m_player;
    uint m_scores, m_bloods, m_bombs, m_level, m_step;
    bool isRunning;

signals:
    void sig_menu();
protected slots:
    void slt_playerDead();
    void slt_updata();
//    void imageup();
//    void slt_menu();
};

#endif // SPACE_H
