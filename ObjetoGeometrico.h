#ifndef OBJETO_GEOMETRICO_H
#define OBJETO_GEOMETRICO_H
#include "Rayo.h"
#include "ColorRGB.h"
class ObjetoGeometrico{
    public:
    ObjetoGeometrico();
    virtual bool hayImpacto(const Rayo& rayo, double& t, Vector3D& n, Punto3D& q ) const = 0;
    virtual ColorRGB obtenerColor() = 0;
};
#endif