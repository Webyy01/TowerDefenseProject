#ifndef TESLATOWER_H
#define TESLATOWER_H

#include "Tower.h"

class TeslaTower : public Tower {
public:
    TeslaTower(QGraphicsItem* parent = nullptr);
    void shoot() override;
    bool upgrade(int& playerCurrency) override;

    // Other members and methods...
};

#endif // TESLATOWER_H
