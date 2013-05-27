#include "../include/Circle.h"

Circle::Circle(GLint x, GLint y):
    Figure(x,y)
{
    //ctor
}

Circle::~Circle()
{
    //dtor
}

void Circle::calcCircle(){
    int x,y,p;

    points.clear();
	x = 0;
	y = std::sqrt( pow(inicial.getX()-final.getX(),2) + pow(inicial.getY()-final.getY(),2));
	applySymmetry(x, y);
	p = 1 - y;
	while(x<y)
	{
		if(p<0)
		{
			x++;
			p +=  2 * x + 1;
		}
		else{
			x++;
			y--;
			p += 2 * (x - y) + 1;
		}
		applySymmetry(x, y);
	}

}


void Circle::applySymmetry(GLint x, GLint y)
{

    points.push_back(Point(inicial.getX() + x, inicial.getY() + y));
    points.push_back(Point(inicial.getX() - x, inicial.getY() + y));
    points.push_back(Point(inicial.getX() + x, inicial.getY() - y));
    points.push_back(Point(inicial.getX() - x, inicial.getY() - y));
    points.push_back(Point(inicial.getX() + y, inicial.getY() + x));
    points.push_back(Point(inicial.getX() - y, inicial.getY() + x));
    points.push_back(Point(inicial.getX() + y, inicial.getY() - x));
    points.push_back(Point(inicial.getX() - y, inicial.getY() - x));

}
