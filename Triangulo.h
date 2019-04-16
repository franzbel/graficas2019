// #include "Punto3D.h"
#include "Rayo.h"
#include "ColorRGB.h"
#include "ObjetoGeometrico.h"

class Triangulo : public ObjetoGeometrico
{
    public:
    Triangulo(Punto3D, Punto3D, Punto3D);
    
    bool hayImpacto(const Rayo& r, double& t, Vector3D& n, Punto3D& q) const;
    void establecerColor(double, double, double);
    ColorRGB obtenerColor();

    Punto3D A, B, C;
    ColorRGB color;
};
