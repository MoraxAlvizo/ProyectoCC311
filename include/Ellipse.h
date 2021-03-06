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
        void calcule(bool);
    protected:
    private:
        void applySymmetry(GLint x, GLint y, bool, GLint, GLint, GLint, GLint);
};

#endif // ELLIPSE_H
