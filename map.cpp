#include "map.h"
#include <QtWidgets/QGraphicsScene>
#include <QMouseEvent>
#include <QGraphicsRectItem>

//Initialize the map
Map::Map() {
    QGraphicsScene();
    startScene();
}

//Function that starts the scene with all its attribtues
void Map::startScene(){

    //Set a constant scene rectangle to avoid having the scene moving
    this->setSceneRect(0,0,width,height);

    //Initialize the path
    createPath(1, 2.5);

    //Create a background Image
    QPixmap backgroundImage(":/Images/map.png");
    backgroundImage.scaled(this->width, this->height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    this->setBackgroundBrush(backgroundImage);

    lblHealth = new QLabel();
    lblScore = new QLabel();
    lblLevel = new QLabel();

    createTiles();
   }

void Map::createTiles(){

    QGraphicsRectItem* rectItem; //rect item to initialize the tiles

    QBrush myBrush(Qt::transparent); //Set all tiles to be transparent
    QBrush pathBrush(QPixmap(":/Images/Sand_Image_PNG.png").scaled(60,100)); //Set only the path tiles to have a sand background

    //Create 100x100 tiles
    for(int i = 0; i < width; i+=100){
        for(int j = 0; j < height; j+=100){

            rectItem = new QGraphicsRectItem(0,0,100,100); //create a new tile

            //fix its position
            rectItem->setX(i);
            rectItem->setY(j);

            //set its brush to transparent and visible
            rectItem->setBrush(myBrush);
            rectItem->setVisible(true);

            //Make it selectable to be able to add towers
            rectItem->setFlag(QGraphicsItem::ItemIsSelectable, true);

            tiles.push_back(rectItem); //Add the tile to the tile list
            this->addItem(rectItem); //Add the tile to the map

            for(size_t k = 0; k< path.size(); k++){

                //check if the tile is on the path, if yes...
                if(((i - path[k]->x()) > -100 && (i - path[k]->x()) < 100) && ((j - path[k]->y()) > -100 && (j - path[k]->y()) <100)){
                    //.. make it impossible to put a tower on it and make its background sandy
                    rectItem->setFlag(QGraphicsItem::ItemIsSelectable, false);
                    rectItem->setBrush(pathBrush);
                    break;
                }
            }
        }
    }
}

//Creates a path of tiles on which the enemies will move
void Map::createPath(int level, double enemySpeed){

    //Create the path for level 1
    if(level == 1){

        //The shift points, the enemy will keep moving until it reaches them, then shifts
        double shift1Y = 500;
        double shift1X = 700;
        double shift2Y = 300;
        double shift2X = 400;
        double endpoint = -100; //adjusted to the height of the enemy (100 pixels)

        double indexX = this->width/2;
        double indexY = this->height;

        QPoint* currentPoint;
        while(indexY > shift1Y){
            currentPoint = new QPoint();
            currentPoint->setX(indexX);
            currentPoint->setY(indexY);
            path.push_back(currentPoint);
            indexY-=enemySpeed;
        }
        while(indexX < shift1X){
            currentPoint = new QPoint();
            currentPoint->setX(indexX);
            currentPoint->setY(indexY);
            path.push_back(currentPoint);
            indexX+=enemySpeed;
        }
        while(indexY > shift2Y){
            currentPoint = new QPoint();
            currentPoint->setX(indexX);
            currentPoint->setY(indexY);
            path.push_back(currentPoint);
            indexY-=enemySpeed;
        }
        while(indexX > shift2X){
            currentPoint = new QPoint();
            currentPoint->setX(indexX);
            currentPoint->setY(indexY);
            path.push_back(currentPoint);
            indexX-=enemySpeed;
        }
        while(indexY >= endpoint){
            currentPoint = new QPoint();
            currentPoint->setX(indexX);
            currentPoint->setY(indexY);
            path.push_back(currentPoint);
            indexY-=enemySpeed;
        }

    }
}

void Map::setHealthLabelText(char* text){
    lblHealth->setText(text);
}
void Map::setLevelLabelText(char* text){
    lblLevel->setText(text);
}
void Map::setScoreLabelText(char* text){
    lblScore->setText(text);
}

void Map::setEnemySpeed(double numPixelsPerMove){
    enemySpeed = numPixelsPerMove;
}

