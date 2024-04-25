#include <QCoreApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QApplication>
#include "map.h"

int main(int argc, char *argv[])
{
    /*
     *    QCoreApplication a(argc, argv);

    //create a new scene
    MainClass::startScene();

    QGraphicsView * view = new QGraphicsView(MainClass::scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();
    view->setFixedSize(800,800);

    return a.exec();
*/

    QApplication a(argc, argv);

    Map* myMap = new Map();

    QGraphicsScene* myScene =myMap;

    QGraphicsView* view = new QGraphicsView(myScene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();
    view->setFixedSize(1400, 700);

    return a.exec();
}
