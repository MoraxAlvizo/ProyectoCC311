#include "../include/ToolsMenu.h"

ToolsMenu::ToolsMenu(bool flag):
    HBox(flag, 12),
    bRotate("Rotar"),
    bMove("Mover"),
    bScale("Escalar")
{
    /** Inserción de iconos**/

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
    figura = HEPTAGONO;
    action = DRAW;
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
