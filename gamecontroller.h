#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>
#include <QTimer>
#include <QList>
#include <enemy.h>
#include "map.h"

class GameController : public QObject
{
    Q_OBJECT

public:
    GameController(Map*);
    void setTotalWaves(int totalWaves);

signals:
    void playerLost();

private:
    QTimer *waveTimer;
    int currentWaveIndex;
    int totalWaves;
    int numEnemiesPerWave;
    int waveInterval;
    int waveDuration;

    QList <Enemy *> enemies;
    Map* map;

    int playerHealth = 1000;
    int playerLevel = 1;

private slots:
    void spawnWave();
    void spawnEnemy();
    void handleEnemyDestroyed(Enemy* destroyedEnemy);
    void handleEnemyDissapeared(Enemy* enemy);
    void handlePlayerLost();

    void handleTileSelected();
};
#endif // GAMECONTROLLER_H
