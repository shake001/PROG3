#pragma once
class Punkt
{
private:
	int x;
	int y;
public:
	Punkt(int x=0, int y=0);
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
	void print();
	~Punkt();
};

