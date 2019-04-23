#include "Plano.h"
Plano::Plano(Punto3D v_p, Vector3D v_n)
{
    p = v_p;
    n = v_n;
}
bool Plano::hayImpacto(const Rayo& _rayo, double& _t, Vector3D& _n, Punto3D& _q  ) const
{
    double t = ((p - _rayo.o)*n) / (_rayo.d * n);
    if( t > 0.0000001 ) 
    {
        _q = _rayo.o + t*_rayo.d;
        _n = n;
        _t = t;

        return true;
    }
    else
    {
        return false;   
    }    
}
void Plano::establecerColor(double v_r, double v_g, double v_b)
{
    color.r = v_r;
    color.g = v_g;
    color.b = v_b;
}
ColorRGB Plano::obtenerColor()
{
    ColorRGB c;
    c.r = color.r;
    c.g = color.g;
    c.b = color.b;
    return  c;
}