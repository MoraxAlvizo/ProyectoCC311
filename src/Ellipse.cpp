#include "../include/Ellipse.h"

Ellipse::Ellipse(GLint x, GLint y):
    Figure(x , y)
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
	long p, px, py, x, y, ry2, rx2, tworx2, twory2;

	points.clear();

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

    char cont[200];

    if(draw){
        points.push_back(Point(inicial.getX() + x, inicial.getY() + y));
        points.push_back(Point(inicial.getX() - x, inicial.getY() + y));
        points.push_back(Point(inicial.getX() + x, inicial.getY() - y));
        points.push_back(Point(inicial.getX() - x, inicial.getY() - y));
    }
    else{
        sprintf(cont,"%d\t%d\t\t[ %d , %d ][ %d , %d ][ %d , %d ][ %d , %d ]\t%d\t%d\n",contador,p,
                               inicial.getX() + x, inicial.getY() + y,
                               inicial.getX() - x, inicial.getY() + y,
                               inicial.getX() + x, inicial.getY() - y,
                               inicial.getX() - x, inicial.getY() - y,
                               _2ry2 * x,
                               _2rx2 * y

                );
        buffer->set_text(buffer->get_text().append(cont));
    }

}

