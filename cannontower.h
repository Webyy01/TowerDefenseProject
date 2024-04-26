#ifndef CANNONTOWER_H
#define CANNONTOWER_H

#include "tower.h"
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>
#include <vector>
#include "map.h"

class CannonTower : public Tower {
public:
    CannonTower(Map* myMap);
    CannonTower(Map* myMap, int posX, int posY);
    void shoot() override;
    bool upgrade(int& playerCurrency) override;
    void setLevelImage() override;

private:
    static const std::vector<QString> levelImages;
};

#endif // CANNONTOWER_H
