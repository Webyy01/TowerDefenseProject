#ifndef UTILITY_H
#define UTILITY_H

#include <QPointF>
#include <QGraphicsScene>
#include <vector>
#include "Enemy.h"
#include "Bullet.h"

double calculateDistance(const QPointF& from, const QPointF& to);
Enemy* findClosestEnemyWithinRange(QGraphicsScene* scene, const QPointF& towerPosition, double range);
std::vector<Enemy*> findAllEnemiesWithinRange(QGraphicsScene* scene, const QPointF& towerPosition, double range);
void fireProjectileAt(QGraphicsScene* scene, Enemy* enemy, int damage);
void fireChainLightningAt(QGraphicsScene* scene, Enemy* enemy, int damage);
void causeSplashDamageToNearbyEnemies(QGraphicsScene* scene, Enemy* enemy, double splashRange, int splashDamage);

#endif // UTILITY_H
