#pragma once
#include "Punkt.h"
class Geom
{
private:
	int typ;
	int laenge;
	int breite;
	int radius;
	int farbe;
	Punkt position;

public:
	Geom(Punkt  p, int radius);
	Geom(Punkt  p, int laenge, int breite);
	void setFarbe(int farbe);
	double getUmfang();
	double getFlaeche();
	void setLaenge(int laenge);
	void setBreite(int breite);
	void setRadius(int radius);
	void print();
	bool enthaelt(Punkt p);
	~Geom();
};