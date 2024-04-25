#include "player.h"

Player::Player() {}

//Returns the health of the player
int Player::getHealth() const{
    return health;
}

//Returns the coin balance of the player
int Player::getCoinBalance() const{
    return coinBalance;
}

//Sets the health of the player
void Player::setHealth(int newHealth){
    health = newHealth;
}

//Decreases the health of the player by a fixed count
void Player::decreaseHealth(){

}

//


