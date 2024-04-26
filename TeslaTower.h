#ifndef TESLATOWER_H
#define TESLATOWER_H

#include "tower.h"
#include <vector>
#include <QString>

class TeslaTower : public Tower {
public:
    TeslaTower(Map* map);
    void shoot() override;
    bool upgrade(int& playerCurrency) override;
    void setLevelImage() override;

private:
    static const std::vector<QString> levelImages;
};

#endif // TESLATOWER_H
