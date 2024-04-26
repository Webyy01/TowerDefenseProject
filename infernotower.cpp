#include "InfernoTower.h"
#include "utility.h"


const std::vector<QString> InfernoTower::levelImages = {
    ":/Images/inferno1.png",
    ":/Images/inferno2.png",
    ":/Images/inferno3.png"
};

InfernoTower::InfernoTower(Map* map) : Tower(30, 100, 200, 50, 2, map) {
    setLevelImage();
}

void InfernoTower::shoot() {
    Enemy* closestEnemy = findClosestEnemyWithinRange(this->scene(), this->pos(), Range);
    if (closestEnemy) {
        fireProjectileAt(this->scene(), closestEnemy, Damage);
        causeSplashDamageToNearbyEnemies(this->scene(), closestEnemy, SplashRange, SplashDamage);
    }
}

bool InfernoTower::upgrade(int& playerCurrency) {
    if (UpgradeLevel < MaxUpgradeLevel && playerCurrency >= UpgradeCost) {
        increaseAttributes(8, 20, 2, 150);
        playerCurrency -= UpgradeCost;
        UpgradeCost += 150;
        UpgradeLevel++;
        return true;
    }
    return false;
}
void InfernoTower::setLevelImage() {
    setPixmap(QPixmap(levelImages[UpgradeLevel]));
}
