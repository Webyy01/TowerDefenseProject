#include "map.h"
#include <QtWidgets/QGraphicsScene>
#include "enemy.h"
#include <QPen>
#include "tower.h"

Map::Map() {
    QGraphicsScene();
    startScene();
}

//Function that starts the scene with all its attribtues
void Map::startScene(){


    //Resizes the main vector (row vector) to size 10
    tiles.resize(20);

    int indexX = 0;
    int indexY = 0;

    //Initialize all the tiles
    for(size_t i = 0; i < tiles.capacity(); i++){

        //Resizes the column vector to 10
        tiles[i].resize(20);
        for(size_t j = 0; j < tiles[i].capacity(); j++){
            tiles[i][j] = new QGraphicsRectItem(indexX, indexY, 70, 35);
            tiles[i][j]->setVisible(false);
            this->addItem(tiles[i][j]);
            indexY+=35;
        }
        indexY = 0;
        indexX+=70;
    }

    //Initialize the path
    createPath(1, 20, 20);

    //Create a background Image
    QPixmap backgroundImage(":/towerdefimgs/pexels-pixabay-235985.jpg");
    backgroundImage.scaled(this->width, this->height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    this->setBackgroundBrush(backgroundImage);

   }

//Creates a path of tiles on which the enemies will move
void Map::createPath(int level, int numRows, int numCols){

    //Create the path for level 1
    if(level == 1){

        //Create a start tile in the middle of the last row
        QGraphicsRectItem* startTile = dynamic_cast<QGraphicsRectItem*>(tiles[numRows/2][numCols-1]);
        startTile->setBrush(QBrush(Qt::red));
        startTile->setVisible(true);
        path.push_back(startTile);

        //The shift points, the enemy will keep moving until it reaches them
        int shift1Cols = 15;
        int shift1Rows = 15;
        int shift2Cols = 7;
        int shift2Rows = 6;
        int shift3Cols = 0;

        int indexX = numRows/2;
        int indexY = numCols-2;
        QGraphicsRectItem* currentTile;
        while(indexY > shift1Cols){
            currentTile = dynamic_cast<QGraphicsRectItem*>(tiles[indexX][indexY]);
            currentTile->setBrush(QBrush(Qt::red));
            currentTile->setVisible(true);
            path.push_back(currentTile);
            indexY--;
        }
        while(indexX < shift1Rows){
            currentTile = dynamic_cast<QGraphicsRectItem*>(tiles[indexX][indexY]);
            currentTile->setBrush(QBrush(Qt::red));
            currentTile->setVisible(true);
            path.push_back(currentTile);
            indexX++;
        }
        while(indexY > shift2Cols){
            currentTile = dynamic_cast<QGraphicsRectItem*>(tiles[indexX][indexY]);
            currentTile->setBrush(QBrush(Qt::red));
            currentTile->setVisible(true);
            path.push_back(currentTile);
            indexY--;
        }
        while(indexX > shift2Rows){
            currentTile = dynamic_cast<QGraphicsRectItem*>(tiles[indexX][indexY]);
            currentTile->setBrush(QBrush(Qt::red));
            currentTile->setVisible(true);
            path.push_back(currentTile);
            indexX--;
        }
        while(indexY >= shift3Cols){
            currentTile = dynamic_cast<QGraphicsRectItem*>(tiles[indexX][indexY]);
            currentTile->setBrush(QBrush(Qt::red));
            currentTile->setVisible(true);
            path.push_back(currentTile);
            indexY--;
        }

    }
}

//Creates an enemy to existence
void Map::addEnemy(Enemy* enemy){
    temp = dynamic_cast<QGraphicsRectItem*>(path[0]);
    path[0] = enemy;
}

//Moves the enemy one step along the path
void Map::moveEnemy(Enemy* enemy){
    for(size_t i = 0; i < path.size(); i++){
        if(path[i] == enemy){
            if(i == path.size()){
                removeEnemy(enemy);
                return;
            }

            path[i+1] = enemy;
            path[0] = temp;
        }
    }
}

//Removes the enemy
void Map::removeEnemy(Enemy* enemy){
    for(size_t i = 0; i < path.size(); i++){
        if(path[i] == enemy){
            path[i] = temp;
            delete enemy;
            return;
        }
    }
    delete enemy;
}

//Adds a tower in the appropriate place
bool Map::addTower(Tower* tower, QGraphicsItem* tile){
    for(size_t i = 0; i < path.size(); i++){
        if(tile == path[i]){
            return false;
        }
    }
    tile = dynamic_cast<QGraphicsPixmapItem*>(tower);
    return true;
}
