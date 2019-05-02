#include<iostream>
#include <math.h>

using namespace std;
#include <vector>
#include <iostream>

#include "Vector3D.h"
#include "Esfera.h"
#include "ViewPlane.h"

#include "Utilitarios.h"
#include "LuzPuntual.h"

#include "Triangulo.h"
#include "Plano.h"
// #include "ObjetoGeometrico.h"

using namespace std;


ColorRGB obtenerColorPixel(const Rayo& r, vector<ObjetoGeometrico*> objetos, LuzPuntual luz, LuzPuntual luz_ambiente){
    
    ColorRGB color;

    color.r = 0.0;
    color.g = 0.0;
    color.b = 0.0;

    double t;
    double tmin = 2000000;    
    Vector3D n;
    Punto3D q;

    Vector3D h;
    for(int i = 0; i < objetos.size(); i++) {
        if( objetos[i]->hayImpacto(r, t, n, q) && t < tmin){    
            // color.r = objetos[i]->obtenerColor().r;
            // color.g = objetos[i]->obtenerColor().g;
            // color.b = objetos[i]->obtenerColor().b;

            // color.r = objetos[i]->obtenerColor().r * luz.color.r * std::max(0.0, n * (luz.posicion - q).hat() );
            // color.g = objetos[i]->obtenerColor().g * luz.color.g * std::max(0.0, n * (luz.posicion - q).hat() );
            // color.b = objetos[i]->obtenerColor().b * luz.color.b * std::max(0.0, n * (luz.posicion - q).hat() );


            // color.r = objetos[i]->obtenerColor().r * luz.color.r * std::max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor().r * luz.color.r * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),10000);
            // color.g = objetos[i]->obtenerColor().g * luz.color.g * std::max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor().g * luz.color.g * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),10000);
            // color.b = objetos[i]->obtenerColor().b * luz.color.b * std::max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor().b * luz.color.b * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),10000);
            
            
            // color.r = objetos[i]->obtenerColor().r * luz_ambiente.color.r;
            // color.g = objetos[i]->obtenerColor().g * luz_ambiente.color.g;
            // color.b = objetos[i]->obtenerColor().b * luz_ambiente.color.b;


            color.r = objetos[i]->obtenerColor().r * luz_ambiente.color.r + objetos[i]->obtenerColor().r * luz.color.r * std::max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor().r * luz.color.r * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),100);
            color.g = objetos[i]->obtenerColor().g * luz_ambiente.color.g + objetos[i]->obtenerColor().g * luz.color.g * std::max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor().g * luz.color.g * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),100);
            color.b = objetos[i]->obtenerColor().b * luz_ambiente.color.b + objetos[i]->obtenerColor().b * luz.color.b * std::max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor().b * luz.color.b * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),100);

            
            


            double t_sombra;
            double t_min_sombra = 2000000;
            Vector3D n_sombra;
            Punto3D q_sombra;
            Rayo rayo_sombra(q, (luz.posicion - q)) ;
            for (int j = 0; j < objetos.size(); j++) {
                if ((objetos[j]->hayImpacto(rayo_sombra, t_sombra, n_sombra, q_sombra) && t_sombra < t_min_sombra)) {
                    color.r = objetos[i]->obtenerColor().r * luz_ambiente.color.r;
                    color.g = objetos[i]->obtenerColor().g * luz_ambiente.color.g;
                    color.b = objetos[i]->obtenerColor().b * luz_ambiente.color.b;
                    t_min_sombra = t_sombra;
                }
            }
            tmin = t;
        }
    }
    return color;
}



int main() {

    // LUZ----------------------------------------------------------------------------------------------
    LuzPuntual luz(1.0, 1.0, 1.0, 500.0, 500.0, -400.0);
    LuzPuntual luz_ambiente(1.0, 1.0, 1.0, 0.0, 0.0, 0.0);
    // ESCENA--------------------------------------------------------------------------------------------
    Punto3D centro1(0.0, 0.0, -400.0);
    double radio1 = 200;
    Esfera esfera1(centro1, radio1);   
    esfera1.establecerColor(0.30, 0.20, 0.0);

    // Punto3D centro2(250.0, 280.0, -400.0);
    // double radio2 = 100;
    // Esfera esfera2(centro2, radio2);   
    // esfera2.establecerColor(0.0, 0.0, 0.49);

    Punto3D A1( -600, 200, -3600);     
    Punto3D B1( -600, -400, 0);
    Punto3D C1( 600, 200, -3600);
    Triangulo triangulo1( B1, C1, A1 );
    triangulo1.establecerColor( 0.10, 0.20, 0.30 );

    Punto3D A2( -600, -400, 0);     
    Punto3D B2( 600, -400, 0);
    Punto3D C2( 600, 200, -3600);
    Triangulo triangulo2( A2, B2, C2 );
    triangulo2.establecerColor( 0.10, 0.20, 0.30 );



    Punto3D A3( -300, 0, 0);     
    Punto3D B3( 300, 0, 0);
    Punto3D C3( 300, 200, -500);
    Triangulo triangulo3( A3, B3, C3 );
    triangulo3.establecerColor( 0.60, 0.20, 0.30 );

    // Punto3D A(0,-800,0);
    // Vector3D v(0.8,0.4,0.7);
    // Plano p(A,v.hat());
    // p.establecerColor(0.2,0.2,0.2);




    vector<ObjetoGeometrico*> escena;
    
    // escena.push_back(&esfera2);
    escena.push_back(&esfera1);
    escena.push_back(&triangulo1);
    escena.push_back(&triangulo2);
    escena.push_back(&triangulo3);

    // VIEWPLANE
    // int hres = 800;
    // int vres = 600;
    int hres = 1200;
    int vres = 800;
    double s = 1.0;
    ViewPlane vp(hres, vres, s);



    // UTILITARIO PARA GUARDAR IMAGEN -------------------------------------------------------------------
     int dpi = 72;
    int width = vp.hres;
    int height = vp.vres;
    int n = width * height;
    ColorRGB* pixeles = new ColorRGB[n];


    

    // ALGORITMO
    for(int fil = 0; fil < vp.vres; fil++)
    {
        for ( int col = 0; col < vp.hres; col++) 
        {
             // Disparar un rayo
            Vector3D direccion(0.0, 0.0, -1.0);
            double x = vp.s * ( col - vp.hres/2 + 0.5 );
            double y = vp.s * ( fil - vp.vres/2 + 0.5 );
            double z = 0;
            Punto3D origen(x, y, z);
            Rayo rayo(origen, direccion);

            pixeles[fil*width+col].r = obtenerColorPixel(rayo, escena, luz, luz_ambiente).r;
            pixeles[fil*width+col].g = obtenerColorPixel(rayo, escena, luz, luz_ambiente).g;
            pixeles[fil*width+col].b = obtenerColorPixel(rayo, escena, luz, luz_ambiente).b;
        }
    }    
    savebmp("img.bmp", width, height, dpi, pixeles);
    return 0;
}