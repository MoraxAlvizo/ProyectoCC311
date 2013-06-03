#include "../include/Polygon.h"

Polygon::Polygon(GLint x, GLint y, GLshort faces):
    Figure(x , y, POLYGON)
{
    //ctor
    this->faces = faces;
}

Polygon::~Polygon()
{
    //dtor
}


void Polygon::calcule(){


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

bool Polygon::buscarPunto(GLint x, GLint y){

    // Se obtiene el ultimo punto
    Point inicial = vertex[faces - 1];
    Point final, temp;
    Point punto_buscar = Point(x,y);
    float b;
    float m;
    float res;

    for (int j = 0; j < faces; j++){
        final = vertex[j];

        /*if (inicial.getX() > final.getX()){
            temp = inicial;
            inicial.setX(final.getX());
            final.setX(temp.getX());
        }
        if (inicial.getY() > final.getY()){
            temp = inicial;
            inicial.setY(final.getY());
            final.setY(temp.getY());
        }*/

        m = ((float)final.getY() - (float)inicial.getY()) / ((float)final.getX() - (float)inicial.getX());
        b = (float)inicial.getY() - m*(float)inicial.getX();
        res = (float)punto_buscar.getY() - m*(float)punto_buscar.getX() - b;
        if ( res >= -1 && res <= 1)
            return true;
        inicial = final;
    }
    return false;
}

void Polygon::polar(GLint x, GLint y,GLint r,GLfloat a, GLint pos){

    int radian = 180/M_PI;
    vertex.push_back(Point(x + ceil( r * cos(a/radian)), y + ceil( r * sin(a/radian))));

}

void Polygon::draw(){

    if(vertex.size() != 0){
        glBegin(GL_LINES);
        for(int i = 1; i<faces ; i++){

            glVertex2i(vertex[i-1].getX(), vertex[i-1].getY());
            glVertex2i(vertex[i].getX(), vertex[i].getY());

        }
        glVertex2i(vertex[faces-1].getX(), vertex[faces-1].getY());
        glVertex2i(vertex[0].getX(), vertex[0].getY());
        glEnd();
    }


}

void Polygon::drawCopy(){
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(2, 0x00FF);
    if(vertex.size() != 0){
        glBegin(GL_LINES);
        for(int i = 1; i<faces ; i++){

            glVertex2i(vertex[i-1].getX(), vertex[i-1].getY());
            glVertex2i(vertex[i].getX(), vertex[i].getY());

        }
        glVertex2i(vertex[faces-1].getX(), vertex[faces-1].getY());
        glVertex2i(vertex[0].getX(), vertex[0].getY());
        glEnd();
    }
    glDisable(GL_LINE_STIPPLE);

}
