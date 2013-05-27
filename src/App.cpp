#include "../include/App.h"

App::App():
    GL(&toolsMenu),
    box(false, 3),
    toolsMenu(false)
{
    set_title("App");

    pestana.set_border_width(10);
    sWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
    // Get automatically redrawn if any of their children changed allocation.
    set_reallocate_redraws(true);
    add(pestana);
    sWindow.add(textView);
    textView.set_editable(false);

    //Add the Notebook pages:
    pestana.append_page(box, "Drawing Area");
    pestana.append_page(sWindow, "Dates");
    pestana.add(box);
    pestana.signal_switch_page().connect(sigc::mem_fun(*this, &App::on_switch_page) );
    GL.set_size_request(1000, 600);

    box.pack_start(toolsMenu);
    box.pack_start(GL);

    // Show window.
    show_all();
}

App::~App()
{

}

void App::on_switch_page (GtkNotebookPage*  page, guint page_num)
{

    switch(page_num){
        case 0:
        break;
        case 1:
        {
            switch(toolsMenu.figura){
                case LINE:
                {
                    Line * figure = (Line *)GL.getLastFigura();
                    if(figure!= NULL){
                        figure->calcule(false);
                        textView.set_buffer(figure->getBuffer());
                    }
                    break;
                }
                case CIRCLE:
                {
                    Circle * figure = (Circle *)GL.getLastFigura();
                    if(figure!= NULL){
                        figure->calcule(false);
                        textView.set_buffer(figure->getBuffer());
                    }
                    break;
                }
                case ELIPSE:
                {
                    Ellipse * figure = (Ellipse *)GL.getLastFigura();
                    if(figure!= NULL){
                        figure->calcule(false);
                        textView.set_buffer(figure->getBuffer());
                    }
                    break;
                }
            }

            break;
        }


    }

  //You can also use m_Notebook.get_current_page() to get this index.
}
