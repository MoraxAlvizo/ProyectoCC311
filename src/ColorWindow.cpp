#include "../include/ColorWindow.h"

ColorWindow::ColorWindow(Gtk::ColorSelection* colorSelection):
    HBox(8),
    color(RGB),
    bConvert("Convertir"),
    //CMY
    bCMY(3),
    _1CMY(2),
    _2CMY(2),
    _3CMY(2),
    lcCMY("C:"),
    lmCMY("M:"),
    lyCMY("Y:"),

    //CMYK
    bCMYK(4),
    _1CMYK(2),
    _2CMYK(2),
    _3CMYK(2),
    _4CMYK(2),
    lcCMYK("C:"),
    lmCMYK("M:"),
    lyCMYK("Y:"),
    lkCMYK("K:"),

    //HSV
    bHSV(3),
    _1HSV(2),
    _2HSV(2),
    _3HSV(2),
    lhHSV("H:"),
    lsHSV("S:"),
    lvHSV("V:"),

    //YIQ
    bYIQ(3),
    _1YIQ(2),
    _2YIQ(2),
    _3YIQ(2),
    lyYIQ("Y:"),
    liYIQ("I:"),
    lqYIQ("Q:"),

    //YUV
    bYUV(3),
    _1YUV(2),
    _2YUV(2),
    _3YUV(2),
    lyYUV("Y:"),
    luYUV("U:"),
    lvYUV("V:"),

    //XYZ
    bXYZ(3),
    _1XYZ(2),
    _2XYZ(2),
    _3XYZ(2),
    lxXYZ("X:"),
    lyXYZ("Y:"),
    lzXYZ("Z:")
{
    set_border_width(10);
    this->colorSelection = colorSelection;

    buttons.set_layout(Gtk::BUTTONBOX_END);
	buttons.pack_start(bConvert);

    //CMY
    _1CMY.pack_start(lcCMY);
    _1CMY.pack_start(cCMY );
    _2CMY.pack_start(lmCMY);
    _2CMY.pack_start(mCMY );
    _3CMY.pack_start(lyCMY);
    _3CMY.pack_start(yCMY );
    bCMY.pack_start(_1CMY , Gtk::PACK_SHRINK);
    bCMY.pack_start(_2CMY , Gtk::PACK_SHRINK);
    bCMY.pack_start(_3CMY , Gtk::PACK_SHRINK);

    //CMYK
    bCMYK.pack_start(_1CMYK);
    bCMYK.pack_start(_2CMYK);
    bCMYK.pack_start(_3CMYK);
    bCMYK.pack_start(_4CMYK);
    _1CMYK.pack_start(lcCMYK);
    _1CMYK.pack_start(cCMYK);
    _2CMYK.pack_start(lmCMYK);
    _2CMYK.pack_start(mCMYK);
    _3CMYK.pack_start(lyCMYK);
    _3CMYK.pack_start(yCMYK);
    _4CMYK.pack_start(lkCMYK);
    _4CMYK.pack_start(kCMYK);

    //HSV
    bHSV.pack_start(_1HSV);
    bHSV.pack_start(_2HSV);
    bHSV.pack_start(_3HSV);
    _1HSV.pack_start(lhHSV);
    _1HSV.pack_start(hHSV);
    _2HSV.pack_start(lsHSV);
    _2HSV.pack_start(sHSV);
    _3HSV.pack_start(lvHSV);
    _3HSV.pack_start(vHSV);

    //YIQ
    bYIQ.pack_start(_1YIQ);
    bYIQ.pack_start(_2YIQ);
    bYIQ.pack_start(_3YIQ);
    _1YIQ.pack_start(lyYIQ);
    _1YIQ.pack_start(yYIQ);
    _2YIQ.pack_start(liYIQ);
    _2YIQ.pack_start(iYIQ);
    _3YIQ.pack_start(lqYIQ);
    _3YIQ.pack_start(qYIQ);

    //YUV
    bYUV.pack_start(_1YUV);
    bYUV.pack_start(_2YUV);
    bYUV.pack_start(_3YUV);
    _1YUV.pack_start(lyYUV);
    _1YUV.pack_start(yYUV);
    _2YUV.pack_start(luYUV);
    _2YUV.pack_start(uYUV);
    _3YUV.pack_start(lvYUV);
    _3YUV.pack_start(vYUV);

    //XYZ
    bXYZ.pack_start(_1XYZ);
    bXYZ.pack_start(_2XYZ);
    bXYZ.pack_start(_3XYZ);
    _1XYZ.pack_start(lxXYZ);
    _1XYZ.pack_start(xXYZ);
    _2XYZ.pack_start(lyXYZ);
    _2XYZ.pack_start(yXYZ);
    _3XYZ.pack_start(lzXYZ);
    _3XYZ.pack_start(zXYZ);

    pack_start(bCMY);
    pack_start(bCMYK);
    pack_start(bHSV);
    pack_start(bYIQ);
    pack_start(bYUV);
    pack_start(bXYZ);
    pack_start(buttons);

    set_size_request (100, 100);

    bConvert.signal_pressed ().connect(sigc::mem_fun(*this, &ColorWindow::onButtonConvert));

}

ColorWindow::~ColorWindow()
{
    //dtor
}

void ColorWindow::onButtonConvert(){

    Gdk::Color newColor = colorSelection->get_current_color ();
    GLfloat* colorArray;

    color.setColor(RGB,
                  newColor.get_red()/65535,
                  newColor.get_green()/65535.0,
                  newColor.get_blue() /65535.0);


    /** RGB to CMY **/
    color.toCMY();
    colorArray = color.getColor() ;

    cCMY.set_text(toString(colorArray[0]));
    mCMY.set_text(toString(colorArray[1]));
    yCMY.set_text(toString(colorArray[2]));

    /** CMY to CMYK **/
    color.toCMYK();
    colorArray = color.getColor() ;

    //CMYK
    cCMYK.set_text(toString(colorArray[0]));
    mCMYK.set_text(toString(colorArray[1]));
    yCMYK.set_text(toString(colorArray[2]));
    kCMYK.set_text(toString(colorArray[3]));


    /** CMYK to HSV **/
    color.toHSV();
    colorArray = color.getColor() ;

    //HSV

    hHSV.set_text(toString(colorArray[0]));
    sHSV.set_text(toString(colorArray[1]));
    vHSV.set_text(toString(colorArray[2]));

    /** HSV to YIQ **/
    color.toYIQ();
    colorArray = color.getColor() ;


    //YIQ
    yYIQ.set_text(toString(colorArray[0]));
    iYIQ.set_text(toString(colorArray[1]));
    qYIQ.set_text(toString(colorArray[2]));

    /** YIQ to YUV **/
    color.toYUV();
    colorArray = color.getColor() ;

    //YUV

    yYUV.set_text(toString(colorArray[0]));
    uYUV.set_text(toString(colorArray[1]));
    vYUV.set_text(toString(colorArray[2]));

    /** YUV to XYZ **/
    color.toXYZ();
    colorArray = color.getColor() ;

    //XYZ

    xXYZ.set_text(toString(colorArray[0]));
    yXYZ.set_text(toString(colorArray[1]));
    zXYZ.set_text(toString(colorArray[2]));


}

string ColorWindow::toString(GLfloat number){
    ostringstream ss;
    ss << number;
    return ss.str();

}
