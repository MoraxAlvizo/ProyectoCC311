#ifndef APP_H
#define APP_H

#include <gtkmm.h>
#include <gtkglmm.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "ToolsMenu.h"
#include "drawingOpenGL.h"
#include "ColorWindow.h"


class App : public Gtk::Window
{
    public:
        App();
        virtual ~App();



    protected:
        // member widgets:
        DrawingOpenGL GL;
        Gtk::ColorSelection colorSelection;
        ColorWindow colorWindow;
        Gtk::VBox box;
        Gtk::VBox colorBox;
        ToolsMenu toolsMenu;
        //Signal handlers:
        void on_button_quit();
        void on_switch_page (GtkNotebookPage* page, guint page_num);

        Gtk::Notebook pestana;
        Gtk::ScrolledWindow sWindow;
        Gtk::TextView textView;
        Gtk::RadioButton bRadioMirrow1;
        Gtk::RadioButton bRadioMirrow2;
        Gtk::RadioButton bRadioMirrow3;
        Gtk::RadioButton bRadioMirrow5;
        Gtk::RadioButton bRadioMirrow6;

        void onButtonMirror1 ();
        void onButtonMirror2 ();
        void onButtonMirror3 ();
        void onButtonMirror5 ();
        void onButtonMirror6 ();

};



#endif // APP_H
