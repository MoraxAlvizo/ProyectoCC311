#include "../include/Line.h"


Line::Line(GLint x, GLint y):
    Figure(x, y, LINE)
{


}

Line::~Line()
{
    //dtor
}

int Line::signo(int num)
{

    if(num<0)return -1;
    if(num>0) return 1;
    return 0;

}


 void Line::calcule(bool draw){

    GLint dx,dy,p;
    GLfloat m;
    Point temp;
    int x, y;
    Point i = inicial, f = final;
    points.clear();
    Glib::ustring text;
    int contador = 0;
    char cont[50];
    buffer->set_text("");
    sprintf(cont,"%10s\t|\t%10s\t|\t%s \n","K", "PK", "[Xk+1, Yk+1]");
    buffer->set_text(buffer->get_text().append("Linea - Algoritmo Bresenham\n\n"));
    buffer->set_text(buffer->get_text().append(cont));
    buffer->set_text(buffer->get_text().append("-----------------------------------------------------------------------------------------------------\n"));



    if(i.getX() > f.getX()){

        temp = i;
        i = f;
        f = temp;

    }

    if(i.getX() == f.getX()){

        if(i.getY() > f.getY()){
            temp = i;
            i = f;
            f = temp;
        }
        x = i.getX();
        y = i.getY();
        while(y < f.getY())
            points.push_back(Point(x, y++));
    }
    else if(i.getY() == f.getY()){
        x = i.getX();
        y = i.getY();
        while(x < f.getX())
            points.push_back(Point(x++, y));
    }
    else{
        m = (float)(f.getY() - i.getY())/(f.getX()-i.getX());

        if(m > 0){
            if(m <= 1){

                x = i.getX();
                y = i.getY();
                dx = std::abs(i.getX() - f.getX());
                dy = std::abs(i.getY() - f.getY());
                p  = 2 * dy - dx;
                while(x < f.getX())
                {
                    x++;
                    if(p < 0)
                    {
                        p = p + 2*dy;
                    }
                    else
                    {
                        y ++;
                        p = p + 2 *(dy - dx);
                    }
                    points.push_back(Point(x, y));
                    if(!draw){
                        sprintf(cont,"%10d\t|\t%10d\t|\t[ %10d , %10d ] \n",contador, p, x,y);
                        buffer->set_text(buffer->get_text().append(cont));
                        contador++;
                    }
                }
            }
            else{
                x = i.getX();
                y = i.getY();
                dx = std::abs(i.getX() - f.getX());
                dy = std::abs(i.getY() - f.getY());
                p  = 2 * dx - dy;
                while(y < f.getY())
                {
                    y++;
                    if(p < 0)
                    {
                        p = p + 2*dx;
                    }
                    else
                    {
                        x ++;
                        p = p + 2 *(dx - dy);
                    }
                    points.push_back(Point(x, y));
                    if(!draw){
                        sprintf(cont,"%10d\t|\t%10d\t|\t[ %10d , %10d ] \n",contador, p, x,y);
                        buffer->set_text(buffer->get_text().append(cont));
                        contador++;
                    }

                }
            }
        }
        else{
            m = std::abs(m);
            if(m < 1){
                x = i.getX();
                y = i.getY();
                dx = std::abs(i.getX() - f.getX());
                dy = std::abs(i.getY() - f.getY());
                p  = 2 * dy - dx;

                while(x < f.getX())
                {
                    x++;
                    if(p < 0)
                    {
                        p = p + 2*dy;
                    }
                    else
                    {
                        y --;
                        p = p + 2 *(dy - dx);
                    }
                    points.push_back(Point(x, y));
                    if(!draw){
                        sprintf(cont,"%10d\t|\t%10d\t|\t[ %10d , %10d ] \n",contador, p, x,y);
                        buffer->set_text(buffer->get_text().append(cont));
                        contador++;
                    }

                }
            }
            else{
                x = i.getX();
                y = i.getY();
                dx = std::abs(i.getX() - f.getX());
                dy = std::abs(i.getY() - f.getY());
                p  = 2 * dx - dy;
                while(y > f.getY())
                {
                    y--;
                    if(p < 0)
                    {
                        p = p + 2*dx;
                    }
                    else
                    {
                        x ++;
                        p = p + 2 *(dx - dy);
                    }
                    points.push_back(Point(x, y));
                    if(!draw){
                        sprintf(cont,"%10d\t|\t%10d\t|\t[ %10d , %10d ] \n",contador, p, x,y);
                        buffer->set_text(buffer->get_text().append(cont));
                        contador++;
                    }

                }
            }

        }

    }// fin del else


 }
