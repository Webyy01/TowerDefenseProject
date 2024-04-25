#ifndef PLAYER_H
#define PLAYER_H
#include "QObject"
#include <QtWidgets/QGraphicsScene>

class Player : QObject
{
private:
    int health;
    int coinBalance;

public:
    Player();
    int getHealth () const;
    void setHealth(int newHealth);
    void decreaseHealth();
    int getCoinBalance() const;
    void placeTower(QGraphicsScene*);

public slots:

 };

#endif // PLAYER_H
