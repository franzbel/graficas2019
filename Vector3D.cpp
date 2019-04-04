#include <iostream>
#include <math.h>
using namespace std;
#include "Vector3D.h"

Vector3D::Vector3D():x(0.0), y(0.0), z(0.0)
{}
Vector3D::Vector3D(const Vector3D& v): x(v.x), y(v.y), z(v.z) 
{}
Vector3D::Vector3D(double n): x(n), y(n), z(n)
{}
Vector3D::Vector3D(double v_x, double v_y, double v_z): x(v_x), y(v_y), z(v_z)
{}
Vector3D::~Vector3D()
{}
//  Asignacion ---------------------------------------------------------------------------------------------------------
Vector3D& Vector3D::operator= (const Vector3D& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
}
//  Sumar dos vectores -------------------------------------------------------------------------------------------------
Vector3D Vector3D::operator+ (const Vector3D& v) const
{
    return(Vector3D( x + v.x, y + v.y, z + v.z));
}

//  Restar dos vectores -----------------------------------------------------------------------------------------------
Vector3D Vector3D::operator- (const Vector3D& v) const 
{
    return (Vector3D(x - v.x, y - v.y, z - v.z));
}
// Producto escalar ---------------------------------------------------------------------------------------------------
double Vector3D::operator* (const Vector3D& v) const
{
    return (x * v.x + y * v.y + z * v.z);
}
// Producto vectorial -------------------------------------------------------------------------------------------------
Vector3D Vector3D::operator^ (const Vector3D& v) const
{
    return (Vector3D( y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x));
}
// Multiplicar un escalar por un vector -------------------------------------------------------------------------------
Vector3D operator*(double n, const Vector3D& v)
{
    return( Vector3D(n*v.x, n*v.y, n*v.z));
}

// Multiplicar un vector por un escalar -------------------------------------------------------------------------------
Vector3D Vector3D::operator*(const double n) const
{
    return(Vector3D(x * n, y * n, z* n));
}

// Dividir un vector entre un numero ----------------------------------------------------------------------------------
Vector3D Vector3D::operator/ (const double n) const 
{
    return(Vector3D( x / n, y / n, z / n));
}


Vector3D& Vector3D::hat(void) {
	double length = sqrt(x * x + y * y + z * z);
	x /= length; y /= length; z /= length;
	return (*this);
}

// Utilitarios --------------------------------------------------------------------------------------------------------
void Vector3D::mostrar_vector()
{
    cout <<"<"<< x <<","<< y <<","<< z<<">"<<endl;
}