#ifndef PIXELMAP_HPP
#define PIXELMAP_HPP

#include "bases3d.hpp"
#include "ppm.hpp"

////////////////////////////////////////////////////////////////// C_PIXELMAP

class Pixelmap {
protected:

	int largeur; // Largeur de l'image
	int hauteur; // Hauteur de l'image
	RVB * map; // Ensemble des couleurs contenues dans l'image

public:

	// Constructeur
	Pixelmap(int l = 320, int h = 200) {
		largeur = l;
		hauteur = h;
		map = new RVB[largeur * hauteur];
	}
	~Pixelmap() {
		delete[] map;
	}

	// Lecture
	int Largeur() const {
		return largeur;
	}
	int Hauteur() const {
		return hauteur;
	}
	RVB Map(int i) const {
		return map[i];
	} // ATTENTION!!! : 0 <= i < largeur*hauteur
	RVB Map(int x, int y) const {
		return map[(y * largeur) + x];
	} // ATTENTION!!! : (0,0) <= (x,y) < (largeur,hauteur)

	// Ecriture
	void Map(int i, const RVB & c) {
		map[i] = c;
	} // ATTENTION!!! : 0 <= i < largeur*hauteur
	
	void Map(int x, int y, const RVB & c) {
		map[(y * largeur) + x] = c;
	} // ATTENTION!!! : (0,0) <= (x,y) < (largeur,hauteur)

	// Methodes
	void Correction(float); // Correction Gamma

	void Normaliser(); // Normalisation de l'image

	void toPPM(PPM &) const; // Transfert vers ppm
};

#endif

