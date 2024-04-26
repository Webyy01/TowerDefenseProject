#include "XbowTower.h"
#include "Utility.h"


const std::vector<QString> XbowTower::levelImages = {
    ":/Images/Xbow1.png",
    ":/Images/Xbow2.png",
    ":/Images/Xbow3.png"
};

XbowTower::XbowTower(Map* map) : Tower(10, 50, 100, 30, 4, map) {
    setLevelImage();
}


void XbowTower::shoot() {
    std::vector<Enemy*> enemies = findAllEnemiesWithinRange(this->scene(), this->pos(), Range);
    for (auto& enemy : enemies) {
        fireProjectileAt(this->scene(), enemy, Damage);
    }
}

bool XbowTower::upgrade(int& playerCurrency) {
    if (UpgradeLevel < MaxUpgradeLevel && playerCurrency >= UpgradeCost) {
        increaseAttributes(4, 10, 2, 75);
        playerCurrency -= UpgradeCost;
        UpgradeCost += 75;
        UpgradeLevel++;
        return true;
    }
    return false;
}
void XbowTower::setLevelImage() {
    setPixmap(QPixmap(levelImages[UpgradeLevel]));
}
