#include "../include/drawingOpenGL.h"

DrawingOpenGL::DrawingOpenGL(ToolsMenu* menu)
{
    Glib::RefPtr<Gdk::GL::Config> glconfig;
    this->drawing = -1;
    this->primerPintado = true;
    this->menu = menu;

    this->add_events(Gdk::BUTTON_PRESS_MASK |
                     Gdk::BUTTON_RELEASE_MASK |
                     Gdk::BUTTON1_MOTION_MASK |
                     Gdk::EXPOSURE_MASK|
                     Gdk::ENTER_NOTIFY_MASK);
    glconfig = Gdk::GL::Config::create(Gdk::GL::MODE_RGB | Gdk::GL::MODE_SINGLE);


    if( !glconfig )
        g_assert_not_reached();

    set_gl_capability(glconfig);

}

DrawingOpenGL::~DrawingOpenGL()
{

}


void DrawingOpenGL::on_realize()
{
  // We need to call the base on_realize()
    Gtk::DrawingArea::on_realize();

}

bool DrawingOpenGL::on_configure_event(GdkEventConfigure*event){

    Glib::RefPtr<Gdk::GL::Context>  context;
	Glib::RefPtr<Gdk::GL::Drawable> gldrawable;
    GLint w = get_width(), h = get_height();

	context = get_gl_context();
	gldrawable = get_gl_drawable();

    gldrawable->gl_begin(context);

	glLoadIdentity();
	glViewport (0,0, w, h);
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glPointSize(2);

	glMatrixMode(GL_PROJECTION);

	gluOrtho2D(0.0, w, 0.0, h);
    glFlush();
	gldrawable->gl_end();

	glEnable(GL_LINE_STIPPLE);

	return TRUE;

}

bool DrawingOpenGL::on_expose_event(GdkEventExpose* event)
{
    Glib::RefPtr<Gdk::GL::Context>  context;
	Glib::RefPtr<Gdk::GL::Drawable> gldrawable;
	gint w = get_width(), h = get_height();

	context = get_gl_context();
	gldrawable = get_gl_drawable();

	if (!gldrawable->gl_begin(context)){
		g_assert_not_reached ();
	}
	if(primerPintado){
		glClear(GL_COLOR_BUFFER_BIT);
		primerPintado = false;
		crearBufferPixeles();
		glReadPixels(0, 0, w, h, GL_RGB, GL_UNSIGNED_BYTE, lienzo);

	}else{
		glDrawPixels(w, h, GL_RGB, GL_UNSIGNED_BYTE, lienzo);
	}

    glFlush();
	gldrawable -> gl_end();
	return true;
}

bool DrawingOpenGL::on_button_press_event(GdkEventButton* event) {


    Glib::RefPtr<Gdk::GL::Context>  context;
	Glib::RefPtr<Gdk::GL::Drawable> gldrawable;
    GLint w = get_width(), h = get_height();

    context = get_gl_context();
	gldrawable = get_gl_drawable();
	gldrawable->gl_begin(context);


    glReadPixels(0, 0, w, h, GL_RGB, GL_UNSIGNED_BYTE, lienzo);

    glColor3i(0,0,0);
    switch(menu->figura){
        case LINE:
            figuras.push_back(new Line(event->x,  h - event->y ));
            break;
        case CIRCLE:
            figuras.push_back(new Circle(event->x,  h - event->y ));
            break;
        case ELIPSE:
            figuras.push_back(new Ellipse(event->x,  h - event->y ));
            break;
        case TRIANGULE:
            figuras.push_back(new Polygon(event->x,  h - event->y ,3));
            break;
        case RECTANGULE:
            figuras.push_back(new Polygon(event->x,  h - event->y ,4));
            break;
        case PENTAGONO:
            figuras.push_back(new Polygon(event->x,  h - event->y ,5));
            break;
        case HEXAGONO:
            figuras.push_back(new Polygon(event->x,  h - event->y ,6));
            break;
        case HEPTAGONO:
            figuras.push_back(new Polygon(event->x,  h - event->y ,7));
            break;

    }

    glFlush();
    gldrawable -> gl_end();
    return true;
}

bool DrawingOpenGL::on_motion_notify_event(GdkEventMotion* event) {

    Glib::RefPtr<Gdk::GL::Context>  context;
	Glib::RefPtr<Gdk::GL::Drawable> gldrawable;
    GLint w = get_width(), h = get_height();

    context = get_gl_context();
	gldrawable = get_gl_drawable();
	gldrawable->gl_begin(context);
    //Eventos del mouse

    glDrawPixels(w, h, GL_RGB, GL_UNSIGNED_BYTE, lienzo);

    if(event->state & GDK_BUTTON1_MASK){

        switch(menu->figura){
            case LINE:
            {
                Line* linea = (Line *)figuras.back();
                linea->setFinalPoint(Point(event->x, h - event->y ));
                linea->calcLine();
                linea->draw();
                break;

            }

            case CIRCLE:
            {
                Circle* circle = (Circle *)figuras.back();
                circle->setFinalPoint(Point(event->x, h - event->y ));
                circle->calcCircle();
                circle->draw();
                break;

            }
            case ELIPSE:
            {
                Ellipse* elipse = (Ellipse *)figuras.back();
                elipse->setFinalPoint(Point(event->x, h - event->y ));
                elipse->calcEllipse();
                elipse->draw();
                break;

            }
            case TRIANGULE:
            case RECTANGULE:
            case PENTAGONO:
            case HEXAGONO:
            case HEPTAGONO:
            {
                Polygon* polygon = (Polygon *)figuras.back();
                polygon->setFinalPoint(Point(event->x, h - event->y ));
                polygon->calcPolygon();
                polygon->draw();
                break;

            }


        }
    }

    glFlush();
    gldrawable -> gl_end();


    return true;
}

bool DrawingOpenGL::on_button_release_event(GdkEventButton* event){

    Glib::RefPtr<Gdk::GL::Context>  context;
	Glib::RefPtr<Gdk::GL::Drawable> gldrawable;

    context = get_gl_context();
	gldrawable = get_gl_drawable();
	gldrawable->gl_begin(context);

    glFlush();
    gldrawable -> gl_end();
    return true;
}

bool DrawingOpenGL::on_enter_notify_event(GdkEventCrossing* event){

    return true;
}


void DrawingOpenGL::crearBufferPixeles(){

    GLint w = get_width(), h = get_height();
    lienzo = new GLint [w*h];
}
