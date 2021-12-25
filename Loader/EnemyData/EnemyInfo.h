#ifndef SFMLPROJECT_ENEMYINFO_H
#define SFMLPROJECT_ENEMYINFO_H

#include "../../Point.h"
#include <iostream>

 struct EnemyData {
    int maxHealth;
    int currentHealth;
    double speed;
    Point coordinats;

    EnemyData();
    EnemyData(int _maxHealth, int _currentHealth, double _speed, Point _coordinats);
    EnemyData(const EnemyData &enemyInfo);
    friend std::istream &operator>>(std::istream &in, EnemyData &enemyInfo);
    friend std::ostream &operator<<(std::ostream &out, const EnemyData &enemyInfo);
};

#endif