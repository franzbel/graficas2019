#ifndef VECTOR3D_H
#define VECTOR3D_H
class Vector3D
{
    public:
    Vector3D();                                              // constructor por defecto
    Vector3D(const Vector3D& v);                             // Constructor copia 
    Vector3D(double n);                                      // constructor 
    Vector3D(double v_x, double v_y, double v_z);            // constructor
    ~Vector3D();

    Vector3D& operator= (const Vector3D& v);                 // Asignacion
    Vector3D operator+ (const Vector3D& v) const;            // Sumar dos vectores
    Vector3D operator- (const Vector3D& v) const;            // Restar dos vectores
    double operator* (const Vector3D& v) const;              // Producto escalar
    Vector3D operator^ (const Vector3D& v) const;            // Producto vectorial
    friend Vector3D operator* (double n, const Vector3D& v); // Multiplicar un escalar por un vector 
    Vector3D operator* (const double n) const;               // Multiplicar un vector por un escalar
    Vector3D operator/ (const double n) const;               // Dividir por un escalar
    
    Vector3D& hat();							             // Convertir el vector a un vector unitario y retornar el vector

    public:
    double x; // componente x
    double y; // componente y
    double z; // componente z

    public:
    void mostrar_vector();
};
#endif