#include "Effect.h"

/*
 * 1 - замедление
 * 2 - отравление
 * 3 - ослабление
 */

Effect::Effect(): time(10), type(0), value(10) {}

Effect::Effect(int _time, int _type, int _value): time(_time), type(_type), value(_value) {}
