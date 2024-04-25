#ifndef MAP_H
#define MAP_H
#include <QGraphicsScene>
#include <QObject>
#include "enemy.h"
#include <vector>
#include "tower.h"

class Map : public QGraphicsScene
{
    Q_OBJECT
private:
    int width = 1400;
    int height = 700;
    int level;

    //Temp variable to store rect items
    QGraphicsRectItem* temp;

    std::vector<std::vector<QGraphicsItem*>> tiles;
    std::vector<QGraphicsItem*> path;

    void createPath(int level, int numRows, int numCols);
    void removeEnemy(Enemy* enemy);
public:
    Map();
    void startScene();
    void addEnemy(Enemy*);
    void moveEnemy(Enemy*);
    bool addTower(Tower* tower, QGraphicsItem* tile);

};

#endif // MAP_H
