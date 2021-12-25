#ifndef SFMLPROJECT_SLOWEFFECT_H
#define SFMLPROJECT_SLOWEFFECT_H

#include "../Effect/Effect.h"
#include "../Enemy/Enemy.h"

class SlowEffect: public Effect {
    SlowEffect();
    virtual void applyEffect(Enemy &enemy) {
        // mapEnemies.insert(std::pair<int, EnemyInfo>(enemiesCount, info));
        enemy.setEffectCounter(enemy.getEffectCounter() + 1);
        enemy.getMap().insert(std::pair<int, Effect>(enemy.getEffectCounter(), SlowEffect));
    }
};

#endif
