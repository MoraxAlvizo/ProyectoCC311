#include "../include/ToolsMenu.h"
#include <iostream>

ToolsMenu::ToolsMenu(bool flag):
    HBox(flag, 12),
    bMirrowButton4("4")
{
    /** Inserción de iconos**/

    m_image=new Gtk::Image("icons/seleccionar.png");
    bSeleccionar.set_image_position(Gtk::POS_LEFT);
    bSeleccionar.set_image(*m_image);

    m_image=new Gtk::Image("icons/line.png");
    bLine.set_image_position(Gtk::POS_LEFT);
    bLine.set_image(*m_image);

    m_image=new Gtk::Image("icons/circle.png");

    bCircle.set_image_position(Gtk::POS_LEFT);
    bCircle.set_image(*m_image);

    m_image=new Gtk::Image("icons/elipse.png");

    bElipse.set_image_position(Gtk::POS_LEFT);
    bElipse.set_image(*m_image);

    m_image=new Gtk::Image("icons/triangle.png");

    bTriangulo.set_image_position(Gtk::POS_LEFT);
    bTriangulo.set_image(*m_image);

    m_image=new Gtk::Image("icons/rectangle.png");

    bRectangule.set_image_position(Gtk::POS_LEFT);
    bRectangule.set_image(*m_image);

    m_image=new Gtk::Image("icons/pentagon.png");

    bPentagono.set_image_position(Gtk::POS_LEFT);
    bPentagono.set_image(*m_image);

    m_image=new Gtk::Image("icons/hexagon.png");

    bHexagono.set_image_position(Gtk::POS_LEFT);
    bHexagono.set_image(*m_image);

    m_image=new Gtk::Image("icons/octagon.png");

    bHeptagono.set_image_position(Gtk::POS_LEFT);
    bHeptagono.set_image(*m_image);

    m_image=new Gtk::Image("icons/rotate.png");

    bRotate.set_image_position(Gtk::POS_LEFT);
    bRotate.set_image(*m_image);

    m_image=new Gtk::Image("icons/move.png");

    bMove.set_image_position(Gtk::POS_LEFT);
    bMove.set_image(*m_image);

    m_image=new Gtk::Image("icons/scale.png");

    bScale.set_image_position(Gtk::POS_LEFT);
    bScale.set_image(*m_image);

    bLine.signal_clicked().connect(sigc::mem_fun(*this, &ToolsMenu::onButtonLine));
    bCircle.signal_clicked().connect(sigc::mem_fun(*this, &ToolsMenu::onButtonCircle));
    bElipse.signal_clicked().connect(sigc::mem_fun(*this, &ToolsMenu::onButtonEllipse));
    bTriangulo.signal_clicked().connect(sigc::mem_fun(*this, &ToolsMenu::onButtonTriangule));
    bRectangule.signal_clicked().connect(sigc::mem_fun(*this, &ToolsMenu::onButtonRectangule));
    bPentagono.signal_clicked().connect(sigc::mem_fun(*this, &ToolsMenu::onButtonPentagono));
    bHexagono.signal_clicked().connect(sigc::mem_fun(*this, &ToolsMenu::onButtonHexagono));
    bHeptagono.signal_clicked().connect(sigc::mem_fun(*this, &ToolsMenu::onButtonHeptagono));
    bRotate.signal_clicked().connect(sigc::mem_fun(*this, &ToolsMenu::onButtonRotate));
    bMove.signal_clicked().connect(sigc::mem_fun(*this, &ToolsMenu::onButtonMove));
    bScale.signal_clicked().connect(sigc::mem_fun(*this, &ToolsMenu::onButtonScale));
    bSeleccionar.signal_clicked().connect(sigc::mem_fun(*this, &ToolsMenu::onButtonSeleccionar));
    bMirrowButton4.signal_pressed ().connect(sigc::mem_fun(*this, &ToolsMenu::onButtonMirror4));


    pack_start(bSeleccionar);
    pack_start(bLine);
    pack_start(bCircle);
    pack_start(bElipse);
    pack_start(bTriangulo);
    pack_start(bRectangule);
    pack_start(bPentagono);
    pack_start(bHexagono);
    pack_start(bHeptagono);
    pack_start(bRotate);
    pack_start(bMove);
    pack_start(bScale);

    this->figura = SELECCIONAR;

}

ToolsMenu::~ToolsMenu()
{
    //dtor
}

void ToolsMenu::onButtonLine()
{
    figura = LINE;
    action = DRAW;
}

void ToolsMenu::onButtonCircle()
{
    figura = CIRCLE;
    action = DRAW;
}

void ToolsMenu::onButtonEllipse()
{
    figura = ELIPSE;
    action = DRAW;
}

void ToolsMenu::onButtonTriangule()
{
    figura = TRIANGULE;
    action = DRAW;
}

void ToolsMenu::onButtonRectangule ()
{
    figura = RECTANGULE;
    action = DRAW;
}

void ToolsMenu::onButtonPentagono ()
{
    figura = PENTAGONO;
    action = DRAW;
}

void ToolsMenu::onButtonHexagono ()
{
    figura = HEXAGONO;
    action = DRAW;
}

void ToolsMenu::onButtonHeptagono ()
{
    figura = OCTAGON;
    action = DRAW;
}

void ToolsMenu::onButtonSeleccionar (){
    action = SELECCIONAR;
}

void ToolsMenu::onButtonRotate ()
{
    action = ROTATE;
}

void ToolsMenu::onButtonMove ()
{
    action = MOVE;
}

void ToolsMenu::onButtonScale ()
{
    action = SCALE;
}

void ToolsMenu::onButtonMirror4 (){
    std::cout << "Ntro al 4" << std::endl;
    action = MIRROR4;
}

void ToolsMenu::addMirrowsButtons(Gtk::RadioButton* bMirrowButton1, Gtk::RadioButton* bMirrowButton2,
                                  Gtk::RadioButton* bMirrowButton3,
                                  Gtk::RadioButton* bMirrowButton5, Gtk::RadioButton* bMirrowButton6){

        m_image=new Gtk::Image("icons/mirror.png");

        pack_start(*m_image);
        pack_start(*bMirrowButton1);
        pack_start(*bMirrowButton2);
        pack_start(*bMirrowButton3);

        //radios buttons
        Gtk::RadioButton::Group group = (*bMirrowButton1).get_group();
        bMirrowButton4.set_group(group);
        pack_start(bMirrowButton4);
        pack_start(*bMirrowButton5);
        pack_start(*bMirrowButton6);


}
