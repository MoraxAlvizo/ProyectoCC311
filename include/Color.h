#ifndef COLOR_H
#define COLOR_H
#include <GL/glut.h>
#include <iostream>

#define     RGB     1
#define     CMY     2
#define     CMYK    3
#define     HSV     4
#define     YIQ     5
#define     YUV     6
#define     XYZ     7

using namespace std;

class Color
{
    private:
        GLfloat dato[4];
        GLfloat copia_dato[4];
        int type;
        int size;

        float getMay();
        float getMin();

        void normalizar();

    public:
        /** Constructores **/

        Color(int type);
        Color(int type, GLfloat dato1, GLfloat dato2, GLfloat dato3);
        Color(int type, GLfloat dato1, GLfloat dato2, GLfloat dato3, GLfloat dato4);

        void setColor(int type, GLfloat dato1, GLfloat dato2, GLfloat dato3);
        /** Solo sirve para mostrar el color en pantalla **/
        void imprimeColor();

        /** Conversión **/
        void toRGB();
        void toCMY();
        void toCMYK();
        void toHSV();
        void toYIQ();
        void toYUV();
        void toXYZ();

        /** Regresa un arreglo con los datos del color **/
        GLfloat* getColor();
};

#endif // COLOR_H
