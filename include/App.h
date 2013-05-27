#ifndef APP_H
#define APP_H

#include <gtkmm.h>
#include <gtkglmm.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "ToolsMenu.h"
#include "drawingOpenGL.h"


class App : public Gtk::Window
{
    public:
        App();
        virtual ~App();



    protected:
        // member widgets:
        DrawingOpenGL GL;
        Gtk::VBox box;
        ToolsMenu toolsMenu;
        //Signal handlers:
        void on_button_quit();
        void on_switch_page (GtkNotebookPage* page, guint page_num);

        Gtk::Notebook pestana;
        Gtk::ScrolledWindow sWindow;
        Gtk::TextView textView;

};



#endif // APP_H
