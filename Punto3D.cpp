#include"Punto3D.h"
Punto3D::Punto3D(): x(0), y(0), z(0)
{}
Punto3D::Punto3D(double n): x(n), y(n), z(n)
{}
Punto3D::Punto3D(double v_x, double v_y, double v_z): x(v_x), y(v_y), z(v_z)
{}
Punto3D::Punto3D(const Punto3D& p): x(p.x), y(p.y), z(p.z)
{}
Punto3D::~Punto3D()
{}

// Restar dos puntos --------------------------------------------------------------------------------------------------
Vector3D Punto3D::operator-(const Punto3D& p) const{
    return (Vector3D(x - p.x, y - p.y, z - p.z));
}
// Sumar al punto un vector -------------------------------------------------------------------------------------------
Punto3D Punto3D::operator+(const Vector3D& v) const
{
    return (Punto3D(x + v.x, y + v.y, z + v.z));
}
// Retar al punto un vector -------------------------------------------------------------------------------------------
Punto3D Punto3D::operator-(const Vector3D& v) const
{
    return (Punto3D(x - v.x, y - v.y, z - v.z));
}
// Multiplicar un punto por un numero ---------------------------------------------------------------------------------
Punto3D Punto3D::operator*(const double n) const 
{
    return (Punto3D( x * n, y * n, z * n));
}
// Multiplicar un numero por un punto ---------------------------------------------------------------------------------
Punto3D operator*(double n, const Punto3D& p)
{
    return (Punto3D(n * p.x , n * p.y, n * p.z));
}