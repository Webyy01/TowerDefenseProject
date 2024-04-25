#include "tower.h"

Tower::Tower(int dmg, int hlth, int cst, int rng, int fireR, QGraphicsItem* parent)
    : QObject(), QGraphicsPixmapItem(parent),
    Damage(dmg), Health(hlth), Cost(cst), Range(rng), FiringRate(fireR),
    UpgradeCost(cst), UpgradeLevel(0) {
}

bool Tower::upgrade(int& playerCurrency) {
    if (playerCurrency >= UpgradeCost && UpgradeLevel < MaxUpgradeLevel) {
        increaseAttributes(5, 5, 1, UpgradeCost * 0.5);
        playerCurrency -= UpgradeCost;
        UpgradeLevel++;
        return true;
    }
    return false;
}

void Tower::increaseAttributes(int dmgIncrease, int rangeIncrease, int rateIncrease, int costIncrease) {
    Damage += dmgIncrease;
    Range += rangeIncrease;
    FiringRate += rateIncrease;
    UpgradeCost += costIncrease;
}
