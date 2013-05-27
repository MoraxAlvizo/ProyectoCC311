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

void Circle::calcule(bool draw){
    int x,y,p;
    int contador = 0;
    if(draw)
        points.clear();
	x = 0;
	y = std::sqrt( pow(inicial.getX()-final.getX(),2) + pow(inicial.getY()-final.getY(),2));
	p = 1 - y;
	applySymmetry(x, y, draw,p, contador);
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
		contador++;
		applySymmetry(x, y, draw, p, contador);
	}

}


void Circle::applySymmetry(GLint x, GLint y, bool draw, GLint p, GLint contador)
{
    char cont[200];

    if(draw){

        points.push_back(Point(inicial.getX() + x, inicial.getY() + y));
        points.push_back(Point(inicial.getX() - x, inicial.getY() + y));
        points.push_back(Point(inicial.getX() + x, inicial.getY() - y));
        points.push_back(Point(inicial.getX() - x, inicial.getY() - y));
        points.push_back(Point(inicial.getX() + y, inicial.getY() + x));
        points.push_back(Point(inicial.getX() - y, inicial.getY() + x));
        points.push_back(Point(inicial.getX() + y, inicial.getY() - x));
        points.push_back(Point(inicial.getX() - y, inicial.getY() - x));

    }
    else{
        sprintf(cont,"%d\t%d\t\t[ %d , %d ][ %d , %d ][ %d , %d ][ %d , %d ]"
                               "[ %d , %d ][ %d , %d ][ %d , %d ][ %d , %d ]\t%d\t%d\n",contador,p,
                               inicial.getX() + x, inicial.getY() + y,
                               inicial.getX() - x, inicial.getY() + y,
                               inicial.getX() + x, inicial.getY() - y,
                               inicial.getX() - x, inicial.getY() - y,
                               inicial.getX() + y, inicial.getY() + x,
                               inicial.getX() - y, inicial.getY() + x,
                               inicial.getX() + y, inicial.getY() - x,
                               inicial.getX() - y, inicial.getY() - x,
                               x * 2,
                               y * 2

                );
        buffer->set_text(buffer->get_text().append(cont));
    }

}
