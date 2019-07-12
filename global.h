#ifndef GLOBAL_H
#define GLOBAL_H

#include <QtWidgets>

extern int scores;

#define PLAYERPLANENAME 4
#define ENEMYPLANENAME 5
#define PLAYERBULLETNAME 6
#define ENEMYBULLETNAME 7
#define BOMBNAME 8

//Size
#define SCENEWIDTH  600
#define SCENEHEIGHT  800
#define PLAYERPLANESIZE 90
#define LittleEnemyPlanesSIZE 100
#define PLAYERBULLETSIZE 20
#define LittleEnemyPlanesBULLETSIZE1 20
#define LittleEnemyPlanesBULLETSIZE2 20
#define LittleEnemyPlanesBULLETSIZE3 20
//Speed
#define PLAYERPLANESPEED 10
#define LittleEnemyPlanesSPEED 10
#define PLAYERBULLETSPEED 50
#define LittleEnemyPlanesBULLETSPEED1 20
#define LittleEnemyPlanesBULLETSPEED2 20
#define LittleEnemyPlanesBULLETSPEED3 20

const int PLAYERSHOOTSTEP = 5;
const int LittleEnemyPlanesSHOOTSTEP = 20;

//Score
#define LittleEnemyPlanesSCORE 10

//Hp
#define LittleEnemyPlanesHP 5

#define PLAYERPLANEBLOOD 5
#define PLAYERPLANEBULLET 3

//
const QString background = "";
const QString bloodsupplypix = "";
const QString boss0 = "";
const QString boss1 = "";
const QString boss2 = "";
const QString boss3 = "";
const QString bossbullet0 = "";
const QString bossbullet1 = "";
const QString bossbullet2 = "";
const QString bossbullet3 = "";
const QString bulletsupplypix = "";
const QString LittleEnemyPlanes1 = ":/image/LittleEnemyPlane/LittleEnemyPlane1.png";
const QString LittleEnemyPlanes2 = ":/image/LittleEnemyPlane/LittleEnemyPlane2.png";
const QString LittleEnemyPlanes3 = ":/image/LittleEnemyPlane/LittleEnemyPlane3.png";
const QString LittleEnemyPlanes4 = ":/image/LittleEnemyPlane/LittleEnemyPlane4.png";
const QString LittleEnemyPlanes5 = ":/image/LittleEnemyPlane/LittleEnemyPlane5.png";

const QString LittleEnemyPlanesbullet0 = ":/new/prefix1/bullet_5.png";
const QString LittleEnemyPlanesbullet1 = ":/new/prefix1/bullet_5.png";
const QString LittleEnemyPlanesbullet2 = ":/new/prefix1/bullet_7.png";
const QString playerbullet0 = ":/new/prefix1/bullet_1.png";
const QString playerbullet1 = ":/new/prefix1/bullet_8.png";
const QString playerbullet2 = ":/new/prefix1/bullet_8.png";
const QString playerplane = ":/image/playerplane/playerplane.png";

#endif // GLOBAL_H
