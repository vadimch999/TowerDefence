#ifndef SFMLPROJECT_LIAR_H
#define SFMLPROJECT_LIAR_H

#include "../Enemy/Enemy.h"
#include "../Point.h"
#include <vector>
#include "SFML/Graphics.hpp"

/**
 * @brief
 * Структура, хранящая время выхода врага, а также информацию о самом враге.
 */

struct EnemyInfo {
    float entranceTime;
    Enemy enemy;
};

/**
 * @brief
 * Класс - логово, в нём создаются враги.
 * @details
 * Логово не может быть уничтожено, оно создает врагов либо с каким-то интервалом времени, либо при заданном порядке,
 * считаемого из файла.
 */

class Liar {
private:
    /**
     * @brief Количество всех отправленных врагов.
     */
    int enemiesCount;
    /**
     * @brief Интервал времени, через которое отправляется новый враг.
     */
    float enemyTime;
    sf::Texture liarTexture;
    sf::Sprite liarSprite;
    Point coordinats;
    /**
     * @brief Словарь, в котором хранятся все отправленные враги.
     */
    std::map<int, EnemyInfo> mapEnemies;
public:
    explicit Liar(const Point &p);
    /**
     * @brief Функция по отправке врага из логова. Враг добавляется в словарь с уникальным ключом.
     */
    void sendEnemy();
    sf::Sprite& getSprite();
    void setPoint(double x = 0, double y = 0);
    /**
     * @return Возвращается словарь, хранящий всех врагов и информацию о них.
     */
    std::map<int, EnemyInfo>& getMap();
};

#endif
