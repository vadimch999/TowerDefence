#ifndef SFMLPROJECT_EFFECT_H
#define SFMLPROJECT_EFFECT_H

/**
 * @brief
 * Класс эффект.
 * @details
 * Накладывает определённый эффект на врага. Существуют три вида эффекта.
 */

class Effect {
protected:
    int time;
    int type;
    int value;
public:
    Effect();
    Effect(int _time, int _type, int _value);
    virtual void applyEffect() = 0;
};

#endif
