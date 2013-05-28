#ifndef DRAWINGOPENGL_H
#define DRAWINGOPENGL_H

#include <iostream>
#include <gtkmm.h>
#include <gtkglmm.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <vector>
#include "ToolsMenu.h"
#include "Point.h"
#include "Line.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Polygon.h"
#include "Transformed.h"

enum{
    R,
    G,
    B
};

class DrawingOpenGL :
    public Gtk::DrawingArea,
    public Gtk::GL::Widget<DrawingOpenGL>
{
    public:
        DrawingOpenGL(ToolsMenu* );
        virtual ~DrawingOpenGL();
        bool primerPintado;
        int drawing;
        int selected;
        ToolsMenu* menu;
        Transformed* transform;
        std::vector<Figure*> figuras;
        std::vector<Polygon*> polygons;
        Figure * figure;

        void buscarFigura(GLint , GLint);
        Figure* getLastFigura();
        void mirrior(int );


    protected:
        //atributos
        Point pointRelease;

        void on_realize();
        virtual bool on_expose_event(GdkEventExpose* event);
        virtual bool on_button_press_event(GdkEventButton* event);
        virtual bool on_motion_notify_event(GdkEventMotion* event);
        virtual bool on_button_release_event(GdkEventButton* event);
        virtual bool on_configure_event (GdkEventConfigure*event);
        virtual bool on_enter_notify_event (GdkEventCrossing*event);

        void drawOrigin();
};


#endif // DRAWINGOPENGL_H
