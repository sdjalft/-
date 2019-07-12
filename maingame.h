#ifndef MAINGAME_H
#define MAINGAME_H

#include <QDialog>
#include <QLabel>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include "planefactory.h"
#include "playerplane.h"
#include "randomizer.h"


namespace Ui {
class maingame;
}


class maingame : public QDialog
{
    Q_OBJECT

public:
    explicit maingame(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    ~maingame();
private slots:
    void imageup();
private:
    QLabel *picLabel;
    int ya=-8000;
    Ui::maingame *ui;
};
class control : public QGraphicsView{
    Q_OBJECT
public:
    control(QWidget *parent=0);
    void init();
    void enemy();
private:
    QGraphicsScene *m_scene;
    QTimer *m_timer;
    PLAYERPLANE *m_player;
protected slots:
    void slt_updata();
};

#endif // MAINGAME_H
