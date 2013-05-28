#include "../include/App.h"

App::App():
    GL(&toolsMenu),
    box(false, 3),
    toolsMenu(false),
    bRadioMirrow1("1"),
    bRadioMirrow2("2"),
    bRadioMirrow3("3"),
    bRadioMirrow5("5"),
    bRadioMirrow6("6")
{
    set_title("App");

    pestana.set_border_width(10);
    sWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
    // Get automatically redrawn if any of their children changed allocation.
    set_reallocate_redraws(true);
    add(pestana);
    sWindow.add(textView);
    textView.set_editable(false);

    //radios buttons
    Gtk::RadioButton::Group group = bRadioMirrow1.get_group();
    bRadioMirrow1.set_group(group);
    bRadioMirrow2.set_group(group);
    bRadioMirrow3.set_group(group);
    bRadioMirrow5.set_group(group);
    bRadioMirrow6.set_group(group);

    //add radio buttons
    toolsMenu.addMirrowsButtons(&bRadioMirrow1, &bRadioMirrow2, &bRadioMirrow3,
                                &bRadioMirrow5, &bRadioMirrow6);

    //events
    bRadioMirrow1.signal_pressed ().connect(sigc::mem_fun(*this, &App::onButtonMirror1));
    bRadioMirrow2.signal_pressed ().connect(sigc::mem_fun(*this, &App::onButtonMirror2));
    bRadioMirrow3.signal_pressed ().connect(sigc::mem_fun(*this, &App::onButtonMirror3));
    bRadioMirrow5.signal_pressed ().connect(sigc::mem_fun(*this, &App::onButtonMirror5));
    bRadioMirrow6.signal_pressed ().connect(sigc::mem_fun(*this, &App::onButtonMirror6));

    //Add the Notebook pages:
    pestana.append_page(box, "Drawing Area");
    pestana.append_page(sWindow, "Dates");
    pestana.add(box);
    pestana.signal_switch_page().connect(sigc::mem_fun(*this, &App::on_switch_page) );
    GL.set_size_request(1000, 600);

    box.pack_start(toolsMenu);
    box.pack_start(GL);
    maximize ();
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

void App::onButtonMirror1 (){
    GL.mirrior(1);
}

void App::onButtonMirror2 (){
    GL.mirrior(2);
}

void App::onButtonMirror3 (){
    GL.mirrior(3);
}


void App::onButtonMirror5 (){
    GL.mirrior(5);
}

void App::onButtonMirror6 (){
    GL.mirrior(6);
}
