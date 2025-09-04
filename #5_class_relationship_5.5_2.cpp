#include <iostream>
#include <string.h>
using namespace std;

class Circle;

class Point{
	
	private:			
	static int num;		
	double x;
	double y;
	char name[10];
	
	public:
		Point() {						
			num++;		
			set(0,0,"n");
			cout << "(0,0,0)=" << num << endl;
			}			
		Point(double x) {
			num++;		
			set(x,0,"n");
			cout << "(x,y,0)=" << num << endl;
			}
		Point(double x, double y) {
			num++;		
			set(x,y,"n");
			cout << "(x,y,n)=" << num << endl;
		}
		Point(double x, double y, char *n) {
			num++;		
			set(x,y,n);
			cout << "(x,y,n)=" << num << endl;
		}
			Point(char* n) {
			num++;		
			set(0,0,n);
			cout << "(0,0,n)=" << num << endl;
		}
		~Point() {		
			num--;		
			cout << num << endl;
		}
		//friend function
		friend bool CheckCircle(Point,Circle);
		
void set(double x, double y, char* n) {			
	this -> x = x;	 
	this -> y = y;	
	strcpy(name,n);
  }

void setX(double x) {this -> x = x;}
void setY(double y) {this -> y = y;}
void set(double x, double y) {this -> x = x; this -> y = y;}
void setName(char* n) {strcpy(name,n);}

double getX() {return this -> x;}
double getY() {return this -> y;}
char* getName() {return name;}
void show(void);		
double dot(Point&);
Point midpoint(Point&, Point&); 

static int count() {return num;}
};

int Point::num;			

void Point::show() {
	cout << "X = " << x << endl;
	cout << "Y = " << y << endl;
	cout << "Name = " << name << endl;
}

double Point::dot(Point & d) {
	return (d.x * x) + (d.y * y);
}

Point Point::midpoint(Point & m, Point & n) {
		x = (m.getX() + n.getX()) / 2;
		y = (m.getY() + n.getY()) / 2;
		return Point(x,y);
}

class Circle
{
	private:
	static int num;	
	double r;
	Point c;
	
	public:
		Circle() {
			r = 0;
			c.set(1,2);
		}
		Circle(double r) {
			setR(r);
			c.set(1,2);
		}
		Circle(double r,Point c) {
			setRC(r,c);
		}
		~Circle() {}
		/*friend function
		friend bool CheckCircle(Point,Circle);*/

void setR(double r) {this -> r = r;}
void setC(Point c) {this -> c = c;}		                    
void setRC(double r, Point c) {this -> r = r; this -> c = c;}

double getR() {return r;}
Point getC() {return c;}
void show(void);
};

void Circle::show() {
	cout << "radius = " << r << endl;
	cout << "centerX = " << c.getX() << endl;
	cout << "centerY = " << c.getY() << endl;
}

//global function
bool CheckCircle(Point point9,Circle circle1) {
	if ((point9.x - circle1.getC().x) * (point9.x - circle1.getC().x) + 
		(point9.y - circle1.getC().y) * (point9.y - circle1.getC().y) <= circle1.getR() * circle1.getR())
		return true;
	else 
		return false;
}

int main()		
{
	cout << "Assignment 2 : Class and Object & Count Object" << endl;
	cout << endl;
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
	cout << "---------------------------------------------"<< endl;
	
	cout << "Assignment 4 : Reference" << endl;
	Point point3, point4;
	point3 = 2;
	point4.setX(1);
	point4.setY(8);

	double dot1;
	
	dot1 = point4.dot(point3);
	point4.show();
	cout << "dot 1 = " << dot1 << endl;
	
	Point point5, point6;
	Point point7, point8;
	point7.setX(4);
	point8.setY(5);
	point5 = point6.midpoint(point7,point8);
	point5.show();
	point6.show();
	
	cout << "---------------------------------------------"<< endl;
	
	cout << "Assignment 5 : class Relationship" << endl;
	Point point9(1,2);
	point9.show();
	Circle circle1(1, point9);
	circle1.show();

	CheckCircle(point9,circle1)?
	
	cout << "Inside Circle" << endl : cout << "Outside Circle" << endl;
	
	cout << "---------------------------------------------"<< endl;
	
	Point point10(5,6);
	point10.show();
	Circle circle2(1, point10);
	circle2.show();

	CheckCircle(point10,circle2)? 
	
	cout << "Inside Circle" << endl : cout << "Outside Circle" << endl;
	
}
