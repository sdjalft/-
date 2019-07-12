#include "space.h"
#include "gameover.h"
#include "global.h"

Space::Space(QWidget *parent) : QGraphicsView(parent), isRunning(false) {
    scores = 0;
    m_scene = new QGraphicsScene;
    m_scene->setSceneRect(0, 0, SCENEWIDTH, SCENEHEIGHT);
    setScene(m_scene);
    setMaximumSize(SCENEWIDTH, SCENEHEIGHT);
    setMinimumSize(SCENEWIDTH, SCENEHEIGHT);

    setFocusPolicy(Qt::StrongFocus);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    QPixmap pix(SCENEWIDTH, SCENEHEIGHT);
        pix.load(":/new/prefix1/mission1.png");
        QPixmap temp = pix.scaled(SCENEWIDTH, SCENEHEIGHT, Qt::KeepAspectRatioByExpanding);
        setBackgroundBrush(temp);
    m_timer = new QTimer;
    m_timer->stop();
    m_timer->setInterval(50);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(slt_updata()));
//    connect(this, SIGNAL(sig_menu()), this, SLOT(slt_menu()));
    m_timer->start();
    init();
}
//void Space::imageup(){
//    ya+=1;
//    pix->move(picLabel->x(),ya);
//}
void Space::init() {

     m_bloods = PLAYERPLANEBLOOD, m_level = 1;
    QPixmaps t;
    t.append(QPixmap(playerplane));
    t.append(QPixmap(playerplane));
    t.append(QPixmap(playerplane));
    t.append(QPixmap(playerplane));
    m_player = new PLAYERPLANE(PLAYERPLANEBLOOD, PLAYERPLANESIZE, PLAYERPLANESIZE, PLAYERPLANESPEED, t, m_scene);
    m_player->setFocus();
    connect(m_player, SIGNAL(sig_fall()), this, SLOT(slt_playerDead()));
}


void Space::slt_playerDead()
{
    m_timer->stop();
    hide();
    gameover *abc=new gameover();
    abc->show();
}

void Space::slt_updata()
{
    m_scene->advance();
    m_step++;
    scores += 1;
    if (m_step % 15 == 0 ) {
        enemys();
    }

}





void Space::enemys()
{
    {
        PlaneFactory::LittleEnemyPlanes littleenemyplanes = PlaneFactory::fcreator(m_level, scene());
        foreach (LittleEnemyPlane *f, littleenemyplanes) {
            int z =  Randomizer::creat(6);
            if (z == 1) {
                int y = Randomizer::creat(SCENEHEIGHT / 2 - LittleEnemyPlanesSIZE);
                f->setPos(0, y);
            }
            else if (z == 2) {
                int y = Randomizer::creat(SCENEHEIGHT / 2 - LittleEnemyPlanesSIZE);
                f->setPos(SCENEWIDTH - LittleEnemyPlanesSIZE, y);
            }
            else {
                int x = Randomizer::creat(SCENEWIDTH - LittleEnemyPlanesSIZE);
                f->setPos(x, 0);
            }
        }
    }
}
