#include <iostream>
#include <string.h>
using namespace std;

class Point{
	
	private:			//attribute x, y, name
	static int num;		//count object
	double x;
	double y;
	char name[10];
	
	public:
		//constrcutor overloading
		Point() {						//default constructor
			num++;		//1(v1)
			set(0,0,"0");
			cout << "(0,0,0)=" << num << endl;
			}			
		Point(double x) {
			num++;		
			set(x,0,"0");
			cout << "(x,0,0)=" << num << endl;
			}
		Point(double x, double y) {
			num++;		
			set(x,y,"0");
			cout << "(x,y,0)=" << num << endl;
		}
		Point(double x, double y, char *n) {
			num++;		
			set(x,y,n);
			cout << "(x,y,n)=" << num << endl;
		}
		Point(char* n) {
			num++;		
			set(0,0,n);
			cout << "(x,y,n)=" << num << endl;
		}
		~Point() {		//deconstructor
			num--;		
			cout << "(0,0,0)=" << num << endl;
		}
void set(double x, double y, char* n) {			//set function provides value to x, y, name
	this -> x = x;	//this pointer x, in case of point but it can change to other objects 
	this -> y = y;	//this pointer y, in case of point but it can change to other objects
	strcpy(name,n);
  }

//set function for attribute x, y, name
void setX(double x) {this -> x = x;}
void setY(double y) {this -> y = y;}
void setName(char* n) {strcpy(name,n);}

//get function for attribute x, y, name
double getX() {return this -> x;}
double getY() {return this -> y;}
char* getName() {return name;}
void show(void);		//non-inline function

//count function 
static int count() {return num;}
};

//static num = 0
int Point::num;			

//scope operator under class Point 
void Point::show() {
	cout << "X = " << x << endl;
	cout << "Y = " << y << endl;
	cout << "Name = " << name << endl;
}
int main()		//note! - using all object in class
{
	cout << "Assignment 2 : Class and Object & Count Object" << endl;
	cout << "Count Object" << endl;
	//this count function apply to no object
	cout << "Count:" << Point::count() << endl;		
	
	Point v1;							
	cout << "Count:" << Point::count() << endl;
	v1.show();
	{
		Point v2(6,7), v3("mission");		
		cout << "Count:" << Point::count() << endl;
		v2.show();
		v3.show();
	}
	Point v4(8,1,"moon");						
	cout << "Count:" << Point::count() << endl;
	v4.show();
	Point v5("apple");
	cout << "Count:" << Point::count() << endl;
	v5.show();
	
	cout << "---------------------------------------------"<< endl;
	
	cout << "Assignment 1 : Class and Object" << endl;
	Point point1, point2;		//point1 and point2 are object of Point
	//point1 and point2 can use set function bc it is public
	point1.set(2,3,"dot");
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
