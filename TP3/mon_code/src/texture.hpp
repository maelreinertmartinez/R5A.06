#ifndef TEXTURE_HPP_
#define TEXTURE_HPP_

#include "couleurRVB.hpp"
#include "stdio.h"
#include "objet3D.hpp"
#include "ppm.hpp"

class Objet3D;

class Texture
{
protected:
  Objet3D * objet;

public:
  Texture(Objet3D * objet) {
    this->objet = objet;
  }

  virtual RVB getColor(Point3D p, float u, float v) = 0 ;
  
};



class Damier: public Texture {
protected :
  RVB col1;
  RVB col2;
  float taille;
public: 
  Damier(Objet3D * objet, float t, RVB c1, RVB c2) : 
    Texture(objet) {
      col1 = c1;
      col2 = c2;
      taille = t;
  }

  RVB getColor(Point3D p, float u, float v);
};



class Bitmap: public Texture {

protected:
  PPM map;
  float resolution;
  float offsetX;
  float offsetY;
  float scale;

public: 

  Bitmap(Objet3D * objet, char* filename, float sc = 1, float offX=0, float offY=0) : 
    Texture(objet) {
      map = PPM(filename);
      resolution = 1;
      offsetX = offX;
      offsetY = offY;
      scale = sc;
  }

  RVB getColor(Point3D p, float u, float v);

};

class Color: public Texture {

public: 

  Color(Objet3D * objet) : 
    Texture(objet) {

  }

  RVB getColor(Point3D p, float u, float v);

};

#endif /* TEXTURE_HPP_ */
