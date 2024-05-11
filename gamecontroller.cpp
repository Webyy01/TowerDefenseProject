#include "gamecontroller.h"
#include "enemy.h"
#include <QMouseEvent>
#include "cannontower.h"
#include "map.h"
#include "bullet.h"
#include <iostream>

// Constructor
GameController::GameController(Map* map)
    : QObject(),
    currentWaveIndex(0), // Current wave index
    totalWaves(2), // Total number of waves (zero-indexed)
    numEnemiesPerWave(10), // Number of enemies per wave
    waveInterval(5000), // Interval between waves (in milliseconds)
    waveDuration(10000) // Duration of each wave (in milliseconds)
{

    //Define the map of the enemy
    this->map = map;

    waveTimer = new QTimer(this); // Create a timer for spawning waves
    connect(waveTimer, &QTimer::timeout, this, &GameController::spawnWave); // Connect the timer's timeout signal to the spawnWave() function
    waveTimer->start(waveInterval); // Start the timer with the specified interval

    connect(this, &GameController::playerLost, this, &GameController::handlePlayerLost);

    //This timer is used to help with the process of adding towers on mouse click
    //It functions by creating a timer that checks for tile selection 10 times per second
    //If a tile is selected, it adds a tower onto it if there is enough funds
    QTimer* checkIfAddTowerTimer = new QTimer(this);
    connect(checkIfAddTowerTimer, &QTimer::timeout, this, &GameController::handleTileSelected);
    checkIfAddTowerTimer->start(100);
}

// Setter function for total number of waves
void GameController::setTotalWaves(int totalWaves)
{
    this->totalWaves = totalWaves;
}


// Slot function to spawn a wave of enemies
void GameController::spawnWave()
{

    if (currentWaveIndex >= totalWaves) { // Check if the current wave index exceeds the total number of waves

        waveTimer->stop(); // If so, stop the wave timer to prevent further spawning
        return;
    }

    for (int i = 0; i < numEnemiesPerWave; i++) { // Iterate to spawn the specified number of enemies in the wave
        QTimer::singleShot(i * (waveDuration / numEnemiesPerWave), this, &GameController::spawnEnemy); // Use singleShot to delay spawning of each enemy within the wave
    }

    currentWaveIndex++; // Increment the current wave index for the next wave
}

// Slot function to spawn an enemy
void GameController::spawnEnemy()
{
    Enemy *enemy = new Enemy(map);  // Instantiate a new Enemy object in the map
    enemies.append(enemy); // Add the enemy to the list of enemies

    // Connect the enemy's  signals to their GameController's handlers
    connect(enemy, &Enemy::enemyDestroyed, this, &GameController::handleEnemyDestroyed);
    connect(enemy, &Enemy::enemyDissapeared, this, &GameController::handleEnemyDissapeared);

    //update the enemies list for all towers
    for(int i =0 ; i< towers.size(); i++){
        towers[i]->setEnemies(enemies);
    }
}

//handles the destroyed enemy by removing it from the scene and cleaning up the scene
void GameController::handleEnemyDestroyed(Enemy* destroyedEnemy) {
    if (destroyedEnemy) {
        enemies.removeOne(destroyedEnemy); //Function to remove the enemy from the QList

        //update all the towers' enemy lists
        for(int i =0 ; i< towers.size(); i++){
            towers[i]->setEnemies(enemies);
        }


        //iterates over all the bullets
        for(int i = 0; i < towers.size(); i++){
            for(int j = 0; j < towers[i]->bullets.size(); j++){
                Bullet* b = towers[i]->bullets[j];

                //if this bullet aims at the destroyed enemy, and if it is not yet deleted (or not in the scene)
                if(b->getEnemy() == destroyedEnemy){
                    if(towers[i]->scene() == b->scene()){
                        towers[i]->bullets.removeOne(b); //remove it from the bullets list
                        delete b; //delete it
                    }
                }
            }
        }
        delete destroyedEnemy; //Delete the destroyed enemy
    }
}

void GameController::handleEnemyDissapeared(Enemy* enemy){
    enemies.removeOne(enemy);
    for(int i =0 ; i< towers.size(); i++){
        towers[i]->setEnemies(enemies);
    }
    playerHealth -= enemy->getHealth();
    if(playerHealth <= 0){
        emit playerLost();
    }
    delete enemy;
}

void GameController::handlePlayerLost(){
    //Handles the player lost signal by deleting the scene and showing options to start new game etc.
    std::cout << "player lost... " << std::endl;
}

void GameController::handleTileSelected(){
    for(QGraphicsRectItem* tile: map->tiles){
        if(tile->isSelected()){ //Check if the tile is selected
            CannonTower* newCannon = new CannonTower(map, tile->x(),tile->y()); //Add a new cannon
            towers.append(newCannon);
            tile->setFlag(QGraphicsItem::ItemIsSelectable, false);  //Prohibit towers from forming on top of one another
        }
    }
}



