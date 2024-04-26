#include "tower.h"
    // base tower instantiation with its properties and sets the QGraphicsItem as parent
Tower::Tower(int dmg, int hlth, int cst, int rng, int fireR, Map* map)
        : Damage(dmg), Health(hlth), Cost(cst), Range(rng), FiringRate(fireR),
        UpgradeCost(cst), UpgradeLevel(0), map(map) {

    map->addItem(this);
}

// function to be used for upgrading
void Tower::increaseAttributes(int dmgIncrease, int rangeIncrease, int rateIncrease, int costIncrease) {
    Damage += dmgIncrease;
    Range += rangeIncrease;
    FiringRate += rateIncrease;
    UpgradeCost += costIncrease;
}
