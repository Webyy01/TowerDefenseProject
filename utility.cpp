#include "Utility.h"
#include <cmath>
#include <QList>

double calculateDistance(const QPointF& from, const QPointF& to) {
    return std::sqrt(std::pow(from.x() - to.x(), 2) + std::pow(from.y() - to.y(), 2));
}

Enemy* findClosestEnemyWithinRange(QGraphicsScene* scene, const QPointF& towerPosition, double range) {
    QList<QGraphicsItem*> items = scene->items(QRectF(towerPosition - QPointF(range, range), QSizeF(2 * range, 2 * range)));
    Enemy* closestEnemy = nullptr;
    double minDistance = range;

    for (QGraphicsItem* item : items) {
        Enemy* enemy = dynamic_cast<Enemy*>(item);
        if (enemy) {
            double distance = calculateDistance(towerPosition, enemy->pos());
            if (distance < minDistance) {
                minDistance = distance;
                closestEnemy = enemy;
            }
        }
    }
    return closestEnemy;
}

std::vector<Enemy*> findAllEnemiesWithinRange(QGraphicsScene* scene, const QPointF& towerPosition, double range) {
    QList<QGraphicsItem*> items = scene->items(QRectF(towerPosition - QPointF(range, range), QSizeF(2 * range, 2 * range)));
    std::vector<Enemy*> enemies;

    for (QGraphicsItem* item : items) {
        Enemy* enemy = dynamic_cast<Enemy*>(item);
        if (enemy && calculateDistance(towerPosition, enemy->pos()) <= range) {
            enemies.push_back(enemy);
        }
    }
    return enemies;
}

void fireProjectileAt(QGraphicsScene* scene, Enemy* enemy, int damage) {
    Bullet* bullet = new Bullet();
    bullet->setPos(enemy->pos());
    bullet->setDamage(damage);
    scene->addItem(bullet);
}

void fireChainLightningAt(QGraphicsScene* scene, Enemy* enemy, int damage) {
    QList<QGraphicsItem*> nearEnemies = scene->items(QRectF(enemy->pos() - QPointF(100, 100), QSizeF(200, 200)));
    int chainCount = 0;

    for (QGraphicsItem* item : nearEnemies) {
        if (chainCount >= 3) break;
        Enemy* target = dynamic_cast<Enemy*>(item);
        if (target) {
            target->takeDamage(damage);
            chainCount++;
        }
    }
}

void causeSplashDamageToNearbyEnemies(QGraphicsScene* scene, Enemy* enemy, double splashRange, int splashDamage) {
    QList<QGraphicsItem*> nearItems = scene->items(QRectF(enemy->pos() - QPointF(splashRange, splashRange), QSizeF(2 * splashRange, 2 * splashRange)));
    for (QGraphicsItem* item : nearItems) {
        Enemy* nearbyEnemy = dynamic_cast<Enemy*>(item);
        if (nearbyEnemy && calculateDistance(enemy->pos(), nearbyEnemy->pos()) <= splashRange) {
            nearbyEnemy->takeDamage(splashDamage);
        }
    }
}
