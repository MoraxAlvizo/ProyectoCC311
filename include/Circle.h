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
        void calcule(bool);
    private:
        void applySymmetry(GLint x, GLint y, bool, GLint, GLint);
        GLint _2x;
        GLint _2y;
};

#endif // CIRCLE_H
