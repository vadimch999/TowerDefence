#include "Tower.h"

Tower::Tower(): level(1), coordinats(), cost(50), radius(40), damage(50), rate(5) {
    towerTexture.loadFromFile("/home/vadim/CLionProjects/SFMLproject/Images/Tower.jpg");
    towerSprite.setTexture(towerTexture);
}

Tower::Tower(const Point &_p): level(1), coordinats(_p), cost(50), radius(40), damage(50), rate(5) {
    towerTexture.loadFromFile("/home/vadim/CLionProjects/SFMLproject/Images/Tower.jpg");
    towerSprite.setTexture(towerTexture);
}

void Tower::setPoint(double x, double y) {
    coordinats.x = x;
    coordinats.y = y;
}

sf::Sprite &Tower::getSprite() {
    return towerSprite;
}

Point Tower::getPoint() {
    return coordinats;
}

void Tower::putTower(Enemy &enemy, double positionX, double positionY, float time) {
    coordinats.x = positionX;
    coordinats.y = positionY;
    towerSprite.setPosition(coordinats.x, coordinats.y);
    double distance = sqrt((enemy.getPoint().x - coordinats.x) * (enemy.getPoint().x - coordinats.x) +
            (enemy.getPoint().y - coordinats.y) * (enemy.getPoint().y - coordinats.y));
    if (distance < radius && time > 3) {
        enemy.setHealth(enemy.isHealth() - damage);
        if (enemy.isHealth() <= 0)
            enemy.setAlive();
    }
}