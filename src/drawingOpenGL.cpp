#include "../include/drawingOpenGL.h"

DrawingOpenGL::DrawingOpenGL(ToolsMenu* menu)
{
    Glib::RefPtr<Gdk::GL::Config> glconfig;
    this->drawing = -1;
    this->primerPintado = true;
    this->menu = menu;
    this->transform = NULL;

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
    GLint  h = get_height();

    context = get_gl_context();
	gldrawable = get_gl_drawable();
	gldrawable->gl_begin(context);


    glClear(GL_COLOR_BUFFER_BIT);
    for(unsigned int i = 0; i < figuras.size(); i++)
        figuras[i]->draw();
    for(unsigned int i = 0; i < polygons.size(); i++)
        polygons[i]->draw();



    glColor3i(0,0,0);
    if(menu->action == DRAW){
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
                polygons.push_back(new Polygon(event->x,  h - event->y ,TRIANGULE));
                break;
            case RECTANGULE:
                polygons.push_back(new Polygon(event->x,  h - event->y ,RECTANGULE));
                break;
            case PENTAGONO:
                polygons.push_back(new Polygon(event->x,  h - event->y ,PENTAGONO));
                break;
            case HEXAGONO:
                polygons.push_back(new Polygon(event->x,  h - event->y ,HEXAGONO));
                break;
            case HEPTAGONO:
                polygons.push_back(new Polygon(event->x,  h - event->y ,HEPTAGONO));
                break;
        }

    }

    else{

            switch(menu->figura){
                case LINE:
                case CIRCLE:
                case ELIPSE:
                    if(!figuras.empty())
                        transform = new Transformed(event->x,  h - event->y ,figuras.back()->getInicialPoint(), figuras.back()->getFinalPoint());
                    break;
                case TRIANGULE:
                case RECTANGULE:
                case PENTAGONO:
                case HEXAGONO:
                case HEPTAGONO:
                    if(!polygons.empty())
                        transform = new Transformed(event->x,  h - event->y ,polygons.back()->getInicialPoint(), polygons.back()->getFinalPoint());
                    break;
            }
          }

    glFlush();
    gldrawable -> gl_end();
    return true;
}

bool DrawingOpenGL::on_motion_notify_event(GdkEventMotion* event) {

    Glib::RefPtr<Gdk::GL::Context>  context;
	Glib::RefPtr<Gdk::GL::Drawable> gldrawable;
    GLint h = get_height();

    context = get_gl_context();
	gldrawable = get_gl_drawable();
	gldrawable->gl_begin(context);
    //Eventos del mouse

    glClear(GL_COLOR_BUFFER_BIT);
    for(unsigned int i = 0; i < figuras.size(); i++)
        figuras[i]->draw();
    for(unsigned int i = 0; i < polygons.size(); i++)
        polygons[i]->draw();

    if(event->state & GDK_BUTTON1_MASK){

        switch(menu->figura){
            case LINE:
            {
                Line* linea = (Line *)figuras.back();

                switch(menu->action){
                    case MOVE:
                        transform->setFinalPoint(Point(event->x, h - event->y));
                        transform->move(linea);
                        break;
                    case ROTATE:
                        transform->setFinalPoint(Point(event->x, h - event->y));
                        transform->rotate(linea);
                        break;
                    case DRAW:
                        linea->setFinalPoint(Point(event->x, h - event->y ));
                        break;
                }
                linea->calcule();
                linea->draw();
                break;

            }

            case CIRCLE:
            {
                Circle* circle = (Circle *)figuras.back();

                switch(menu->action){
                    case MOVE:
                        transform->setFinalPoint(Point(event->x, h - event->y));
                        transform->move(circle);
                        break;
                    case ROTATE:
                        transform->setFinalPoint(Point(event->x, h - event->y));
                        transform->rotate(circle);
                        break;
                    case DRAW:
                        circle->setFinalPoint(Point(event->x, h - event->y ));
                        break;
                }

                circle->calcule();
                circle->draw();
                break;

            }
            case ELIPSE:
            {
                Ellipse* elipse = (Ellipse *)figuras.back();

                switch(menu->action){
                    case MOVE:
                        transform->setFinalPoint(Point(event->x, h - event->y));
                        transform->move(elipse);
                        break;
                    case ROTATE:
                        transform->setFinalPoint(Point(event->x, h - event->y));
                        transform->rotate(elipse);
                        break;
                    case DRAW:
                        elipse->setFinalPoint(Point(event->x, h - event->y ));
                        break;
                }
                elipse->calcule();
                elipse->draw();
                break;

            }
            case TRIANGULE:
            case RECTANGULE:
            case PENTAGONO:
            case HEXAGONO:
            case HEPTAGONO:
            {
                Polygon* polygon = polygons.back();

                switch(menu->action){
                    case MOVE:
                        transform->setFinalPoint(Point(event->x, h - event->y));
                        transform->move(polygon);
                        break;
                    case ROTATE:
                        transform->setFinalPoint(Point(event->x, h - event->y));
                        transform->rotate(polygon);
                        break;
                    case SCALE:
                        transform->setFinalPoint(Point(event->x, h - event->y));
                        transform->scale(polygon);
                        break;
                    case DRAW:
                        polygon->setFinalPoint(Point(event->x, h - event->y ));
                        break;
                }
                polygon->calcule();
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

    glClear(GL_COLOR_BUFFER_BIT);
    for(unsigned int i = 0; i < figuras.size(); i++)
        figuras[i]->draw();
    for(unsigned int i = 0; i < polygons.size(); i++)
        polygons[i]->draw();
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
