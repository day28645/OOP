#include <iostream>
using namespace std;

class Shape {							//base class
		
	public : 
		Shape() {cout << "Shape Constructor Called\n";}
		virtual ~Shape() {cout << "Shape Destructor Called\n";}

virtual float area() = 0;	
virtual void print(ostream& os) {cout << "Shape ostream called\n";}
virtual void input(istream& is) {cout << "Shape istream called\n";}
virtual void show() = 0;
};

class TwoDimensional:public Shape {		//derived class
	
	private :
		string name;
		
	public :
		TwoDimensional() {cout << "TwoDimensional Constructor Called\n";}
		TwoDimensional(string n) {
			cout << "TwoDimensional Default Constructor Called\n";
			name = n; 
		}
		~TwoDimensional() {
			cout << "TwoDimensional Destructor Called\n";
		}

void setName(string n) {name = n;}
string getName() {return name;}
float area() = 0;
};

class Rectangle:public TwoDimensional {
	private :
		int width,length;
		
	public : 
		Rectangle() {
			cout << "Rectangle Constructor Called\n";
			setRectangle(0,0);
			setName("Rectangle");
		}
		Rectangle(int w,int l,string n) {
			cout << "Rectangle Default Constructor Called\n";
			setRectangle(w,l);
			setName(n);
		}
		~Rectangle() {
			cout << "Rectangle Destructor Called\n";
		}

void setRectangle(int w,int l) {
	width = w;
	length = l;	
}
int getWidth() {return width;}
float getLength() {return length;}
float area() {
	int area = width * length;
	return area;
}
void show() {
	cout << "Width = " << width << "/ Lenght = " << length << endl;
	cout << "Area = "<< area() << endl;
}
void print(ostream& os) {
	os << "Width :" << width << endl;
	os << "Length :" << length << endl;
}
void input(istream& is) {
	cout << "Enter width :"; is >> width;
	cout << "Enter length :"; is >> length;
}
};

class Triangle:public TwoDimensional {
	private :
		int height,base;

	public : 
		Triangle() {
			cout << "Triangle Constructor Called\n";
			setTriangle(0,0);
			setName("Triangle");
		}
		Triangle(int h,int b,string n) {
			cout << "Triangle Default Constructor Called\n";
			setTriangle(h,b);
			setName(n);
		}
		~Triangle() {
			cout << "Triangle Destructor Called\n";
		}

void setTriangle(int h,int b) {
	height = h;
	base = b;
}	
int getHeigth() {return height;}
int getBase() {return base;}
float area() {
	float area = 0.5 * base * height;
	return area;
}
void show() {
	cout << "Base = " << base << "/ Height = "<< height << endl;
	cout << "Area = "<< area() << endl;
}
void print(ostream& os) {
	os << "Heigth :" << height << endl;
	os << "Base :" << base << endl;
}
void input(istream& is) {
	cout << "Enter height :"; is >> height;
	cout << "Enter base :"; is >> base;
}
};

class Circle:public TwoDimensional {
	private :
		int radius;
		
	public : 
		Circle() {
			cout << "Circle Constructor Called\n";
			setCircle(0);
			setName("Circle");
		}
		Circle(int r,string n) {
			cout << "Circle Default Constructor Called\n";
			setCircle(r);
			setName(n);
		}
		~Circle() {cout << "Circle Destructor Called\n";}
		
void setCircle(int r) {
	radius = r;
}
int getRadius() {return radius;}
float area() {
	float area = 3.14 * radius * radius;
	return area;
}
void show() {
	cout << "Radius = "<< radius << endl;
	cout << "Area = " << area() << endl;
}
void print(ostream& os) {
	os << "Radius :" << radius << endl;
}
void input(istream& is) {
	cout << "Enter radius :"; is >> radius;
}
};

class ThreeDimensional:public Shape {		//derived class
	
	private :
		string name;
		
	public :
		ThreeDimensional() {cout << "ThreeDimensional Constructor Called\n";}
		ThreeDimensional(string n) {
			cout << "ThreeDimensional Default Constructor Called\n";
			name = n;
		}
		~ThreeDimensional() {cout << "ThreeDimensional Destructor Called\n";}

void setName(string n) {name = n;}
string getName() {return name;}
virtual float volume() = 0; 
};

class Cylinder:public ThreeDimensional {
	private :
		int height;
		int radius;
		
	public : 
		Cylinder() {
			{cout << "Cylinder Constructor Called\n";}
			setCylinder(0,0);
			setName("Cylinder");
		}
		Cylinder(int r,int h,string n) {
			cout << "Cylinder Default Constructor Called\n";
			setCylinder(r,h);
			setName(n);
		}
		~Cylinder() {cout << "Cylinder Destructor Called\n";}

void setCylinder(int r,int h) {
	radius = r;
	height = h;
}
int getRadius() {return radius;}
int getHeigth() {return height;}
float area() {
	float area = (2 * 3.14 * radius * height) + (2 * 3.14 * radius * radius);
	return area;
}
float volume() {
	float area = 3.14 * radius * radius * height;
	return area;
}
void show() {
	cout<< "Radius = " << radius << "/ Height = " << height << endl;
	cout<< "Area = " << area() << endl;
	cout<< "Volume = "<< volume() << endl;
}
void print(ostream& os) {
	os << "Radius :" << radius << endl;
	os << "Heigth :" << height << endl;
}
void input(istream& is) {
	cout << "Enter radius :"; is >> radius;
	cout << "Enter height :"; is >> height;
}
};

class Sphere:public ThreeDimensional {
	private :
		int radius;
		
	public : 
		Sphere() {
			cout << "Sphere Constructor Called\n";
			setSphere(0);
			setName("Sphere");
		}
		Sphere(int r,string n) {
			cout << "Sphere Default Constructor Called\n";
			setSphere(r);
			setName(n);
		}
		~Sphere() {cout << "Sphere Destructor Called\n";}

void setSphere(int r) {
	radius = r;
}
int getRadius() {return radius;}
float area() {
	float area = 4 * 3.14 * radius * radius;
	return area;
}	
float volume() {
	float area = ( 4 / 3) * 3.14 * radius * radius;
	return area;
}
void show() {
	cout<< "Radius = " << radius << endl;
	cout<< "Area = " << area() << endl;
	cout<< "Volume = "<< volume() << endl;
}
void print(ostream& os) {
	os << "Radius :" << radius << endl;
}
void input(istream& is) {
	cout << "Enter radius :"; is >> radius;
}
};

ostream& operator<<(ostream& os, Shape* s) {
	s -> show();
	s -> print(os);
	return os;
}
istream& operator>>(istream& is, Shape* s) {
	s -> input(is);
	return is;
}
ostream& operator<<(ostream& os, TwoDimensional* tw) {
	cout << tw -> getName() << endl;
	tw -> show();
	return os;
}
istream& operator>>(istream& is, TwoDimensional* tw) {
	cout << "is : " << tw -> getName() << endl;
	tw -> input(is);
	return is;
}
ostream& operator<<(ostream& os, ThreeDimensional* th) {
	cout << th -> getName() << endl;
	th -> show();
	return os;
}
istream& operator>>(istream& is, ThreeDimensional* th) {
	cout << "is : " << th -> getName() << endl;
	th -> input(is);
	return is;
}

int main()
{
	cout << "Assignment 10 : Polymorphism and Virtual Function" << endl << endl;
	
	cout << "------------class TwoDimensional------------" << endl << endl;
	TwoDimensional *two[3];
	two[0] = new Rectangle;
	two[1] = new Triangle;
	two[2] = new Circle;
	
	for(int i = 0; i < 3; i++) {
		cin >> two[i]; cout << endl;
		cout << two[i]  << endl;
	}
	for (int i = 0; i < 3; i++) {
		cout << "Area = "<< two[i] -> area() << endl;
	}
	for(int i = 0; i < 3; i++) {
		delete two[i];
	}
	
	cout << "------------class ThreeDimensional------------" << endl << endl;
	ThreeDimensional *three[2];
	three[0] = new Cylinder;
	three[1] = new Sphere;
	
	for(int i = 0; i < 2; i++) {
		cin >> three[i]; cout << endl;
		cout << three[i]  << endl;
	}
	for (int i = 0; i < 2; i++) {
		cout << "Area = "<< three[i] -> area() << endl;
		cout << "Volume = "<< three[i] -> volume() << endl;
	}	
	for(int i = 0; i < 2; i++) {
		delete three[i];
	}
	
}
