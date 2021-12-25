#include "Castle.h"

Castle::Castle(): isAlive(true), name("Castle"), currentEndurance(200), maxEndurance(1000), gold(0), coordinats() {
    castleTexture.loadFromFile("/home/vadim/CLionProjects/SFMLproject/Images/Castle.jpg");
    castleSprite.setTexture(castleTexture);
};

Castle::Castle(std::string &_name, const Point &_p): isAlive(true), name(_name), currentEndurance(1000), maxEndurance(1000), gold(0), coordinats(_p) {
    castleTexture.loadFromFile("/home/vadim/CLionProjects/SFMLproject/Images/Castle.jpg");
    castleSprite.setTexture(castleTexture);
};

Castle::Castle(std::string &_name, int _currentEndurance, int _maxEndurance, int _gold, const Point &_p): isAlive(true), name(_name),
                                                    currentEndurance(_currentEndurance), maxEndurance(_maxEndurance), gold(_gold), coordinats(_p)
{
    castleTexture.loadFromFile("/home/vadim/CLionProjects/SFMLproject/Images/Castle.jpg");
    castleSprite.setTexture(castleTexture);
};

void Castle::setGold(int _gold) {
    gold = _gold;
}

int Castle::getGold() const {
    return gold;
}

sf::Sprite& Castle::getSprite() {
    return castleSprite;
}

void Castle::setPoint(double x, double y) {
    coordinats.x = x;
    coordinats.y = y;
}

Point Castle::getPoint() {
    return coordinats;
}

int Castle::getEndurance() const {
    return currentEndurance;
}

void Castle::setEndurance(int _currentEndurance) {
    currentEndurance = _currentEndurance;
}