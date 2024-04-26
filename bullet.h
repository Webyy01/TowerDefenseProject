#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>

class Bullet : public QGraphicsPixmapItem {
public:
    Bullet();
    //add image

    void setDamage(int damage);
    int getDamage() const;

private:
    int damage;
};

#endif // BULLET_H
