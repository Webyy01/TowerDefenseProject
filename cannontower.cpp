#include "CannonTower.h"

// Define the path to the cannon tower image
const QString CANNON_TOWER_IMAGE_PATH = ":/images/cannon_tower.png";

CannonTower::CannonTower(QGraphicsItem* parent)
    : Tower(10, // Damage
            150, // Health
            100, // Cost
            75, // Range
            1, // Firing rate
            parent) {
    // Set the pixmap for the cannon tower's GUI representation
    setPixmap(QPixmap(CANNON_TOWER_IMAGE_PATH));
}

void CannonTower::shoot() {
    // TODO: Implement the specific shooting behavior for the Cannon Tower
}

bool CannonTower::upgrade(int& playerCurrency) {
    if (UpgradeLevel < MaxUpgradeLevel && playerCurrency >= UpgradeCost) {
        increaseAttributes(2, 5, 1, 50); // Smaller increments for a basic tower
        playerCurrency -= UpgradeCost;
        UpgradeCost += 50; // Increase upgrade cost for the next level
        UpgradeLevel++;
        return true;
    }
    return false;
}
