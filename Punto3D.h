#ifndef PUNTO3D_H
#define PUNTO3D_H
#include "Vector3D.h"
class Punto3D
{
    public:
    Punto3D();                                             // Constructor por defecto
    Punto3D(double n);                                     // Constructor
    Punto3D(double v_x, double v_y, double v_z);           // Constructor
    Punto3D(const Punto3D& p);                             // Constructor copia
    ~Punto3D();                                            // Destructor
    Vector3D operator- (const Punto3D& p) const;           // Restar dos puntos
    Punto3D operator+ (const Vector3D& v) const;           // Sumar al punto un vector
    Punto3D operator- (const Vector3D& v) const;           // Restar al punto un vector
    Punto3D operator* (const double n) const;              // Multiplicar un punto por un numero
    friend Punto3D operator* (double n, const Punto3D& p); // Multiplicar un mumero por un punto
    public:    
    double x, y, z;
};
#endif