#include "Game/Game.h"
#include "Loader/Loader.h"
#include <iostream>

/**
 * @mainpage TowerDefence
 * @brief Игра в защиту башен. Есть крепость, башни, враги и логово. Задача поставить башни, чтобы недопустить врагов к замку.
 * @author Лебедев Вадим Андреевич [Б20-505]
 * @date 23.10.2021
 *
 */

int main() {
    Loader load;
    load.loadTable();
    load.showTable();
    // game();
    return 0;
}