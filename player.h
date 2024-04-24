#ifndef PLAYER_H
#define PLAYER_H
#include "QObject"

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
    void placeTower();

public slots:

 };

#endif // PLAYER_H
