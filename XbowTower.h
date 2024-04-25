#ifndef XBOWTOWER_H
#define XBOWTOWER_H

#include "Tower.h"

// Xbow Tower: less expensive with moderate power
class XbowTower : public Tower {
public:
    XbowTower(QGraphicsItem* parent = nullptr);
    void shoot() override;
    bool upgrade(int& playerCurrency) override;};

#endif // XBOWTOWER_H
