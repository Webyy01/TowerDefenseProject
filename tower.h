#ifndef TOWER_H
#define TOWER_H

#include <QObject>
#include <QGraphicsPixmapItem>

// base tower class
class Tower : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    // tower constructor
    Tower(int dmg, int hlth, int cst, int rng, int fireR, QGraphicsItem* parent = nullptr);
    virtual void shoot() = 0; // purly virtual shoot function
    virtual bool upgrade(int& playerCurrency) = 0; // purly visrtual upgrade function
protected:
    // tower attributes
    int Damage;
    int Health;
    int Cost;
    int Range;
    int FiringRate;
    int UpgradeCost;
    int UpgradeLevel;
    static const int MaxUpgradeLevel = 3;
    // function to be used in upgrading
    void increaseAttributes(int dmgIncrease, int rangeIncrease, int rateIncrease, int costIncrease);
};

#endif
