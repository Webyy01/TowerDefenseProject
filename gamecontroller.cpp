#include "gamecontroller.h"
#include "enemy.h"
#include <iostream>
#include <QMouseEvent>
#include "cannontower.h"
#include "map.h"

// Constructor
GameController::GameController(Map* map)
    : QObject(),
    currentWaveIndex(0), // Current wave index
    totalWaves(2), // Total number of waves (zero-indexed)
    numEnemiesPerWave(5), // Number of enemies per wave
    waveInterval(5000), // Interval between waves (in milliseconds)
    waveDuration(10000) // Duration of each wave (in milliseconds)
{

    //Define the map of the enemy
    this->map = map;

    //Connect the enemy when destroyed to their destruction handler
    for (Enemy* enemy : enemies) {
        connect(enemy, &Enemy::enemyDestroyed, this, &GameController::handleEnemyDestroyed);
        connect(enemy, &Enemy::enemyDissapeared, this, &GameController::handleEnemyDissapeared);
    }


    waveTimer = new QTimer(this); // Create a timer for spawning waves
    connect(waveTimer, &QTimer::timeout, this, &GameController::spawnWave); // Connect the timer's timeout signal to the spawnWave() function
    waveTimer->start(waveInterval); // Start the timer with the specified interval

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

    // Connect the enemy's enemyDestroyed signal to the GameController's handleEnemyDestroyed slot
    connect(enemy, &Enemy::enemyDestroyed, this, &GameController::handleEnemyDestroyed);

}

void GameController::handleEnemyDestroyed(Enemy* destroyedEnemy) {
    if (destroyedEnemy) {
        enemies.removeOne(destroyedEnemy); //Function to remove the enemy from the QList
        delete destroyedEnemy; //Delete the destroyed enemy
    }
}

void GameController::handleEnemyDissapeared(Enemy* enemy){
    std::cout << "In the handleEnemyDissapeared function, the player health and the enemy health are: " << playerHealth << " " << enemy->getHealth();
    playerHealth -= enemy->getHealth();
    if(playerHealth <= 0){
        std::cout << "In the handleEnemyDissapeared function in game controller, emitting playerLost() NOW... ";
        emit playerLost();
    }
}

void GameController::handlePlayerLost(){
    //Handles the player lost signal by deleting the scene and showing options to start new game etc.
}

void GameController::handleTileSelected(){
    for(QGraphicsRectItem* tile: map->tiles){
        if(tile->isSelected()){ //Check if the tile is selected
            // std::cout<< "I am here in the if condition and doing stuff and goodies... " << std::endl;
            // std::cout<<"the index x is: " << tile->x() << "and the index y is: " << tile->y() << std::endl;
            CannonTower* newCannon = new CannonTower(map, tile->x(),tile->y()); //Add a new cannon
            tile->setFlag(QGraphicsItem::ItemIsSelectable, false);  //Prohibit towers from forming on top of one another
        }
    }
}
