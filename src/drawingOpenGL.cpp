#include "../include/drawingOpenGL.h"

#define COLOR_SELECTED 1.0,0.0,1.0

DrawingOpenGL::DrawingOpenGL(ToolsMenu* menu)
{
    Glib::RefPtr<Gdk::GL::Config> glconfig;
    this->drawing = -1;
    this->primerPintado = true;
    this->menu = menu;
    this->transform = NULL;
    this->figure = NULL;

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

	gluOrtho2D(-(w/2), w/2, -(h/2), h/2);
    glFlush();
	gldrawable->gl_end();

	return TRUE;

}

bool DrawingOpenGL::on_expose_event(GdkEventExpose* event)
{
    Glib::RefPtr<Gdk::GL::Context>  context;
	Glib::RefPtr<Gdk::GL::Drawable> gldrawable;

	context = get_gl_context();
	gldrawable = get_gl_drawable();

	if (!gldrawable->gl_begin(context)){
		g_assert_not_reached ();
	}

    glClear(GL_COLOR_BUFFER_BIT);
    drawOrigin();
    glColor3f(0.0,0.0,0.0);
    for(unsigned int i = 0; i < figuras.size(); i++)
        figuras[i]->draw();
    glFlush();
	gldrawable -> gl_end();
	return true;
}

bool DrawingOpenGL::on_button_press_event(GdkEventButton* event) {


    Glib::RefPtr<Gdk::GL::Context>  context;
	Glib::RefPtr<Gdk::GL::Drawable> gldrawable;
    GLint  w = get_width(),h = get_height();

    context = get_gl_context();
	gldrawable = get_gl_drawable();
	gldrawable->gl_begin(context);



    glClear(GL_COLOR_BUFFER_BIT);
    drawOrigin();
    glColor3f(0.0,0.0,0.0);

    if(menu->action == DRAW){
        switch(menu->figura){
            case LINE:
                figuras.push_back(new Line(event->x - (w/2),  (h/2) - event->y ));
                break;
            case CIRCLE:
                figuras.push_back(new Circle(event->x - (w/2),  (h/2) - event->y  ));
                break;
            case ELIPSE:
                figuras.push_back(new Ellipse(event->x - (w/2),  (h/2) - event->y ));
                break;
            case TRIANGULE:
                figuras.push_back(new Polygon(event->x - (w/2),  (h/2) - event->y  ,TRIANGULE));
                break;
            case RECTANGULE:
                figuras.push_back(new Polygon(event->x - (w/2),  (h/2) - event->y  ,RECTANGULE));
                break;
            case PENTAGONO:
                figuras.push_back(new Polygon(event->x - (w/2),  (h/2) - event->y  ,PENTAGONO));
                break;
            case HEXAGONO:
                figuras.push_back(new Polygon(event->x - (w/2),  (h/2) - event->y ,HEXAGONO));
                break;
            case OCTAGON:
                figuras.push_back(new Polygon(event->x - (w/2),  (h/2) - event->y ,8));
                break;
        }
        if(menu->figura != SELECCIONAR){
            figure = figuras.back();
            selected = figuras.size() -1;
        }

    }
    else if(menu->action == MIRROR4 && !figuras.empty()){
        //figure = figuras.back();
        transform = new Transformed(event->x - (w/2),  (h/2) - event->y  ,figuras.back()->getInicialPoint(), figuras.back()->getFinalPoint());
        transform->mirror4(figure);
        switch(figure->getType()){
                case LINE:
                {
                    Line * line = (Line *) figure;
                    line->calcule(DRAW);
                    break;
                }
                case CIRCLE:
                {
                    Circle * circle = (Circle *) figure;
                    circle->calcule(DRAW);
                    break;
                }
                case ELIPSE:
                {
                    Ellipse * elipse = (Ellipse *) figure;
                    elipse->calcule(DRAW);
                    break;
                }
                case POLYGON:
                {
                    Polygon * polygon = (Polygon *)figure;
                    polygon->calcule();
                    break;
                }
            }

    }
    else if(menu->action == SELECCIONAR){
        buscarFigura(event->x - (w/2),  (h/2) - event->y );
        if(figure != NULL){
            std::cout<< "Lo encontro \n";
        }
    }
    else if(figure != NULL){
        transform = new Transformed(event->x - (w/2),  (h/2) - event->y  ,figure->getInicialPoint(), figure->getFinalPoint());
    }

    glColor3f(0.0,0.0,0.0);

    for(unsigned int i = 0; i < figuras.size(); i++)
        figuras[i]->draw();

    glColor3f(COLOR_SELECTED);
    if(!figuras.empty())
        figuras[selected]->draw();

    glFlush();
    gldrawable -> gl_end();
    return true;
}

bool DrawingOpenGL::on_motion_notify_event(GdkEventMotion* event) {

    Glib::RefPtr<Gdk::GL::Context>  context;
	Glib::RefPtr<Gdk::GL::Drawable> gldrawable;
    GLint w = get_width(),h = get_height();

    context = get_gl_context();
	gldrawable = get_gl_drawable();
	gldrawable->gl_begin(context);
    //Eventos del mouse

    glClear(GL_COLOR_BUFFER_BIT);
    drawOrigin();
    glColor3f(0.0,0.0,0.0);

    if((event->state & GDK_BUTTON1_MASK) && figure!=NULL){

        switch(figure->getType()){
            case LINE:
            {
                Line* linea = (Line *)figure;
                Line copyLine = Line(0,0);

                switch(menu->action){
                    case MOVE:
                        transform->setFinalPoint(Point(event->x - (w/2),  (h/2) - event->y ));
                        transform->move(linea);
                        break;
                    case ROTATE:
                        transform->setFinalPoint(Point(event->x - (w/2),  (h/2) - event->y ));
                        transform->rotate(linea);
                        break;
                    case SCALE:
                        transform->setFinalPoint(Point(event->x - (w/2),  (h/2) - event->y ));
                        transform->scale(linea);
                        break;
                    case DRAW:
                        linea->setFinalPoint(Point(event->x - (w/2),  (h/2) - event->y));
                        break;
                }

                linea->calcule(true);
                linea->draw();
                break;

            }

            case CIRCLE:
            {
                Circle* circle = (Circle *)figure;

                switch(menu->action){
                    case MOVE:
                        transform->setFinalPoint(Point(event->x - (w/2),  (h/2) - event->y));
                        transform->move(circle);
                        break;
                    case ROTATE:
                        transform->setFinalPoint(Point(event->x - (w/2),  (h/2) - event->y));
                        transform->rotate(circle);
                        break;
                    case SCALE:
                        transform->setFinalPoint(Point(event->x - (w/2),  (h/2) - event->y));
                        transform->scale(circle);
                        break;
                    case DRAW:
                        circle->setFinalPoint(Point(event->x - (w/2),  (h/2) - event->y ));
                        break;
                }

                circle->calcule(true);
                circle->draw();
                break;

            }
            case ELIPSE:
            {
                Ellipse* elipse = (Ellipse *)figure;

                switch(menu->action){
                    case MOVE:
                        transform->setFinalPoint(Point(event->x - (w/2),  (h/2) - event->y));
                        transform->move(elipse);
                        break;
                    case ROTATE:
                        transform->setFinalPoint(Point(event->x - (w/2),  (h/2) - event->y));
                        transform->rotate(elipse);
                        break;
                    case DRAW:
                        elipse->setFinalPoint(Point(event->x - (w/2),  (h/2) - event->y ));
                        break;
                }
                elipse->calcule(true);
                elipse->draw();
                break;

            }
            case POLYGON:
            {
                Polygon* polygon = (Polygon *)figure;

                switch(menu->action){
                    case MOVE:
                        transform->setFinalPoint(Point(event->x - (w/2),  (h/2) - event->y));
                        transform->move(polygon);
                        break;
                    case ROTATE:
                        transform->setFinalPoint(Point(event->x - (w/2),  (h/2) - event->y));
                        transform->rotate(polygon);
                        break;
                    case SCALE:
                        transform->setFinalPoint(Point(event->x - (w/2),  (h/2) - event->y));
                        transform->scale(polygon);
                        break;
                    case DRAW:
                        polygon->setFinalPoint(Point(event->x - (w/2),  (h/2) - event->y ));
                        break;
                }
                polygon->calcule();
                polygon->draw();
                break;

            }

        }
    }

    for(unsigned int i = 0; i < figuras.size(); i++){
        figuras[i]->draw();
    }

    if(figure != NULL){
        glColor3f(COLOR_SELECTED);
        figuras[selected]->draw();
    }


    glFlush();
    gldrawable -> gl_end();


    return true;
}

bool DrawingOpenGL::on_button_release_event(GdkEventButton* event){

    Glib::RefPtr<Gdk::GL::Context>  context;
	Glib::RefPtr<Gdk::GL::Drawable> gldrawable;
	GLint w = get_width(),h = get_height();
	Point pointRelease = Point(event->x - (w/2),  (h/2) - event->y);

    context = get_gl_context();
	gldrawable = get_gl_drawable();
	gldrawable->gl_begin(context);

    glClear(GL_COLOR_BUFFER_BIT);
    drawOrigin();
    glColor3f(0.0,0.0,0.0);

    if(figure!= NULL && figure->getInicialPoint() == pointRelease){
        figure->setFinalPoint(pointRelease);
        std::cout << "Entro a eliminar figura" << std::endl;

    }

    std::cout << "Numero de figuras" << figuras.size() << std::endl;

    for(unsigned int i = 0; i < figuras.size(); i++)
        figuras[i]->draw();

    if(figure != NULL){
        glColor3f(COLOR_SELECTED);
        figuras[selected]->draw();
    }

    glFlush();
    gldrawable -> gl_end();

    return true;
}

bool DrawingOpenGL::on_enter_notify_event(GdkEventCrossing* event){

    return true;
}

void DrawingOpenGL::drawOrigin(){

    GLint w = get_width(), h = get_height();

    glBegin(GL_LINES);

        glColor3f(1.0,0.0,0.0);
        glVertex2i(w/2 , 0  );
        glVertex2i(-w/2, 0  );

        glColor3f(0.0,1.0,0.0);
        glVertex2i( 0  ,h/2 );
        glVertex2i( 0  ,-h/2);
    glEnd();

}

Figure* DrawingOpenGL::getLastFigura(){
    if(!figuras.empty())
        return figuras.back();
    return NULL;
}

void DrawingOpenGL::mirrior(int numMirror){

    Glib::RefPtr<Gdk::GL::Context>  context;
	Glib::RefPtr<Gdk::GL::Drawable> gldrawable;

    context = get_gl_context();
	gldrawable = get_gl_drawable();
	gldrawable->gl_begin(context);

	glClear(GL_COLOR_BUFFER_BIT);
    drawOrigin();
    glColor3f(0.0,0.0,0.0);

    if(!figuras.empty()){
        transform = new Transformed(0, 0, figure->getInicialPoint(), figure->getFinalPoint());
        figure -> drawCopy();
        switch(numMirror){

            case 1:
            transform->mirror1(figure);
            break;
            case 2:
            transform->mirror2(figure);
            break;
            case 3:
            transform->mirror3(figure);
            break;
            case 4:
            transform->mirror4(figure);
            break;
            case 5:
            transform->mirror5(figure);
            break;
            case 6:
            transform->mirror6(figure);
            break;
            }

            switch(figure->getType()){
                case LINE:
                {
                    Line * line = (Line *) figure;
                    line->calcule(DRAW);
                    break;
                }
                case CIRCLE:
                {
                    Circle * circle = (Circle *) figure;
                    circle->calcule(DRAW);
                    break;
                }
                case ELIPSE:
                {
                    Ellipse * elipse = (Ellipse *) figure;
                    elipse->calcule(DRAW);
                    break;
                }
                case POLYGON:
                {
                    Polygon * polygon = (Polygon *)figure;
                    polygon->calcule();
                    break;
                }
            }
    }

    for(unsigned int i = 0; i < figuras.size(); i++)
        figuras[i]->draw();

    glFlush();
    gldrawable -> gl_end();
}

void DrawingOpenGL::buscarFigura(GLint x, GLint y){

    for(unsigned int i = 0; i < figuras.size(); i++){
        if(figuras[i]->buscarPunto(x,y)
        || figuras[i]->buscarPunto(x+1,y+1)
        || figuras[i]->buscarPunto(x+1,y-1)
        || figuras[i]->buscarPunto(x-1,y+1)
        || figuras[i]->buscarPunto(x-1,y-1)
        || figuras[i]->buscarPunto(x  ,y+1)
        || figuras[i]->buscarPunto(x+1,y  )
        || figuras[i]->buscarPunto(x  ,y-1)
        || figuras[i]->buscarPunto(x-1,y  )
           ){
                figure = figuras.at(i);
                selected = i;
                return;
               }
    }
}


