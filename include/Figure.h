#ifndef FIGURE_H
#define FIGURE_H

#include <vector>
#include <sstream>
#include <gtkmm.h>

#include "ToolsMenu.h"
#include "Point.h"
#define  POLYGON 13

class Figure
{
    public:
        Figure(GLint x, GLint y, int tipo);
        virtual ~Figure();
        void setFinalPoint(Point final);
        void setInicialPoint(Point inicial);
        Point getFinalPoint();
        Point getInicialPoint();
        virtual int getType();
        Glib::RefPtr<Gtk::TextBuffer> getBuffer();

        virtual void draw();
        virtual bool buscarPunto(GLint, GLint);
        std::vector<Point> getPoints();
        void setPoints(std::vector<Point>);
    protected:
        Point   inicial;
        Point   final;
        int     tipo;
        std::vector<Point> points;
        Glib::RefPtr<Gtk::TextBuffer> buffer;

};

#endif // FIGURE_H
