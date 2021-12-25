#ifndef SFMLPROJECT_TOWER_H
#define SFMLPROJECT_TOWER_H

#include <SFML/Graphics.hpp>
#include "../Point.h"
#include "../Enemy/Enemy.h"

/**
 * @brief
 * Класс башня, уничтожающая врагов.
 * @details
 * С помощью клика мышки ставится башня, если враг попадает в радиус действия башня, то по нему наносится определённый урон, может
 * наложиться эффект. Башни можно ставить до тех пор, пока есть золото у замка. Башня наносит урон раз в какое-то время.
 */

class Tower {
private:
    /**
     * @brief Текущий уровень башни. Определяет её способности.
     */
    int level;
    sf::Texture towerTexture;
    sf::Sprite towerSprite;
    Point coordinats;
protected:
    int cost;
    int radius;
    int damage;
    int rate;
public:
    Tower();
    explicit Tower(const Point &_p);
    /**
     * @brief Размещение башни по клику мышки
     * @param enemy Передача врага, чтобы проверить, в каком радиусе от башни он находится.
     * @param positionX Координата башни по X
     * @param positionY Координата башни по Y
     * @param time Текущее время, чтобы задать, когда башня может наносить урон.
     */
    void putTower(Enemy &enemy, double positionX, double positionY, float time);
    sf::Sprite& getSprite();
    void setPoint(double x = 0, double y = 0);
    Point getPoint();
};

#endif
