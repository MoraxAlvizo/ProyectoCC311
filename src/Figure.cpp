#include "../include/Figure.h"

Figure::Figure(GLint x, GLint y, int tipo)
{
    //ctor
    this->inicial = Point(x,y);
    this->final = Point(x,y);
    buffer = Gtk::TextBuffer::create();
    this->tipo = tipo;
}

Figure::~Figure()
{
    //dtor
    points.clear();
}

void Figure::setInicialPoint(Point inicial){
    this->inicial = inicial;
}

void Figure::setFinalPoint(Point final){
    this->final = final;

 }

Point Figure::getInicialPoint(){
    return inicial;

}

Point Figure::getFinalPoint(){
    return final;

}

void Figure::draw()
{
    for(unsigned int i = 0; i < points.size(); i++)
        points[i].drawPoint();
}

void Figure::drawCopy()
{
    int patron = 0;
    for(unsigned int i = 0; i < points.size(); i++){
        if(patron > 0 && patron <= 70)
            points[i].drawPoint();
        if(patron == 140)
            patron = 0;
        patron++;
    }

}


std::vector<Point> Figure::getPoints(){
    return points;
}

void Figure::setPoints(std::vector<Point> points){
    this->points = points;
}

Glib::RefPtr<Gtk::TextBuffer> Figure::getBuffer(){
    return buffer;
}

int Figure::getType(){
    return tipo;
}
bool Figure::buscarPunto(GLint x, GLint y){

    Point point = Point(x,y);

    for(unsigned int i = 0; i < points.size(); i++){
        if(point == points[i])
            return true;
    }
    return false;

}
