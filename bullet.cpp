#include "Bullet.h"

Bullet::Bullet() : damage(0) {
    // Constructor body can be expanded as necessary
}

void Bullet::setDamage(int newDamage) {
    damage = newDamage;
}

int Bullet::getDamage() const {
    return damage;
}
