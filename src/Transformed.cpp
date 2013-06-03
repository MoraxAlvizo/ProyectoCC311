#include "../include/Transformed.h"

#include <iostream>

Transformed::Transformed(GLint x, GLint y, Point figureInicial, Point figureFinal)
{
    //ctor
    inicial = Point( x, y);
    this->figureInicial = figureInicial;
    this->figureFinal   = figureFinal;
}

Transformed::~Transformed()
{
    //dtor
}

void Transformed::rotate(Figure* figure){

    GLfloat angulo = atan2(final.getY() -inicial.getY(), final.getX() -inicial.getX());
    GLfloat seno   = std::sin(angulo) ;
    GLfloat coseno = std::cos(angulo) ;
    GLfloat tx     = inicial.getX() * (1.0f - coseno) + inicial.getY() * seno;
    GLfloat ty     = inicial.getY() * (1.0f - coseno) - inicial.getX() * seno;

    GLfloat mat[3][3] = {
        { coseno , -seno  , tx},
        { seno   ,  coseno, ty},
        { 0.0f   ,  0.0f  , 1.0f},
    };

    figure->setInicialPoint(figureInicial);
    figure->setFinalPoint(figureFinal);
    figure->calcule(true);
    figure->drawCopy();


    figure->setInicialPoint(
                            Point(
                                  (mat[0][X] * figureInicial.getX() + mat[0][Y] * figureInicial.getY() + mat[0][2] * 1),
                                  (mat[1][X] * figureInicial.getX() + mat[1][Y] * figureInicial.getY() + mat[1][2] * 1)
                                  )
                            );
    figure->setFinalPoint(
                            Point(
                                  (mat[0][X] * figureFinal.getX() + mat[0][Y] * figureFinal.getY() + mat[0][2] * 1),
                                  (mat[1][X] * figureFinal.getX() + mat[1][Y] * figureFinal.getY() + mat[1][2] * 1)
                                  )
                            );

}

void Transformed::scale(Figure* figure){

    GLfloat sx = std::abs( (final.getX() - inicial.getX())/10.0f );
    GLfloat sy = std::abs( (final.getY() - inicial.getY())/10.0f );

    GLfloat mat[3][3] = {
        { sx , 0  , (GLfloat)(inicial.getX()*(1 - sx))},
        { 0  , sy , (GLfloat)(inicial.getY()*(1 - sy))},
        { 0  , 0  , 1},
    };

    figure->setInicialPoint(figureInicial);
    figure->setFinalPoint(figureFinal);
    figure->calcule(true);
    figure->drawCopy();

    figure->setInicialPoint(
                            Point(
                                  (mat[0][X] * figureInicial.getX() + mat[0][Y] * figureInicial.getY() + mat[0][2] * 1),
                                  (mat[1][X] * figureInicial.getX() + mat[1][Y] * figureInicial.getY() + mat[1][2] * 1)
                                  )
                            );
    figure->setFinalPoint(
                            Point(
                                  (mat[0][X] * figureFinal.getX() + mat[0][Y] * figureFinal.getY() + mat[0][2] * 1),
                                  (mat[1][X] * figureFinal.getX() + mat[1][Y] * figureFinal.getY() + mat[1][2] * 1)
                                  )
                            );

}

void Transformed::move(Figure* figure){


    GLint tx = final.getX() - inicial.getX();
    GLint ty = final.getY() - inicial.getY();

    figure->setInicialPoint(figureInicial);
    figure->setFinalPoint(figureFinal);
    figure->calcule(true);
    figure->drawCopy();

    figure->setInicialPoint(
                            Point(
                                  (figureInicial.getX() + tx ),
                                  (figureInicial.getY() + ty )
                                  )
                            );
    figure->setFinalPoint(
                            Point(
                                  (figureFinal.getX() + tx ),
                                  (figureFinal.getY() + ty )
                                  )
                            );
}

void Transformed::mirror1(Figure* figure){

    GLint mat[3][3] = {
        { 1  , 0  , 0},
        { 0  , -1 , 0},
        { 0  , 0  , 1},
    };
    std::cout << "Entro mirror 1" << std::endl;

    figure->setInicialPoint(
                            Point(
                                  (mat[0][X] * figureInicial.getX() + mat[0][Y] * figureInicial.getY() + mat[0][2] * 1),
                                  (mat[1][X] * figureInicial.getX() + mat[1][Y] * figureInicial.getY() + mat[1][2] * 1)
                                  )
                            );
    figure->setFinalPoint(
                            Point(
                                  (mat[0][X] * figureFinal.getX() + mat[0][Y] * figureFinal.getY() + mat[0][2] * 1),
                                  (mat[1][X] * figureFinal.getX() + mat[1][Y] * figureFinal.getY() + mat[1][2] * 1)
                                  )
                            );

}

void Transformed::mirror2(Figure* figure){

    GLint mat[3][3] = {
        {-1  , 0  , 0},
        { 0  , 1  , 0},
        { 0  , 0  , 1},
    };

    figure->setInicialPoint(
                            Point(
                                  (mat[0][X] * figureInicial.getX() + mat[0][Y] * figureInicial.getY() + mat[0][2] * 1),
                                  (mat[1][X] * figureInicial.getX() + mat[1][Y] * figureInicial.getY() + mat[1][2] * 1)
                                  )
                            );
    figure->setFinalPoint(
                            Point(
                                  (mat[0][X] * figureFinal.getX() + mat[0][Y] * figureFinal.getY() + mat[0][2] * 1),
                                  (mat[1][X] * figureFinal.getX() + mat[1][Y] * figureFinal.getY() + mat[1][2] * 1)
                                  )
                            );

}

void Transformed::mirror3(Figure* figure){

    GLint mat[3][3] = {
        {-1  , 0  , 0},
        { 0  , -1 , 0},
        { 0  , 0  , 1},
    };

    figure->setInicialPoint(
                            Point(
                                  (mat[0][X] * figureInicial.getX() + mat[0][Y] * figureInicial.getY() + mat[0][2] * 1),
                                  (mat[1][X] * figureInicial.getX() + mat[1][Y] * figureInicial.getY() + mat[1][2] * 1)
                                  )
                            );
    figure->setFinalPoint(
                            Point(
                                  (mat[0][X] * figureFinal.getX() + mat[0][Y] * figureFinal.getY() + mat[0][2] * 1),
                                  (mat[1][X] * figureFinal.getX() + mat[1][Y] * figureFinal.getY() + mat[1][2] * 1)
                                  )
                            );

}

void Transformed::mirror4(Figure* figure){

    GLfloat angulo = M_PI;
    GLfloat seno   = std::sin(angulo) ;
    GLfloat coseno = std::cos(angulo) ;
    GLfloat tx     = inicial.getX() * (1.0f - coseno) + inicial.getY() * seno;
    GLfloat ty     = inicial.getY() * (1.0f - coseno) - inicial.getX() * seno;

    GLfloat mat[3][3] = {
        { coseno , -seno  , tx},
        { seno   ,  coseno, ty},
        { 0.0f   ,  0.0f  , 1.0f},
    };

    figure->setInicialPoint(
                            Point(
                                  (mat[0][X] * figureInicial.getX() + mat[0][Y] * figureInicial.getY() + mat[0][2] * 1),
                                  (mat[1][X] * figureInicial.getX() + mat[1][Y] * figureInicial.getY() + mat[1][2] * 1)
                                  )
                            );
    figure->setFinalPoint(
                            Point(
                                  (mat[0][X] * figureFinal.getX() + mat[0][Y] * figureFinal.getY() + mat[0][2] * 1),
                                  (mat[1][X] * figureFinal.getX() + mat[1][Y] * figureFinal.getY() + mat[1][2] * 1)
                                  )
                            );

}

void Transformed::mirror5(Figure* figure){

    GLint mat[3][3] = {
        { 0  , 1  , 0},
        { 1  , 0  , 0},
        { 0  , 0  , 1},
    };

    figure->setInicialPoint(
                            Point(
                                  (mat[0][X] * figureInicial.getX() + mat[0][Y] * figureInicial.getY() + mat[0][2] * 1),
                                  (mat[1][X] * figureInicial.getX() + mat[1][Y] * figureInicial.getY() + mat[1][2] * 1)
                                  )
                            );
    figure->setFinalPoint(
                            Point(
                                  (mat[0][X] * figureFinal.getX() + mat[0][Y] * figureFinal.getY() + mat[0][2] * 1),
                                  (mat[1][X] * figureFinal.getX() + mat[1][Y] * figureFinal.getY() + mat[1][2] * 1)
                                  )
                            );

}

void Transformed::mirror6(Figure* figure){

    GLint mat[3][3] = {
        { 0  , -1 , 0},
        { -1 , 0  , 0},
        { 0  , 0  , 1},
    };

    figure->setInicialPoint(
                            Point(
                                  (mat[0][X] * figureInicial.getX() + mat[0][Y] * figureInicial.getY() + mat[0][2] * 1),
                                  (mat[1][X] * figureInicial.getX() + mat[1][Y] * figureInicial.getY() + mat[1][2] * 1)
                                  )
                            );
    figure->setFinalPoint(
                            Point(
                                  (mat[0][X] * figureFinal.getX() + mat[0][Y] * figureFinal.getY() + mat[0][2] * 1),
                                  (mat[1][X] * figureFinal.getX() + mat[1][Y] * figureFinal.getY() + mat[1][2] * 1)
                                  )
                            );

}

void Transformed::setFinalPoint(Point final){
    this->final = final;
}

Point Transformed::getInicialFigurePoint(){
    return figureFinal;
}

Point Transformed::getFinalFigurePoint(){
    return figureInicial;
}
