#include "bullet.h"
#include <QTimer>
#include <iostream>

//Constructor to create a new bullet with specific pos, damage, and enemy to be targeted
Bullet::Bullet(Map* map, QPointF& pos, double damage, Enemy* enemy){
    this->setPixmap(QPixmap(":/Images/Cannon_Shell_2_PNG.png").scaled(20,20));//set the picture of the bullet
    this->map = map; //set the map of the bullet (its scene)
    map->addItem(this);


    this->setPos(pos);
    this->setDamage(damage);
    this->enemy = enemy;

    //Create a timer for bullet motion, set the bullet to move every .05 seconds
     bulletMotionTimer = new QTimer();
    connect(bulletMotionTimer, SIGNAL(timeout()), this, SLOT(move()));
    bulletMotionTimer->start(30); //move the bullet 33 times per second
}

//deelte the bullet
Bullet::~Bullet(){
    setEnemy(nullptr);
    bulletMotionTimer->stop();
    if(this->scene() == map){
        map->removeItem(this);
    }
}

//Set the damage to specific damage
void Bullet::setDamage(int newDamage) {
    damage = newDamage;
}

//Get the damage of the bullet
int Bullet::getDamage() const {
    return damage;
}

//Returns the enemy the bullet targets
Enemy* Bullet::getEnemy() const{
    return enemy;
}

//Returns the map
Map* Bullet::getMap() const{
    return map;
}

//sets the enemy to the specified value
void Bullet::setEnemy(Enemy* enemy){
    this->enemy = enemy;
}

//Moves the bullet, max of two pixels in each direction per move
void Bullet::move(){
    if(enemy == nullptr || enemy->scene()!=map){
        delete this;
        return;
    }
    double bulletXPosition = this->x();
    double bulletYPosition= this->y();
    double enemyXPosition = enemy->x();
    double enemyYPosition = enemy->y();

    if(this->pos() != enemy->pos()){
        if(enemyXPosition > bulletXPosition){
            this->setX(bulletXPosition + 2);
        }
        else if(enemyXPosition < bulletXPosition){
            this->setX(bulletXPosition -2 );
        }

        if(enemyYPosition > bulletYPosition){
            this->setY(bulletYPosition + 2);
        }
        else if(enemyYPosition < bulletYPosition){
            this->setY(bulletYPosition -2 );
        }
    }
}

