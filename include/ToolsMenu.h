#ifndef TOOLSMENU_H
#define TOOLSMENU_H

#include <gtkmm.h>
#include <gtkglmm.h>
#include <GL/gl.h>
#include <GL/glu.h>


#define    LINE         0
#define    CIRCLE       1
#define    ELIPSE       2
#define    TRIANGULE    3
#define    RECTANGULE   4
#define    PENTAGONO    5
#define    HEXAGONO     6
#define    HEPTAGONO    7
#define    ROTATE       8
#define    MOVE         9
#define    DRAW         10
#define    SCALE        11


class ToolsMenu:
    public Gtk::HBox
{
    public:
        ToolsMenu(bool);
        virtual ~ToolsMenu();
        /** Members **/
        int figura;
        int action;
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
        Gtk::Button bRotate;
        Gtk::Button bMove;
        Gtk::Button bScale;
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
        void onButtonRotate ();
        void onButtonMove ();
        void onButtonScale ();
};

#endif // TOOLSMENU_H
