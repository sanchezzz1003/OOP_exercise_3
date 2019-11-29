#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Point{
private:
	double x, y;
public:
	Point();
	Point(double new_x, double new_y);
	void setCoordinates(double new_x, double new_y);
	void dispPoint();
	double getX();
	double getY();
};

class Figure{
private:
	int ID;
protected:
	int q;
	vector <Point> angles;
public:
	Figure(int new_ID, int new_q);
	void setAngles(int i, double new_x, double new_y);
	void setID(int new_ID);
	void Angles();
	virtual double Square();
	virtual void Center();
	int getID();
	int getq();
	void Copy(Figure a);
	virtual ~Figure();
};

class Triangle : public Figure{
public:
	Triangle(int new_ID, int new_q);
	double Square();
	bool TrCheck();
	void Center();
	~Triangle();
};

class Hexagon : public Figure{
private:
	Point center;
	double length; 
public:
	Hexagon(int new_ID, int new_q);
	double Square();
	void Center();
	~Hexagon();
};

class Octagon : public Figure{
private:
	Point center;
	double length; 
public:
	Octagon(int new_ID, int new_q);
	double Square();
	void Center();
	~Octagon();
};