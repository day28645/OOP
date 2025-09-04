#include <iostream>
using namespace std;

class Rectangle {
	
	private:
		static int num;		//count object
		int width;
		int length;
		
	public:
	//constructor overloading
	Rectangle() {			//default constructor
		num++;
		set(0,0);
		cout << num << endl;
	}
	Rectangle(int w) {
		num++;
		set(w,0);
		cout << num << endl;
	}
	Rectangle(int w, int l) {
		num++;
		set(w,l);
		cout << num << endl;
	}
	~Rectangle() {			//destructor
		num--;
		cout << num << endl;
	}
//set function
void set(int w, int l) {	
	width = w;
	length = l;
}
void setWidth(int w) {width = w;}
void setLength(int l) {length = l;}

//get function
int getWidth() {return width;}
int getLength() {return length;}

//scopre operator under class Point
void show(void);
int areaRec(void);
int perimeterRec(void);
void addWidth(Rectangle);
void decreaseLength(Rectangle);

//count function
static int count() {return num;}	
};
//static num = 0
int Rectangle::num;
void Rectangle::show() {
	cout << "Width = " << width << endl;
	cout << "Length = " << length << endl;
	cout << endl;
}
//Find Area
int Rectangle::areaRec() {
	int area;
	area = width * length;
	cout << "Area = " << area << endl;
}
//Find Perimeter
int Rectangle::perimeterRec() {
	int perimeter;
	perimeter = (2 * width) + (2 * length);
	cout << "Perimeter = " << perimeter << endl;
}
//Add Width
void Rectangle::addWidth(Rectangle z) {
	int add;
	add = width + z.width;
	cout << "After add width = " << add << endl;
}
//Decrease Length
void Rectangle::decreaseLength(Rectangle p) {
	int decrease;
	decrease = length - p.length;
	length = length - decrease;
	cout << "After decrease length = " << decrease << endl;
}
int main()
{
	cout << "Assignment 2 : Class and Object & Count Object" << endl;
	cout << "Count Object" << endl;
	cout << "Count:" << Rectangle::count() << endl;
	Rectangle a;
	cout << "Return by className.get()" << endl;
	cout << "Width = " << a.getWidth() << endl;
	cout << "Length = " << a.getLength() << endl;
	a.show();
	cout << "---------------------------------------------"<< endl;	
	{
	Rectangle b(6,7);
	cout << "Count:" << Rectangle::count() << endl;
	
	//Add Width
	b.addWidth(b);
	cout << "Return by className.get()" << endl;
	cout << "Width = " << b.getWidth() << endl;
	cout << "Length = " << b.getLength() << endl;
	b.show();
	}
	cout << "---------------------------------------------"<< endl;	
	Rectangle c(8,9);
	cout << "Count:" << Rectangle::count() << endl;
	Rectangle d(10,11);
	cout << "Count:" << Rectangle::count() << endl;
	
	//Find Area
	c.areaRec();
	cout << "Return by className.functionArea" << endl;	
	cout << "Area = " << c.areaRec() << endl;
	cout << "---------------------------------------------"<< endl;
	
	//Find Perimeter
	d.perimeterRec();
	cout << "Return by className.functionPerimeter" << endl;
	cout << "Perimeter = " << d.perimeterRec() << endl;
	cout << "---------------------------------------------"<< endl;
	
	//Decrease Length
	d.decreaseLength(c);
	cout << "Return by className.functionDecreaseLength" << endl;
	cout << "After decrease Width = " << d.getWidth() << endl;
	cout << "After decrease Length = " << d.getLength() << endl;
	d.show();
}
