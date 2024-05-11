#ifndef ENEMY_H
#define ENEMY_H

#include<QGraphicsPixmapItem>
#include<QGraphicsItem>
#include<QObject>
#include<QMediaPlayer>
#include<QProgressBar>
#include "map.h"

class Enemy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy(Map*);
    ~Enemy();
    int getHealth() const;
    bool isALive() const{
        return isAlive;
    }

public slots:
    void move();
    void takeDamage(int damage);

signals:
    void enemyDestroyed(Enemy* enemy);
    void enemyDissapeared(Enemy* enemy);

private:
    int health;
    int maxHealth;
    bool isAlive;
    Map* map;
    QTimer *motionTimer;

    int indexEnemyOnPath(Enemy*);
};

#endif // ENEMY_H
