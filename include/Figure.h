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
        void draw();
    protected:
        Point   inicial;
        Point   final;
        std::vector<Point> points;
    private:
};

#endif // FIGURE_H
