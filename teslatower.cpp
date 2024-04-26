#include "TeslaTower.h"
#include "utility.h"

const std::vector<QString> TeslaTower::levelImages = {
    ":/Images/Tesla1.png",
    ":/Images/Tesla2.png",
    ":/Images/Tesla3.png"
};

TeslaTower::TeslaTower(Map* map) : Tower(20, 100, 150, 40, 3, map) {
    setLevelImage();
}

void TeslaTower::shoot() {
    std::vector<Enemy*> enemies = findAllEnemiesWithinRange(this->scene(), this->pos(), Range);
    for (auto& enemy : enemies) {
        fireChainLightningAt(this->scene(), enemy, Damage);
    }
}

bool TeslaTower::upgrade(int& playerCurrency) {
    if (UpgradeLevel < MaxUpgradeLevel && playerCurrency >= UpgradeCost) {
        increaseAttributes(6, 15, 1, 100);
        playerCurrency -= UpgradeCost;
        UpgradeCost += 100;
        UpgradeLevel++;
        return true;
    }
    return false;
}
void TeslaTower::setLevelImage() {
    setPixmap(QPixmap(levelImages[UpgradeLevel]));
}
