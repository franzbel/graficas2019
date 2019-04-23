#ifndef PLANO_H
#define PLANO_H
#include "ObjetoGeometrico.h"
#include "ColorRGB.h"
class Plano : public ObjetoGeometrico
{
    public:
    Plano(Punto3D, Vector3D);
    bool hayImpacto(const Rayo& rayo, double& t, Vector3D& n, Punto3D& q ) const;
    ColorRGB obtenerColor();
    void establecerColor(double, double, double);

    Punto3D p;
    Vector3D n;
    ColorRGB color;
};
#endif
