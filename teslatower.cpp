#include "TeslaTower.h"

TeslaTower::TeslaTower(QGraphicsItem* parent)
    : Tower(20, 100, 150, 40, 3, parent) {
    setPixmap(QPixmap(":/images/tesla_tower.png")); // Placeholder for actual image path
}

void TeslaTower::shoot() {
    // Implement shooting for TeslaTower
}

bool TeslaTower::upgrade(int& playerCurrency) {
    if (UpgradeLevel < MaxUpgradeLevel && playerCurrency >= UpgradeCost) {
        increaseAttributes(6, 15, 1, 100); // Significant increments for a powerful tower
        playerCurrency -= UpgradeCost;
        UpgradeCost += 100; // Increase upgrade cost for the next level
        UpgradeLevel++;
        return true;
    }
    return false;
}
