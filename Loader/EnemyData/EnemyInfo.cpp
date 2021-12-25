#include "EnemyInfo.h"

EnemyData::EnemyData(): currentHealth(100), maxHealth(100), speed(10), coordinats() {}

EnemyData::EnemyData(int _maxHealth, int _currentHealth, double _speed, Point _coordinats):
                        maxHealth(_maxHealth), currentHealth(_currentHealth), speed(_speed), coordinats(_coordinats) {}

EnemyData::EnemyData(const EnemyData &enemyInfo): currentHealth(enemyInfo.currentHealth), maxHealth(enemyInfo.maxHealth),
                                                        speed(enemyInfo.speed), coordinats(enemyInfo.coordinats) {}

std::istream &operator>>(std::istream &in, EnemyData &enemyInfo) {
    in >> enemyInfo.maxHealth >> enemyInfo.currentHealth >> enemyInfo.speed >> enemyInfo.coordinats.x >> enemyInfo.coordinats.y;
    return in;
}

std::ostream &operator<<(std::ostream &out, const EnemyData &enemyInfo) {
    out << enemyInfo.maxHealth << " " << enemyInfo.currentHealth << " " << enemyInfo.speed << " " << enemyInfo.coordinats.x << " " << enemyInfo.coordinats.y;
    return out;
}