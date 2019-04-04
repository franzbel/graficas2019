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


// #include "ObjetoGeometrico.h"

using namespace std;

ColorRGB obtenerColorPixel(const Rayo& r, vector<ObjetoGeometrico*> objetos, LuzPuntual luz){
    
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


            color.r = objetos[i]->obtenerColor().r * luz.color.r * std::max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor().r * luz.color.r * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),10000);
            color.g = objetos[i]->obtenerColor().g * luz.color.g * std::max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor().g * luz.color.g * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),10000);
            color.b = objetos[i]->obtenerColor().b * luz.color.b * std::max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor().b * luz.color.b * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),10000);



            cout<<"[ "<<color.r<<", "<<color.g<<", "<<color.b<<" ]"<<endl;
            tmin = t;
        }
    }
    return color;
}


int main() {

    // LUZ----------------------------------------------------------------------------------------------
    LuzPuntual luz(1.0, 1.0, 1.0, 0, 0, -30);
    // ESCENA--------------------------------------------------------------------------------------------
    Punto3D centro1(0.0, 0.0, -400.0);
    double radio1 = 120;
    Esfera esfera1(centro1, radio1);   
    esfera1.establecerColor(0.5, 0.3, 0.3);

    Punto3D centro2(150.0, 50.0, -200.0);
    double radio2 = 100;
    Esfera esfera2(centro2, radio2);   
    esfera2.establecerColor(0.3, 0.3, 0.2);


    vector<ObjetoGeometrico*> escena;
    escena.push_back(&esfera1);
    escena.push_back(&esfera2);


    // VIEWPLANE
    int hres = 800;
    int vres = 600;
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
            double z = 100;
            Punto3D origen(x, y, z);
            Rayo rayo(origen, direccion);

            pixeles[fil*width+col].r = obtenerColorPixel(rayo, escena, luz).r;
            pixeles[fil*width+col].g = obtenerColorPixel(rayo, escena, luz).g;
            pixeles[fil*width+col].b = obtenerColorPixel(rayo, escena, luz).b;
        }
    }    
    savebmp("img.bmp", width, height, dpi, pixeles);
    return 0;
}