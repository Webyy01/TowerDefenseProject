#ifndef XBOWTOWER_H
#define XBOWTOWER_H

#include "tower.h"
#include <vector>
#include <QString>

class XbowTower : public Tower {
public:
    XbowTower(Map* map);
    void shoot() override;
    bool upgrade(int& playerCurrency) override;
    void setLevelImage() override;

private:
    static const std::vector<QString> levelImages;
};

#endif // XBOWTOWER_H
