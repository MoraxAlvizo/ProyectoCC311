#ifndef FIGURE_H
#define FIGURE_H

#include <vector>
#include <sstream>
#include "Point.h"
#include <gtkmm.h>

class Figure
{
    public:
        Figure(GLint x, GLint y);
        virtual ~Figure();
        void setFinalPoint(Point final);
        void setInicialPoint(Point inicial);
        Point getFinalPoint();
        Point getInicialPoint();
        Glib::RefPtr<Gtk::TextBuffer> getBuffer();

        void draw();
        std::vector<Point> getPoints();
        void setPoints(std::vector<Point>);
    protected:
        Point   inicial;
        Point   final;
        std::vector<Point> points;
        Glib::RefPtr<Gtk::TextBuffer> buffer;

};

#endif // FIGURE_H
