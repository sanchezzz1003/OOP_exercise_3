#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#include "Figure.h"

Point::Point(){
	x = 0;
	y = 0;
}

Point::Point(double new_x, double new_y){
	x = new_x;
	y = new_y;
}

void Point::setCoordinates(double new_x, double new_y){
	x = new_x;
	y = new_y;
}

void Point::dispPoint(){
	cout << "x= " << x << ", y= " << y << endl;
}

double Point::getX(){
	return x;
}

double Point::getY(){
	return y;
}

Figure::Figure(int new_ID, int new_q){
	ID = new_ID;
	q = new_q;
}

void Figure::setAngles(int i, double new_x, double new_y){
	angles[i].setCoordinates(new_x, new_y);
}

void Figure::setID(int new_ID){
	ID = new_ID;
}

void Figure::Angles(){
	cout << "Figure " << getID() << " is ";
	if (getq() == 3) cout << "Triangle\n";
	if (getq() == 6) cout << "Hexagon\n";
	if (getq() == 8) cout << "Octagon\n";
	for (int i = 0; i < q; ++i){
		angles[i].dispPoint();
	}
}

double Figure::Square(){ return 0; }
void Figure::Center(){}

int Figure::getID(){
	return ID;
}

int Figure::getq(){
	return q;
}

//void Figure::Copy(Figure a){}

Figure::~Figure(){}

Triangle::Triangle(int new_ID, int new_q) : Figure(new_ID, new_q){
	double new_x, new_y;
	angles.reserve(3);
	do{
		for (int i = 0; i < 3; ++i){
			cout << "Enter coordinates:\n";
			cout << "X: \n";
			while (!(cin >> new_x))
			    {
			        cin.clear(); 
			        cout << "Wrong coordinate\nX: ";
			        char c;
			        cin >> c;
			    }
			    cout << "Y: \n";
			while (!(cin >> new_y))
			    { 
			        cin.clear(); 
			        cout << "Wrong coordinate\nY: ";
			        char c;
			        cin >> c;
			    }
			setAngles(i, new_x, new_y);
			if (!TrCheck()) cout << "Wrong triangle\n";
		}
	} while (!TrCheck());
}

double Triangle::Square(){
	return abs((angles[1].getX()-angles[0].getX())*(angles[2].getY()-angles[0].getY())-(angles[2].getX()-angles[0].getX())*(angles[1].getY()-angles[0].getY()))/2;
}

bool Triangle::TrCheck(){
	double sqLength;
	sqLength = pow(angles[1].getX()-angles[2].getX(),2) + pow(angles[1].getY()-angles[2].getY(),2);
	if (pow(angles[1].getX()-angles[3].getX(),2) + pow(angles[1].getY()-angles[3].getY(),2) - sqLength > 0.01) return false;
	if (pow(angles[2].getX()-angles[3].getX(),2) + pow(angles[2].getY()-angles[3].getY(),2) - sqLength > 0.01) return false;
	return true;
}

void Triangle::Center(){
	double sumx = 0, sumy = 0;
	for(int i = 0; i < q; ++i){
		sumx += angles[i].getX();
		sumy += angles[i].getY();
	}
	cout << "Center coordinates:\nx= " << sumx/q << " y= " << sumy/q << endl;
}

Triangle::~Triangle(){
	cout << "Destructor called for Triangle " << getID() << endl;
}

Hexagon::Hexagon(int new_ID, int new_q) : Figure(new_ID, new_q){
	double new_x, new_y;
	angles.reserve(6);
	double new_length, rotate, pos = 0;
	cout << "Enter coordinates of the center of hexagon:\n";
	cin >> new_x >> new_y;
	cout << "Enter length of side and rotation:\n";
	cin >> new_length >> rotate;
	length = new_length;
	while (rotate < 0 || rotate > 0.33333333333333333333){
		cout << "Wrong rotate. Enter value from 0 to 0.33333333333333333333";
		cin >> rotate;
	}
	center.setCoordinates(new_x, new_y);
	for(int i = 0; i < 6; ++i){
		if (rotate == 0 && pos == 0.99999999999999999999)
			setAngles(i, new_x+cos(M_PI*rotate+M_PI*pos)*new_length, new_y);
		else if(rotate == 0.16666666666666666666 && (pos == 0.33333333333333333333 || pos == 1.33333333333333333333))
			setAngles(i, new_x, new_y+sin(M_PI*rotate+M_PI*pos)*new_length);
		else
			setAngles(i, new_x+cos(M_PI*rotate+M_PI*pos)*new_length, new_y+sin(M_PI*rotate+M_PI*pos)*new_length);
		pos += 0.33333333333333333333;
	}
}

double Hexagon::Square(){
	return 3*sqrt(3)/2*length*length;
}

void Hexagon::Center(){
	cout << "Center coordinates:\n" << "x = " << center.getX() << " y= " << center.getY() << endl;
}

Hexagon::~Hexagon(){
	cout << "Destructor called for Hexagon " << getID() << endl;
}

	
Octagon::Octagon(int new_ID, int new_q) : Figure(new_ID, new_q){
	double new_x, new_y;
	angles.reserve(8);
	double new_length, rotate, pos = 0;
	cout << "Enter coordinates of the center of octagon:\n";
	cin >> new_x >> new_y;
	cout << "Enter length of side and rotation:\n";
	cin >> new_length >> rotate;
	length = new_length;
	while (rotate < 0 || rotate > 0.25){
		cout << "Wrong rotate. Enter value from 0 to 0.25 (0.25 = 0) ";
		cin >> rotate;
	}
	center.setCoordinates(new_x, new_y);
	for(int i = 0; i < 8; ++i){	
			if (rotate == 0 && pos == 1)
			setAngles(i, new_x+cos(M_PI*rotate+M_PI*pos)*new_length, new_y);
		else if(rotate == 0 && (pos == 0.5 || pos == 1.5))
			setAngles(i, new_x, new_y+sin(M_PI*rotate+M_PI*pos)*new_length);
		else
			setAngles(i, new_x+cos(M_PI*rotate+M_PI*pos)*new_length, new_y+sin(M_PI*rotate+M_PI*pos)*new_length);
		pos += 0.25;
	}
}

double Octagon::Square(){
	return 3*sqrt(3)/2*length*length;
}

void Octagon::Center(){
	cout << "Center coordinates:\n" << "x = " << center.getX() << " y= " << center.getY() << endl;
}

Octagon::~Octagon(){
	cout << "Destructor called for Octagon " << getID() << endl;
}
