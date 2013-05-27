#include "../include/Polygon.h"

Polygon::Polygon(GLint x, GLint y, GLshort faces):
    Figure(x , y)
{
    //ctor
    this->faces = faces;
}

Polygon::~Polygon()
{
    //dtor
}

void Polygon::calcPolygon(){


    GLint  ang = 360/ faces, l;
    GLint radio = std::sqrt( pow(inicial.getX()-final.getX(),2) + pow(inicial.getY()-final.getY(),2));
    GLfloat a = atan2(final.getY() -inicial.getY(), final.getX() -inicial.getX()) * 180 /M_PI;

    points.clear();
    vertex.clear();

    if(a<0)a=360+a;

    for(l = 0;l<faces;l++)
    {
        polar(inicial.getX(), inicial.getY(), radio, a, l);
        a+= ang;
    }


}

void Polygon::polar(GLint x, GLint y,GLint r,GLfloat a, GLint pos){

    int radian = 180/M_PI;
    vertex.push_back(Point(x + ceil( r * cos(a/radian)), y + ceil( r * sin(a/radian))));

}

void Polygon::draw(){

    glBegin(GL_LINES);
    for(int i = 1; i<faces ; i++){

        glVertex2i(vertex[i-1].getX(), vertex[i-1].getY());
        glVertex2i(vertex[i].getX(), vertex[i].getY());

    }
    glVertex2i(vertex[faces-1].getX(), vertex[faces-1].getY());
    glVertex2i(vertex[0].getX(), vertex[0].getY());
    glEnd();

}
