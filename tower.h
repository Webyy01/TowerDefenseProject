#ifndef TOWER_H
#define TOWER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <vector>
#include "map.h"

class Tower : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Tower(int dmg, int hlth, int cst, int rng, int fireR, Map* map);
    virtual void shoot() = 0;
    virtual bool upgrade(int& playerCurrency) = 0;
    virtual void setLevelImage() = 0;

protected:
    int Damage;
    int Health;
    int Cost;
    int Range;
    int FiringRate;
    int UpgradeCost;
    int UpgradeLevel;
    static const int MaxUpgradeLevel = 3;

    Map* map;
    std::vector<QString> levelImages;
    void increaseAttributes(int dmgIncrease, int rangeIncrease, int rateIncrease, int costIncrease);
};

#endif // TOWER_H
