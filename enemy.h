#ifndef ENEMY_H
#define ENEMY_H
#include<QObject>
#include <QtWidgets/QGraphicsPixmapItem>

class Enemy : public QObject, public QGraphicsPixmapItem
{
public:
    Enemy();
};

#endif // ENEMY_H
