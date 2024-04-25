#ifndef TOWER_H
#define TOWER_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Tower : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Tower(int dmg, int hlth, int cst, int rng, int fireR, QGraphicsItem* parent = nullptr);
    virtual void shoot() = 0;
    virtual bool upgrade(int& playerCurrency) = 0;
protected:
    int Damage;
    int Health;
    int Cost;
    int Range;
    int FiringRate;
    int UpgradeCost;
    int UpgradeLevel;
    static const int MaxUpgradeLevel = 3;

    void increaseAttributes(int dmgIncrease, int rangeIncrease, int rateIncrease, int costIncrease);
};

#endif
