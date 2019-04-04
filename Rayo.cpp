#include "Rayo.h"
Rayo::Rayo(): o(0.0), d(0.0, 0.0, 1.0)
{}
Rayo::Rayo(const Punto3D& origen, const Vector3D& direccion): o(origen), d(direccion)
{}
Rayo::~Rayo(){}
