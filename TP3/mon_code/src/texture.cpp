#include <math.h>
#include "texture.hpp"

#include <iostream>
using namespace std;



RVB Damier::getColor(Point3D p, float u, float v){
    int x = static_cast<int>(floor(u * 0.5f));
    int y = static_cast<int>(floor(v * 0.5f));

    bool isPair = (x + y) % 2 == 0;

    return isPair ? RVB(0, 0, 0) : RVB(1, 1, 1);
}



RVB Bitmap::getColor(Point3D p, float u, float v){
    u = fmod(u, 1.0f);
    v = fmod(v, 1.0f);
    if (u < 0) u += 1.0f;
    if (v < 0) v += 1.0f;

    int x = static_cast<int>(u * (map.Largeur() - 1));
    int y = static_cast<int>(v * (map.Hauteur() - 1));
    
    return map.MapRVB(x, y);
}



RVB Color::getColor(Point3D p, float u, float v){
	return objet->Couleur();
}