#define _USE_MATH_DEFINES
#include "Geom.h"
#include "Punkt.h"
#include <iostream>
#include <math.h>

using namespace std;

Geom::Geom(Punkt p, int radius)
{
	setRadius(radius);
	position.setX(p.getX());
	position.setY(p.getY());
}
Geom::Geom(Punkt p, int laenge, int breite)
{
	setBreite(breite);
	setLaenge(laenge);
	position.setX(p.getX());
	position.setY(p.getY());
}
void Geom::setRadius(int radius){
	this->radius = radius;
	this->breite = 0;
	this->laenge = 0;
}
void Geom::setBreite(int breite){
	this->radius = 0;
	this->breite = breite;
	if (!(this->laenge > 0))
		this->laenge = 0;
}
void Geom::setLaenge(int laenge){
	this->laenge = laenge;
	this->radius = 0;
	if (!(this->breite > 0))
		this->breite = 0;
}
double Geom::getUmfang(){
	if (this->radius == 0){
		return ((2 * this->breite) + (2 * this->laenge));
	}
	else if (this->breite == 0 && this->laenge == 0){
		return (2 * M_PI*this->radius);
	}
	else{
		cout << "no matching pattern found return 0";
		return 0;
	}
}

void Geom::print(){
	if (this->radius == 0){
		cout << "Die Breite beträgt: " << this->breite << endl;
		cout << "Die Laenge beträgt: " << this->laenge << endl;;
		cout << "Der Umfang beträgt: " << this->getUmfang() << endl;
	}
	else if (this->breite == 0 && this->laenge == 0){
		cout << "Der Radius beträgt: " << this->radius << endl;
		cout << "Der Umfang beträgt: " << this->getUmfang() << endl;
	}
}

bool Geom::enthaelt(Punkt p){
	int mx, my;
	if (this->position.getX() < p.getX() || this->position.getY() < p.getY()){
		cout << "position x " << this->position.getX() << endl;
		cout << "position y " << this->position.getY() << endl;
		cout << "Punkt ist nicht in der Koordinate!" << endl;
		return false;
	}
	else{
		if (this->breite == 0 && this->laenge == 0){
			cout << "Hallo ich bin ein Kreis!!!!" << endl;
			mx = this->position.getX() + this->radius;
			my = this->position.getY() + this->radius;
			if (p.getX() > (mx + this->radius) || p.getY() > (my + this->radius)){
				cout << "Punkt ist nicht in der Koordinate!" << endl;
				return false;
			}
			else {
				cout << "Punkt ist in der Koordinate!" << endl;
				return true;
			}
		}
		else if (this->radius == 0){
			cout << "Hallo ich bin ein Rechteck/Quadrat!!!!" << endl;
			mx = this->position.getX() + this->laenge;
			my = this->position.getY() + this->breite;
			if (p.getY() > my || p.getX() > mx){
				cout << "Punkt ist nicht in der Koordinate!" << endl;
				return false;
			}
			else {
				cout << "Punkt ist in der Koordinate!" << endl;
				return true;
			}
		}
		return false;
	}
}

Geom::~Geom()
{
}