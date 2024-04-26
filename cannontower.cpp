#include "cannontower.h"
#include "Utility.h"

const QString CANNON_TOWER_IMAGE_PATH = ":/images/cannon_tower.png";

const std::vector<QString> CannonTower::levelImages = {
    ":/Images/Cannon1.png",
    ":/Images/Cannon2.png",
    ":/Images/Cannon3.png"
};

CannonTower::CannonTower(Map* map) : Tower(10, 150, 100, 75, 1, map) {
    setLevelImage();
}

CannonTower::CannonTower(Map* map, int posX, int posY) : CannonTower(map){
    setLevelImage();
    this->setX(posX);
    this->setY(posY);
}

void CannonTower::shoot() {
    Enemy* closestEnemy = findClosestEnemyWithinRange(this->scene(), this->pos(), Range);
    if (closestEnemy) {
        fireProjectileAt(this->scene(), closestEnemy, Damage);
    }
}

bool CannonTower::upgrade(int& playerCurrency) {
    if (UpgradeLevel < MaxUpgradeLevel && playerCurrency >= UpgradeCost) {
        increaseAttributes(2, 5, 1, 50);
        playerCurrency -= UpgradeCost;
        UpgradeCost += 50;
        UpgradeLevel++;
        return true;
    }
    return false;
}

void CannonTower::setLevelImage() {
    setPixmap(QPixmap(levelImages[UpgradeLevel]).scaled(100,100));
}
