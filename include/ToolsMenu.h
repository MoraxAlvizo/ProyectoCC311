#ifndef TOOLSMENU_H
#define TOOLSMENU_H

#include <gtkmm.h>
#include <gtkglmm.h>
#include <GL/gl.h>
#include <GL/glu.h>

enum{
    LINE,
    CIRCLE,
    ELIPSE,
    TRIANGULE,
    RECTANGULE,
    PENTAGONO,
    HEXAGONO,
    HEPTAGONO
};

class ToolsMenu:
    public Gtk::HBox
{
    public:
        ToolsMenu(bool);
        virtual ~ToolsMenu();
        /** Members **/
        int figura;
        GLfloat color[3];
        GLfloat* getColor ();

    protected:

        /** Botones **/
        Gtk::Button bLine;
        Gtk::Button bCircle;
        Gtk::Button bElipse;
        Gtk::Button bTriangulo;
        Gtk::Button bRectangule;
        Gtk::Button bPentagono;
        Gtk::Button bHexagono;
        Gtk::Button bHeptagono;
        Gtk::Image* m_image;


        /** Metodos **/
        void onButtonLine();
        void onButtonCircle();
        void onButtonEllipse ();
        void onButtonTriangule ();
        void onButtonRectangule ();
        void onButtonPentagono ();
        void onButtonHexagono ();
        void onButtonHeptagono ();
};

#endif // TOOLSMENU_H
