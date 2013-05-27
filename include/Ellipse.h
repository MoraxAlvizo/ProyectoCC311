#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <cmath>
#include "Figure.h"

class Ellipse:
    public Figure
{
    public:
        Ellipse(GLint, GLint);
        virtual ~Ellipse();
        void calcEllipse();
    protected:
    private:
        void applySymmetry(GLint x, GLint y);
};

#endif // ELLIPSE_H
