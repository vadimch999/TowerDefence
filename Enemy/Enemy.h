#ifndef SFMLPROJECT_ENEMY_H
#define SFMLPROJECT_ENEMY_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Point.h"
#include "../Castle/Castle.h"
#include "../Effect/Effect.h"
#include <cmath>

/**
 * @brief
 * Класс врагов.
 * @details
 * Враг имеет способность двигаться к замку, понижать его запас здоровья может только башня или ловушка. При уничтожении
 * врага замку начисляется запас золота, враг имеет скорость движения.
 */

class Enemy {
private:
    /**
     * @brief
     * Состояние врага: жив или мертв.
     */
    bool isAlive;
    std::string name;
    sf::Texture enemyTexture;
    sf::Sprite enemySprite;
    int maxHealth;
    int currentHealth;
    double speed;
    Point coordinats;
    int effectsCounter;
    std::map<int, Effect> effects;

public:
    Enemy();
    Enemy(std::string &_name, const Point &_p);
    Enemy(std::string &_name, int _maxHealth, int _currentHealth, int _speed, const Point &_p);
    /**
     * @brief Перегруженный оператор присваивания
     * @param enemy Передаётся враг
     * @return Возвращается враг с корректно заданными текстурой и спрайтом.
     */
    Enemy& operator = (const Enemy& enemy);
    sf::Sprite& getSprite();
    void setPoint(double x = 0, double y = 0);
    Point getPoint();
    /**
     * @param fortress Передаётся замок, чтобы понять, где он расположен.
     * @param time Передается текущее время
     * @return Возвращается update состояние врага
     */
    Enemy& move(Castle &fortress, float time);
    void setAlive() { isAlive = false; }
    bool getAlive() const { return isAlive; }
    void setHealth(int _currentHealth) { currentHealth = _currentHealth; }
    int isHealth() const { return currentHealth; }
    std::map<int, Effect>& getMap();
    int getEffectCounter() const;
    void setEffectCounter(int _counter);
};

#endif
