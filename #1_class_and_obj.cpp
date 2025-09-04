#include <iostream>
using namespace std;

class Point{
	
	private:		//attribute x, y, name
	double x;
	double y;
	string name;
	
	public:
void set(double x, double y, string n) {			//set function provides value to x, y, name
	this -> x = x;	//this pointer x, in case of point but it can change to other objects 
	this -> y = y;	//this pointer y, in case of point but it can change to other objects
	name = n;
  }
  
//set function for attribute x, y, name
void setX(double x) {this -> x = x;}
void setY(double y) {this -> y = y;}
void setName(string n) {name = n;}

//get function for attribute x, y, name
double getX() {return this -> x;}
double getY() {return this -> y;}
string getName() {return name;}

void show(void);		//non-inline function
};
void Point::show() {	//scope operator Point function
	
	cout << "X = " << x << endl;
	cout << "Y = " << y << endl;
	cout << "Name = " << name << endl;
}
int main()		//note - using all object in class
{
	cout << "Assignment 1 : Class and Object" << endl;
	Point point1, point2;		// point1 and point2 are object of Point
	point1.set(2,3,"dot");		//point1 and point2 can use set function bc it is public
	point2.set(4,5,"mark");
	cout << "---------------------------------------------"<< endl;
	cout << "Return by className.get()" << endl;
	//point1
	cout << "X1 = " << point1.getX() << endl;
	cout << "Y1 = " << point1.getY() << endl;
	cout << "Name1 = " << point1.getName() << endl;
	//point2
	cout << "X2 = " << point2.getX() << endl;
	cout << "Y2 = " << point2.getY() << endl;
	cout << "Name2 = " << point2.getName() << endl;
	cout << "---------------------------------------------"<< endl;	
	cout << "Return by show function" << endl;
	point1.show();
	point2.show();
}
