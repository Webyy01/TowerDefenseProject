#ifndef CANNONTOWER_H
#define CANNONTOWER_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include "Tower.h"

// Cannon Tower: the most basic and fundamental tower
class CannonTower : public Tower {
public:
    // Constructor with default properties
    CannonTower(QGraphicsItem* parent = nullptr);
    void shoot() override; // Implementation of the basic shoot functionality
    bool upgrade(int& playerCurrency) override;

};

#endif // CANNONTOWER_H
