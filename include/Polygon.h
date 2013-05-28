#ifndef POLYGON_H
#define POLYGON_H

#include <cmath>
#include <vector>
#include "Figure.h"
#include "Line.h"

class Polygon:
    public Figure
{
    public:
        Polygon(GLint, GLint, GLshort);
        virtual ~Polygon();
        void calcule();
        void draw();
    protected:
        GLshort faces;
        std::vector<Point> vertex;
        bool buscarPunto(GLint, GLint);
        void polar(GLint x, GLint y,GLint r,GLfloat a, GLint pos);
    private:
};

#endif // POLYGON_H
