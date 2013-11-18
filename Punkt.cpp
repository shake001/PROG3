#include <iostream>
#include "Punkt.h"
#include "Geom.h"
using namespace std;

Punkt::Punkt(int x, int y)
{
	setX(x);
	setY(y);
}
Punkt::~Punkt()
{
}

void Punkt::setX(int x){
	this->x = x;
}
void Punkt::setY(int y){
	this->y = y;
}
int Punkt::getX(){
	return this->x;
}
int Punkt::getY(){
	return this->y;
}

void Punkt::print() {

}
void main(){
	
	Punkt p1(0, 0);
	Punkt p2(3, 4);
	Geom g1(p1, 5);
	Geom g2(p2, 4, 4);
	g1.print();
	g2.print();
	g2.setLaenge(5);
	Punkt pt1(17, 2);
	Punkt pt2(5, 15);
	g1.enthaelt(pt1);
	g1.enthaelt(pt2);
	if (g1.getUmfang() > g2.getUmfang()) {
		cout << "Umfang von g1 > g2" << endl;
	}
	else {
		cout << "Umfang von g1 <= g2" << endl;
	}

}