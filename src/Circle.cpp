#include "../include/Circle.h"

Circle::Circle(GLint x, GLint y):
    Figure(x,y, CIRCLE)
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
    char cont[200];
    if(draw)
        points.clear();
    buffer->set_text("Circulo -  Algoritmo de punto medio\n\n");
    sprintf(cont,"%8s\t|\t%8s\t|\t%8s\t|\t%8s\t|\t%s\n", "K","Pk","2xk+1","2yk+1","(Xk+1, Yk+1)");
    buffer->set_text(buffer->get_text().append(cont));
    buffer->set_text(buffer->get_text().append("----------------------------------------"
                                               "----------------------------------------"
                                               "----------------------------------------"
                                               "----------------------------------------"
                                               "----------------------------------------"
                                               "----------------------------------------"
                                               "----------------------------------------"
                                               "----------------------------------------"
                                               "----------------------------------------"
                                               "\n"));

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
    char cont[600];

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
        sprintf(cont,"%8d\t|\t%8d\t|\t%8d\t|\t%8d\t|\t[ %8d , %8d ][ %8d , %8d ][ %8d , %8d ][ %8d , %8d ]"
                     "[ %8d , %8d ][ %8d , %8d ][ %8d , %8d ][ %8d , %8d ]\n",
                               contador,p,x * 2,y * 2,
                               inicial.getX() + x, inicial.getY() + y,
                               inicial.getX() - x, inicial.getY() + y,
                               inicial.getX() + x, inicial.getY() - y,
                               inicial.getX() - x, inicial.getY() - y,
                               inicial.getX() + y, inicial.getY() + x,
                               inicial.getX() - y, inicial.getY() + x,
                               inicial.getX() + y, inicial.getY() - x,
                               inicial.getX() - y, inicial.getY() - x

                );
        buffer->set_text(buffer->get_text().append(cont));
    }

}
