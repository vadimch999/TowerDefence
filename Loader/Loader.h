#ifndef SFMLPROJECT_LOADER_H
#define SFMLPROJECT_LOADER_H

#include "../TemplateTable/TemplateTable.h"
#include "EnemyData/EnemyInfo.h"

class Loader {
private:
    Table<int, EnemyData> enemyTable;
public:
    Loader();
    void createTable();
    void loadTable();
    void showTable();

};

#endif
