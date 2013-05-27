#include "../include/Figure.h"

Figure::Figure(GLint x, GLint y)
{
    //ctor
    this->inicial = Point(x,y);
}

Figure::~Figure()
{
    //dtor
    points.clear();
}

void Figure::setFinalPoint(Point final){
    this->final = final;

 }

void Figure::draw()
{
    for(unsigned int i = 0; i < points.size(); i++)
        points[i].drawPoint();
}
