#ifndef TRANSFORMED_H
#define TRANSFORMED_H

#include <cmath>
#include "Figure.h"

enum{
    X,
    Y
};

class Transformed
{
    public:
        Transformed(GLint ,GLint ,Point, Point);
        virtual ~Transformed();
        void rotate(Figure*);
        void move(Figure *);
        void scale(Figure *);
        void setFinalPoint(Point);
    protected:
        Point inicial;
        Point final;
        Point figureInicial;
        Point figureFinal;
    private:
};

#endif // TRANSFORMED_H
