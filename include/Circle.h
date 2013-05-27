#ifndef CIRCLE_H
#define CIRCLE_H
#include "Figure.h"
#include <cmath>

class Circle:
    public Figure
{
    public:
        Circle(GLint, GLint);
        virtual ~Circle();
        /** Metodos **/
        void calcCircle();
    private:
        void applySymmetry(GLint x, GLint y);
};

#endif // CIRCLE_H
