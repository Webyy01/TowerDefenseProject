#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include "map.h"
#include "enemy.h"
#include <QObject>

class Bullet : public QObject, public QGraphicsPixmapItem {
Q_OBJECT
public:
    Bullet(Map* map, QPointF& pos, double damage, Enemy* targetEnemy);
    ~Bullet();

    void setDamage(int damage);
    int getDamage() const;
    void setEnemy(Enemy* enemy);
    Enemy* getEnemy() const;
    Map* getMap() const;

public slots:
    void move();
private:
    Map* map;
    Enemy* enemy;
    double damage;
    QTimer* bulletMotionTimer;
};

#endif // BULLET_H
