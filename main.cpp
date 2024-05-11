#include <QCoreApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QApplication>
#include "map.h"
#include <gamecontroller.h>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    Map* myMap = new Map();

    GameController gameController(myMap);

    QGraphicsView* view = new QGraphicsView();
    view->setScene(myMap);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();
    view->setFixedSize(1400, 700);
    view->setAttribute(Qt::WA_AcceptTouchEvents, false);

    return a.exec();
}
