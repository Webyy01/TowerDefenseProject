// enemy.cpp
#include "Enemy.h"
#include "QTimer"
#include "QAudioOutput"
#include "QGraphicsScene"
#include "QGraphicsProxyWidget"
#include "Bullet.h"

Enemy::Enemy(Map* map) : QObject(), QGraphicsPixmapItem(), lose(new QMediaPlayer()), sound(new QMediaPlayer()), mainlosing(new QAudioOutput()){

    health = 100;
    maxHealth = 100;
    isAlive = true;

    setPixmap(QPixmap(":/Images/Enemy_Dropper_Ballon.png").scaled(60, 100));


    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);

    // mainlosing->setVolume(10);
    // lose->setAudioOutput(mainlosing);
    // lose->setSource(QUrl(":/audios/balloonpop.mp3"));

    // QProgressBar healthBar;
    // healthBar.setMinimum(0);
    // healthBar.setMaximum(100);
    // healthBar.setValue(health);

    // QGraphicsProxyWidget *proxy = new QGraphicsProxyWidget(this);
    // proxy->setWidget(&healthBar);
    // proxy->setScale(0.2);
    // proxy->setRotation(270);
    // proxy->setPos(-5, 30);
    // proxy->setParentItem(this);

    this->map = map;

    //Add the enemy to the map and set its position to the starting point in the path
    map->addItem(this);
    this->setX(map->path[0]->x());
    this->setY(map->path[0]->y());

}

//Destructor of the enemy
Enemy::~Enemy() {

    //Remove the enemy from the map
    map->removeItem(this);
    delete lose;
    delete sound;
    delete mainlosing;
}

void Enemy::move() {
    size_t currentIndex = indexEnemyOnPath(this);

    //If the enemy has passed the whole path
    if(currentIndex+1 == map->path.size()){
        //Emit the enemyDissapeared signal to be handled by the appropriate function (decrease player health)
        emit enemyDissapeared(this);

        //delete the enemy
        delete this;
        return;
    }

    //Set position to next point on path
    this->setX(map->path[currentIndex+1]->x());
    this->setY(map->path[currentIndex+1]->y());

    //Handles the colliding items
    QList<QGraphicsItem *> collideItems = collidingItems();
    for (int i = 0; i < collideItems.size(); ++i) {
            Bullet *bullet = dynamic_cast<Bullet*>(collideItems[i]);
            if (bullet) {
                sound->play();
                scene()->removeItem(bullet);
                takeDamage(bullet->getDamage());
                delete bullet;
                return;
            }
    }
}

//Allows the enemy to take damage by the bullet
void Enemy::takeDamage(int damage) {
    health -= damage;
    if (health <= 0) {
        isAlive = false;
        lose->play();
        emit enemyDestroyed(this);
    }
}

//Returns the index of the enemy on the path
//If the enemy is not found returns -1
int Enemy::indexEnemyOnPath(Enemy* enemy){
    for(size_t i = 0; i < map->path.size(); i++){
        if(enemy->x() == map->path[i]->x() && enemy->y() == map->path[i]->y()){
            return i;
        }
    }
    return -1;
}

//Returns enemy health
int Enemy::getHealth() const{
    return health;
}
