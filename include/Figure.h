#ifndef FIGURE_H
#define FIGURE_H

#include <vector>
#include "Point.h"


class Figure
{
    public:
        Figure(GLint x, GLint y);
        virtual ~Figure();
        void setFinalPoint(Point final);
        void setInicialPoint(Point inicial);
        Point getFinalPoint();
        Point getInicialPoint();

        void draw();
        std::vector<Point> getPoints();
        void setPoints(std::vector<Point>);
    protected:
        Point   inicial;
        Point   final;
        std::vector<Point> points;

};

#endif // FIGURE_H
