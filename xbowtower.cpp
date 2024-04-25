#include "XbowTower.h"

// Initializing specific attributes for XbowTower
XbowTower::XbowTower(QGraphicsItem* parent)
    : Tower(10, 50, 100, 30, 4, parent) { // XbowTower has moderate attributes
    setPixmap(QPixmap(":/images/xbow_tower.png")); // GUI representation
}

void XbowTower::shoot() {
    // Implement shooting for XbowTower
}

bool XbowTower::upgrade(int& playerCurrency) {
    if (UpgradeLevel < MaxUpgradeLevel && playerCurrency >= UpgradeCost) {
        increaseAttributes(4, 10, 2, 75); // Moderate increments for a mid-level tower
        playerCurrency -= UpgradeCost;
        UpgradeCost += 75; // Increase upgrade cost for the next level
        UpgradeLevel++;
        return true;
    }
    return false;
}
