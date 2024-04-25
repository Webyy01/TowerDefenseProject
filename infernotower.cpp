#include"InfernoTower.h"

// Initializing specific attributes for InfernoTower
InfernoTower::InfernoTower(QGraphicsItem* parent)
    : Tower(30, 100, 200, 50, 2, parent) { // InfernoTower has high damage and cost
    setPixmap(QPixmap(":/images/inferno_tower.png")); // GUI representation
}

void InfernoTower::shoot() {
    // Implement powerful shooting for InfernoTower
}

bool InfernoTower::upgrade(int& playerCurrency) {
    if (UpgradeLevel < MaxUpgradeLevel && playerCurrency >= UpgradeCost) {
        increaseAttributes(8, 20, 2, 150); // Largest increments for the most powerful tower
        playerCurrency -= UpgradeCost;
        UpgradeCost += 150; // Increase upgrade cost for the next level
        UpgradeLevel++;
        return true;
    }
    return false;
}
