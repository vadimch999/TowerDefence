#include <iostream>
#include <fstream>
#include "Loader.h"

Loader::Loader(): enemyTable() {}

void Loader::loadTable() {
    std::ifstream enemyFile("/home/vadim/CLionProjects/SFMLproject/Config/EnemyInfo.txt");
    Pair<int, EnemyData> enemyPair;
    while (enemyFile >> enemyPair) {
        enemyTable.push(enemyPair);
    }
    enemyFile.close();
}

void Loader::showTable() {
    std::cout << "Enemy Table:" << std::endl;
    for (TabIterator<int, EnemyData> it = enemyTable.begin(); it != enemyTable.end(); ++it) {
        std::cout << (*it).key << " " << (*it).data << std::endl;
    }
}