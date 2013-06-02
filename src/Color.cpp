#include "../include/Color.h"
#include <math.h>

#define R_RGB this->dato[0]
#define G_RGB this->dato[1]
#define B_RGB this->dato[2]

#define C_CMYK this->dato[0]
#define M_CMYK this->dato[1]
#define Y_CMYK this->dato[2]
#define K_CMYK this->dato[3]

#define H_HSV this->dato[0]
#define S_HSV this->dato[1]
#define V_HSV this->dato[2]

#define Y_YIQ this->dato[0]
#define I_YIQ this->dato[1]
#define Q_YIQ this->dato[2]

#define Y_YUV this->dato[0]
#define U_YUV this->dato[1]
#define V_YUV this->dato[2]

#define X_XYZ this->dato[0]
#define Y_XYZ this->dato[1]
#define Z_XYZ this->dato[2]

Color::Color(int type)
{
    if (type > 0 && type < 8)
        this->type = type;
    else
        this->type = RGB;

    this->dato[0] = 0;
    this->dato[1] = 0;
    this->dato[2] = 0;
    this->dato[3] = 0;

    this->size = 3;
}

Color::Color(int type, GLfloat dato1, GLfloat dato2, GLfloat dato3){
    this->type = type;
    this->dato[0] = dato1;
    this->dato[1] = dato2;
    this->dato[2] = dato3;
    this->dato[3] = 0;
    this->size = 3;
}

Color::Color(int type, GLfloat dato1, GLfloat dato2, GLfloat dato3, GLfloat dato4){
    this->type = type;
    this->dato[0] = dato1;
    this->dato[1] = dato2;
    this->dato[2] = dato3;
    this->dato[3] = dato4;
    this->size = 4;
}

float Color::getMay(){
    float may = 0;
    for (int i = 0; i < this->size; i++){
        if (this->dato[i] > may)
            may = this->dato[i];
    }

    return may;
}

float Color::getMin(){
    float min = 0;
    for (int i = 0; i < this->size; i++){
        if (this->dato[i] < min)
            min = this->dato[i];
    }

    return min;
}

/**  CONVERTIR A RGB  **/

void Color::toRGB(){
    float Hi, f, p, q, t;

    switch(this->type){
        case RGB:
            break;
        case CMY:
            R_RGB  = 1 - C_CMYK;
            G_RGB  = 1 - M_CMYK;
            B_RGB  = 1 - Y_CMYK;
            break;
        case CMYK:
            this->toCMY();
            this->toRGB();
            break;
        case HSV:
            Hi = ((int)H_HSV/60) % 6;
            f = (H_HSV/60) - Hi;
            p = V_HSV * (1 - S_HSV);
            q = V_HSV * (1 - f*S_HSV);
            t = V_HSV * (1 - (1-f)*S_HSV);
            switch ((int)Hi){
                case 0:
                    R_RGB = V_HSV;
                    G_RGB = t;
                    B_RGB = p;
                    break;
                case 1:
                    R_RGB = q;
                    G_RGB = V_HSV;
                    B_RGB = p;
                    break;
                case 2:
                    R_RGB = p;
                    G_RGB = V_HSV;
                    B_RGB = t;
                    break;
                case 3:
                    R_RGB = p;
                    G_RGB = q;
                    B_RGB = V_HSV;
                    break;
                case 4:
                    R_RGB = t;
                    G_RGB = p;
                    B_RGB = V_HSV;
                    break;
                case 5:
                    R_RGB = V_HSV;
                    G_RGB = p;
                    B_RGB = q;
                    break;
            }

            break;
        case YIQ:
            p = Y_YIQ + 0.9563f*I_YIQ + 0.6210f*Q_YIQ;
            q = Y_YIQ - 0.2721f*I_YIQ - 0.6474f*Q_YIQ;
            t = Y_YIQ - 1.1070f*I_YIQ + 1.7046f*Q_YIQ;

            R_RGB = p;
            G_RGB = q;
            B_RGB = t;
            break;
        case YUV:
            p = Y_YUV + V_YUV/0.877f;
            q = Y_YUV - 0.395f*U_YUV - 0.581f*V_YUV;
            t = Y_YUV + U_YUV / 0.492f;

            R_RGB = p;
            G_RGB = q;
            B_RGB = t;
            break;
        case XYZ:
            p = 0.48872*X_XYZ + 0.31068*Y_XYZ + 0.20060*Z_XYZ;
            q = 0.17620*X_XYZ + 0.81298*Y_XYZ + 0.01081*Z_XYZ;
            t = 0.01020*Y_XYZ + 0.98980*Z_XYZ;

            R_RGB = p;
            G_RGB = q;
            B_RGB = t;
            break;
    }
    this->type = RGB;
    this->size = 3;
}

void Color::toCMY(){
    float min = this->getMin();

    switch(this->type){
        case RGB:
            C_CMYK = 1 - R_RGB;
            M_CMYK = 1 - G_RGB;
            Y_CMYK = 1 - B_RGB;
            break;
        case CMY:
            break;
        case CMYK:
            C_CMYK += min;
            M_CMYK += min;
            Y_CMYK += min;
            break;
        case HSV:
            toRGB();
            toCMY();
            break;
        case YIQ:
            toRGB();
            toCMY();
            break;
        case YUV:
            toRGB();
            toCMY();
            break;
        case XYZ:
            toRGB();
            toCMY();
            break;
    }
    this->type = CMY;
    this->size = 3;
}

void Color::toCMYK(){
    float min = this->getMin();

    switch(this->type){
        case RGB:
            toCMY();
            toCMYK();
            break;
        case CMY:
            C_CMYK -= min;
            M_CMYK -= min;
            Y_CMYK -= min;
            K_CMYK = min;
            break;
        case CMYK:
            break;
        case HSV:
            toRGB();
            toCMYK();
            break;
        case YIQ:
            toRGB();
            toCMYK();
            break;
        case YUV:
            toRGB();
            toCMYK();
            break;
        case XYZ:
            toRGB();
            toCMYK();
            break;
    }
    this->type = CMYK;
    this->size = 4;
}

void Color::toHSV(){
    float max = this->getMay();
    float min = this->getMin();
    float diferencia = max - min;
    float h,s;

    switch(this->type){
        case RGB:
            if (max == R_RGB)
                h = 60 * ((int)((G_RGB - B_RGB)/diferencia) % 6);
            else if (max == G_RGB)
                h = 60 * ((int)((B_RGB - R_RGB)/diferencia) + 2);
            else if (max == B_RGB)
                h = 60 * ((int)((R_RGB - G_RGB)/diferencia) + 4);

            if (diferencia == 0)
                s = 0;
            else
                s = diferencia / max;
            H_HSV = h;
            S_HSV = s;
            V_HSV = max;
            break;
        case CMY:
            toRGB();
            toHSV();
            break;
        case CMYK:
            toRGB();
            toHSV();
            break;
        case HSV:
            break;
        case YIQ:
            toRGB();
            toHSV();
            break;
        case YUV:
            toRGB();
            toHSV();
            break;
        case XYZ:
            toRGB();
            toHSV();
            break;
    }
    this->type = HSV;
    this->size = 3;
}

void Color::toYIQ(){
    float y,i,q;

    switch(this->type){
        case RGB:
            y = 0.299*R_RGB + 0.587*G_RGB + 0.114*B_RGB;
            i = 0.596*R_RGB - 0.274*G_RGB - 0.322*B_RGB;
            q = 0.211*R_RGB - 0.523*G_RGB + 0.312*B_RGB;
            Y_YIQ = y;
            I_YIQ = i;
            Q_YIQ = q;
            break;
        case CMY:
            toRGB();
            toYIQ();
            break;
        case CMYK:
            toRGB();
            toYIQ();
            break;
        case HSV:
            toRGB();
            toYIQ();
            break;
        case YIQ:
            break;
        case YUV:
            toRGB();
            toYIQ();
            break;
        case XYZ:
            toRGB();
            toYIQ();
            break;
    }
    this->type = YIQ;
    this->size = 3;
}

void Color::toYUV(){
    float y,u,v;
    switch(this->type){
        case RGB:
            y = 0.299*R_RGB + 0.587*G_RGB + 0.114*B_RGB;
            u = -0.14713*R_RGB - 0.28886*G_RGB + 0.436*B_RGB;
            v = 0.615*R_RGB - 0.51499*G_RGB - 0.10001*B_RGB;
            Y_YUV = y;
            U_YUV = u;
            V_YUV = v;
            break;
        case CMY:
            toRGB();
            toYUV();
            break;
        case CMYK:
            toRGB();
            toYUV();
            break;
        case HSV:
            toRGB();
            toYUV();
            break;
        case YIQ:
            toRGB();
            toYUV();
            break;
        case YUV:
            break;
        case XYZ:
            toRGB();
            toYUV();
            break;
    }
    this->type = YUV;
    this->size = 3;
}

void Color::toXYZ(){
    float x,y,z;
    switch(this->type){
        case RGB:
            x = 2.37067*R_RGB - 0.90004*G_RGB - 0.47063*B_RGB;
            y = -0.51388*R_RGB + 1.42530*G_RGB + 0.08858*B_RGB;
            z = 0.00530*R_RGB - 0.01469*G_RGB + 1.00940*B_RGB;

            X_XYZ = x;
            Y_XYZ = y;
            Z_XYZ = z;
            break;
        case CMY:
            toRGB();
            toXYZ();
            break;
        case CMYK:
            toRGB();
            toXYZ();
            break;
        case HSV:
            toRGB();
            toXYZ();
            break;
        case YIQ:
            toRGB();
            toXYZ();
            break;
        case YUV:
            toRGB();
            toXYZ();
            break;
        case XYZ:
            break;
    }
    this->type = XYZ;
    this->size = 3;
}

void Color::imprimeColor(){
        switch(this->type){
        case RGB:
            cout<<"RGB";
            break;
        case CMY:
            cout<<"CMY";
            break;
        case CMYK:
            cout<<"CMYK";
            break;
        case HSV:
            cout<<"HSV";
            break;
        case YIQ:
            cout<<"YIQ";
            break;
        case YUV:
            cout<<"YUV";
            break;
        case XYZ:
            cout<<"XYZ";
            break;
    }

    cout<<" ( ";
    for (int i = 0; i < this->size; i++)
        cout<<this->dato[i]<<" ";
    cout<<")"<<endl;
}

GLfloat* Color::getColor(){
    for (int i = 0;i < this->size; i++)
        copia_dato[i] = dato[i];
    return copia_dato;
}

void Color::setColor(int type, GLfloat dato1, GLfloat dato2, GLfloat dato3){
    this->type = type;
    this->dato[0] = dato1;
    this->dato[1] = dato2;
    this->dato[2] = dato3;
    this->dato[3] = 0;
    this->size = 3;
}
