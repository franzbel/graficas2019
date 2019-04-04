#ifndef LUZ_PUNTUAL_H
#define LUZ_PUNTUAL_H
#include "Punto3D.h"
#include "ColorRGB.h"
class LuzPuntual
{
    public:
    LuzPuntual(double r, double g, double b, double x, double y, double z);
    
    Punto3D posicion;
    ColorRGB color;
};
#endif


