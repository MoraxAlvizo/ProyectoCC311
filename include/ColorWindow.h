#ifndef COLORWINDOW_H
#define COLORWINDOW_H

#include <gtkmm.h>
#include "Color.h"

class ColorWindow:
    public Gtk::HBox
{
    public:
        ColorWindow(Gtk::ColorSelection*);
        virtual ~ColorWindow();
        string toString(GLfloat);

    protected:
        Gtk::ColorSelection* colorSelection;
        Color color;

        //CMY
        Gtk::VBox bCMY;
        Gtk::HBox _1CMY;
        Gtk::HBox _2CMY;
        Gtk::HBox _3CMY;

        Gtk::Label lcCMY;
        Gtk::Label lmCMY;
        Gtk::Label lyCMY;

        Gtk::Entry cCMY;
        Gtk::Entry mCMY;
        Gtk::Entry yCMY;

        //CMYK
        Gtk::VBox bCMYK;
        Gtk::HBox _1CMYK;
        Gtk::HBox _2CMYK;
        Gtk::HBox _3CMYK;
        Gtk::HBox _4CMYK;

        Gtk::Label lcCMYK;
        Gtk::Label lmCMYK;
        Gtk::Label lyCMYK;
        Gtk::Label lkCMYK;

        Gtk::Entry cCMYK;
        Gtk::Entry mCMYK;
        Gtk::Entry yCMYK;
        Gtk::Entry kCMYK;

        //HSV
        Gtk::VBox bHSV;
        Gtk::HBox _1HSV;
        Gtk::HBox _2HSV;
        Gtk::HBox _3HSV;

        Gtk::Label lhHSV;
        Gtk::Label lsHSV;
        Gtk::Label lvHSV;

        Gtk::Entry hHSV;
        Gtk::Entry sHSV;
        Gtk::Entry vHSV;


        //YIQ
        Gtk::VBox bYIQ;

        Gtk::HBox _1YIQ;
        Gtk::HBox _2YIQ;
        Gtk::HBox _3YIQ;

        Gtk::Label lyYIQ;
        Gtk::Label liYIQ;
        Gtk::Label lqYIQ;

        Gtk::Entry yYIQ;
        Gtk::Entry iYIQ;
        Gtk::Entry qYIQ;

        //YUV
        Gtk::VBox bYUV;

        Gtk::HBox _1YUV;
        Gtk::HBox _2YUV;
        Gtk::HBox _3YUV;

        Gtk::Label lyYUV;
        Gtk::Label luYUV;
        Gtk::Label lvYUV;

        Gtk::Entry yYUV;
        Gtk::Entry uYUV;
        Gtk::Entry vYUV;

        //XYZ
        Gtk::VBox bXYZ;

        Gtk::HBox _1XYZ;
        Gtk::HBox _2XYZ;
        Gtk::HBox _3XYZ;

        Gtk::Label lxXYZ;
        Gtk::Label lyXYZ;
        Gtk::Label lzXYZ;

        Gtk::Entry xXYZ;
        Gtk::Entry yXYZ;
        Gtk::Entry zXYZ;

        /**Metodos**/
        void onButtonConvert();
};

#endif // COLORWINDOW_H
