#include "Liar.h"

Liar::Liar(const Point &p): coordinats(p), enemiesCount(0), enemyTime(0) {
    liarTexture.loadFromFile("/home/vadim/CLionProjects/SFMLproject/Images/Liar.jpg");
    liarSprite.setTexture(liarTexture);
}

void Liar::sendEnemy() {
    Enemy walkingEnemy;
    walkingEnemy.setPoint(coordinats.x, coordinats.y);
    walkingEnemy.getSprite().setPosition(coordinats.x, coordinats.y);
    enemiesCount += 1;
    enemyTime += 3;
    EnemyInfo info;
    info.entranceTime = enemyTime;
    info.enemy = walkingEnemy;
    mapEnemies.insert(std::pair<int, EnemyInfo>(enemiesCount, info));
}

void Liar::setPoint(double x, double y) {
    coordinats.x = x;
    coordinats.y = y;
}

sf::Sprite &Liar::getSprite() {
    return liarSprite;
}

std::map<int, EnemyInfo>& Liar::getMap() {
    return mapEnemies;
}