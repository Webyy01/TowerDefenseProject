#ifndef INFERNOTOWER_H
#define INFERNOTOWER_H

#include "tower.h"
#include <vector>
#include <QString>

class InfernoTower : public Tower {
public:
    InfernoTower(Map* map);
    void shoot() override;
    bool upgrade(int& playerCurrency);
    void setLevelImage() override;

private:
    static const std::vector<QString> levelImages;
    int SplashRange;
    int SplashDamage;
};

#endif // INFERNOTOWER_H
