#include "Game.h"
#include <iostream>
#include <fstream>

void game() {
    std::ifstream castleFile("/home/vadim/CLionProjects/SFMLproject/Config/CastleInfo.txt");
    int castleX, castleY;
    castleFile >> castleX >> castleY;
    std::cout << castleX << " " << castleY << std::endl;
    castleFile.close();
    bool putTower = false;
    float savedTime = 0, savedEnemyTime = 3;
    double putTowerx, putTowery;
    Castle fortress;
    Point liarPoint;
    liarPoint.x = 200, liarPoint.y = 350;
    Liar liarEnemies(liarPoint);
    liarEnemies.getSprite().setPosition(liarPoint.x, liarPoint.y);
    fortress.setPoint(600, 700);
    fortress.getSprite().setPosition(fortress.getPoint().x, fortress.getPoint().y);
    std::map<int, EnemyInfo>& mapEnemies = liarEnemies.getMap();
    std::map<int, EnemyInfo>::iterator it;
    std::map<int, Tower> mapTowers;
    std::map<int, Tower>::iterator itTower;
    //it = mapEnemies.find(1);
    sf::Clock clock;
    int towerCounter = 0;
    //Enemy enemy1;
    //enemy1.setPoint(100, 400);
    //enemy1.getSprite().setPosition(enemy1.getPoint().x, enemy1.getPoint().y);
    Tower tower;
    tower.setPoint(200, 300);
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    while (window.isOpen()) {
        float time = clock.getElapsedTime().asMicroseconds();
        float getTime = clock.getElapsedTime().asSeconds();
        float enemyTime = clock.getElapsedTime().asSeconds();
        savedTime += getTime;
        savedEnemyTime += enemyTime;
        clock.restart();
        time = time / 2000;
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    putTowerx = event.mouseButton.x;
                    putTowery = event.mouseButton.y;
                    tower.setPoint(putTowerx, putTowery);
                    putTower = true;
                    towerCounter += 1;
                    mapTowers.insert(std::pair<int, Tower>(towerCounter, tower));
                }
            }
        }
        window.clear(sf::Color{101, 240, 182});
        for (int i = 1; i <= mapTowers.size(); i++) {
            for (int j = 1; j <= mapEnemies.size(); j++) {
                it = mapEnemies.find(j);
                itTower = mapTowers.find(i);
                if (itTower != mapTowers.end() && it != mapEnemies.end()) {
                    itTower->second.putTower(it->second.enemy, itTower->second.getPoint().x, itTower->second.getPoint().y, savedTime);
                //    if (!(it->second.enemy.getAlive())) { mapEnemies.erase(it); }
                }
            }
        }
        if (savedEnemyTime > 3) {
            //std::cout << savedEnemyTime << std::endl;
            savedEnemyTime = 0;
            liarEnemies.sendEnemy();
            std::cout << mapEnemies.size() << std::endl;
        }
        for (int i = 1; i <= mapEnemies.size(); i++) {
            it = mapEnemies.find(i);
            if (it != mapEnemies.end()) {
               //  std::cout << tempEnemy.getPoint().x << " " << tempEnemy.getPoint().y << std::endl;
               // itTower->second.putTower(it->second.enemy, itTower->second.getPoint().x, itTower->second.getPoint().y, savedTime);
                it->second.enemy = it->second.enemy.move(fortress, time);
                //  std::cout << tempEnemy.getPoint().x << " " << tempEnemy.getPoint().y << std::endl;
                if (it->second.enemy.getAlive()) window.draw(it->second.enemy.getSprite());
            }
        }
        if (savedTime > 3) savedTime = 0;
        if (putTower) {
            for (int i = 1; i <= mapTowers.size(); i++) {
                itTower = mapTowers.find(i);
                if (itTower != mapTowers.end()) {
                    window.draw(itTower->second.getSprite());
                }
            }
        }
        window.draw(liarEnemies.getSprite());
        if (fortress.getAlive()) window.draw(fortress.getSprite());
        else window.close();
        window.display();
    }
}