#ifndef SFMLPROJECT_CASTLE_H
#define SFMLPROJECT_CASTLE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Point.h"


/**
 * @brief
 * Реализация замка
 * @details
 * Класс - замок. Замок может быть размещен только в одной точке плоскости. Имеет прочность, замок уничтожается, если прочность заканчивается.
 * Имеет запас золота. За счёт золота можно ставить башни. Если золота нет - башню поставить не удастся.
 */


class Castle {
private:
    bool isAlive;
    std::string name;
    sf::Texture castleTexture;
    sf::Sprite castleSprite;
    /**
     * @brief Текущая прочность замка
     */
    int currentEndurance;
    /**
     * @brief Максимальная прочность замка
     */
    int maxEndurance;
    /**
     * @brief Текущее количество золота в замке
     */
    int gold;
    Point coordinats;
public:
    Castle();
    Castle(std::string &_name, const Point &_p);
    Castle(std::string &_name, int _currentEndurance, int _maxEndurance, int _gold, const Point &_p);
    void setGold(int _gold);
    [[nodiscard]] int getGold() const;
    sf::Sprite& getSprite();
    void setPoint(double x, double y);
    Point getPoint();
    [[nodiscard]] int getEndurance() const;
    void setEndurance(int _currentEndurance);
    /**
     * @return Возвращает состояние замка: уничтожен или существует.
     */
    bool getAlive() const { return isAlive; }
    void setAlive() { isAlive = false; }
};

#endif
