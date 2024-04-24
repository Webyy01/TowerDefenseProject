#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
    int health;
    int coinBalance;

public:
    Player();
    int getHealth () const;
    int getCoinBalance() const;
    void placeTower();

 };

#endif // PLAYER_H
