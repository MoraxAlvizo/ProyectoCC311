#ifndef LINE_H
#define LINE_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <cmath>
#include "Figure.h"
#include "Point.h"

class Line:
    public Figure
{
    public:
        Line(GLint x, GLint y);
        virtual ~Line();

        /** Metodos **/
        void calcule(bool);

    private:
        int signo(int);
};

#endif // LINE_H
