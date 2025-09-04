#include <iostream>
using namespace std;

class Point{
	
	private:			//attribute x, y, name
	static int num;		//count object
	double x;
	double y;
	string name;
	
	public:
		//constrcutor overloading
		Point() {						//default constructor
			num++;		//1(v1)
			set(0,0,"0");
			cout << "(0,0,0)=" << num << endl;
			}			
		Point(double x) {
			num++;		
			set(x,0,"n");
			cout << "(x,0,0)=" << num << endl;
			}
		Point(double x, double y) {
			num++;		//2(v2)
			set(x,y,"n");
			cout << "(x,y,0)=" << num << endl;
		}
		Point(double x, double y, string n) {
			num++;		//2(v4)
			set(x,y,"n");
			cout << "(x,y,n)=" << num << endl;
		}
		Point(string n) {
			num++;		//3(v3)
			set(0,0,"n");
			cout << "(0,0,n)=" << num << endl;
		}
		~Point() {		//deconstructor
			num--;		//2-1=1(v3) > 1-1=0(v2) > 1(-v4) > 0(-v1)
			cout << num << endl;
		}
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
	cout << "Count:" << Point::count() << endl;		//0(no object)
	
	//constructor and deconstructor
	Point v1;							//1(v1) , 0(-v1)
	cout << "Count:" << Point::count() << endl;
	{
		Point v2(6,7), v3("peak");		//2(v2) , 3(v3) , 3-1=2(-v3) , 2-1= 1(-v2) , 
		cout << "Count:" << Point::count() << endl;
	}
	Point v4(1);						//2(v4) , 1(-v4)
	cout << "Count:" << Point::count() << endl;
	
	//Timeline constructor and deconstructor(count object)
	// 0 > 1 > 2 > 3 > 2 > 1 > 2 > 1 > 0
	// 0(no object) > 1(v1) > 2(v2) > 3(v3) > 2(-v3) > 1(-v2) > 2(v4) > 1(-4) > 0(-v1)
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
