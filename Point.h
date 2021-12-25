#ifndef SFMLPROJECT_POINT_H
#define SFMLPROJECT_POINT_H

/**
 * @brief
 * Точка - координата конкретного объекта в данный момент времени.
 */

struct Point {
    double x;
    double y;
    Point(): x(0), y(0) {};
    Point(const Point &p): x(p.x), y(p.y) {};
};


#endif
