#include "../include/Ellipse.h"

Ellipse::Ellipse(GLint x, GLint y):
    Figure(x , y, ELIPSE)
{
    //ctor
}

Ellipse::~Ellipse()
{
    //dtor
}


 void Ellipse::calcule(bool draw){

    GLint rx = std::abs(inicial.getX() - final.getX());
    GLint ry = std::abs(inicial.getY() - final.getY());
    int contador = 0;
    char cont[500];
	long p, px, py, x, y, ry2, rx2, tworx2, twory2;

    if(draw)
        points.clear();
	buffer->set_text("Elipse -  Algoritmo de punto medio\n\n");
    sprintf(cont,"%10s\t|\t%15s\t|\t%15s\t|\t%15s\t|\t%s\n","K","Pk","2ry2Xk+1","2rx2Yk+1","[Xk+1, Yk+1]");
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

	ry2 = ry * ry;
	rx2 = rx * rx;
	twory2 = 2 * ry2;
	tworx2 = 2 * rx2;

	//region1
	x = 0;
	y = ry;
	p = ceil(ry2 - rx2 * ry + (0.25 * rx2));
	applySymmetry(x,y,draw,contador,p, tworx2, twory2);
	px = 0;
	py = tworx2 * y;
	while(px < py)
	{
		x++;
		px += twory2;
		if(p >= 0)
		{
			y--;
			py  -= tworx2;
		}
		if(p<0)
			p+= ry2 + px;
		else
			p+= ry2 + px - py;
        contador++;
		applySymmetry(x,y,draw,contador,p, tworx2, twory2);

	}
	//region 2
	p = ceil(ry2 * (x + 0.5) * (x + 0.5) + rx2 * (y-1) * (y-1) - rx2 * ry2);
	while(y > 0)
	{

		y--;
		py -= tworx2;
		if(p <= 0)
		{
			x++;
			px += twory2;
		}
		if(p>0)
			p += rx2 -py;
		else
			p += rx2 -py + px;
        contador++;
		applySymmetry(x,y,draw,contador, p, tworx2, twory2);
	}
}

void Ellipse::applySymmetry(GLint x, GLint y, bool draw,GLint contador, GLint p, GLint _2rx2, GLint _2ry2){

    char cont[500];

    if(draw){
        points.push_back(Point(inicial.getX() + x, inicial.getY() + y));
        points.push_back(Point(inicial.getX() - x, inicial.getY() + y));
        points.push_back(Point(inicial.getX() + x, inicial.getY() - y));
        points.push_back(Point(inicial.getX() - x, inicial.getY() - y));
    }
    else{
        sprintf(cont,"%10d\t|\t%15d\t|\t%15d\t|\t%15d\t|\t[ %8d , %8d ][ %8d , %8d ][ %8d , %8d ][ %8d , %8d ]\n",
                               contador,p,_2ry2 * x,_2rx2 * y,
                               inicial.getX() + x, inicial.getY() + y,
                               inicial.getX() - x, inicial.getY() + y,
                               inicial.getX() + x, inicial.getY() - y,
                               inicial.getX() - x, inicial.getY() - y

                );
        buffer->set_text(buffer->get_text().append(cont));
    }

}

