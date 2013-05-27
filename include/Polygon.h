#ifndef POLYGON_H
#define POLYGON_H

#include <cmath>
#include <vector>
#include "Figure.h"

class Polygon:
    public Figure
{
    public:
        Polygon(GLint, GLint, GLshort);
        virtual ~Polygon();
        void calcPolygon();
        void draw();
    protected:
        GLshort faces;
        std::vector<Point> vertex;
        void polar(GLint x, GLint y,GLint r,GLfloat a, GLint pos);
    private:
};

#endif // POLYGON_H
