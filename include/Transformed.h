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
        void mirror1(Figure *);
        void mirror2(Figure *);
        void mirror3(Figure *);
        void mirror4(Figure *);
        void mirror5(Figure *);
        void mirror6(Figure *);
        void setFinalPoint(Point);
        Point getInicialFigurePoint();
        Point getFinalFigurePoint();
    protected:
        Point inicial;
        Point final;
        Point figureInicial;
        Point figureFinal;
    private:
};

#endif // TRANSFORMED_H
