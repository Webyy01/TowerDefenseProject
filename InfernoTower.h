#ifndef INFERNOTOWER_H
#define INFERNOTOWER_H

#include "Tower.h"

// InfernoTower: most powerful and expensive tower
class InfernoTower : public Tower {
public:


    InfernoTower(QGraphicsItem* parent = nullptr);
    void shoot() override;
    bool upgrade(int& playerCurrency) override;
};


#endif // INFERNOTOWER_H
