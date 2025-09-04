#include <iostream>
#include <string.h>
using namespace std;

class Rectangle {
	
	private:
		static int num;		//count object
		int width;
		int length;
		char name[50];
		
	public:
	//constructor overloading
	Rectangle() {			//default constructor
		num++;
		set(0,0,"0");
		cout << num << endl;
	}
	Rectangle(int w) {
		num++;
		set(w,0,"0");
		cout << num << endl;
	}
	Rectangle(int w, int l) {
		num++;
		set(w,l,"0");
		cout << num << endl;
	}
	Rectangle(int w, int l, char *n) {
		num++;
		set(w,l,n);
		cout << num << endl;
	}
	~Rectangle() {			//deconstructor
		num--;
		cout << num << endl;
	}
//set function
void set(int w, int l, char *n) {	
	width = w;
	length = l;	
	strcpy(name,n);
}
void setWidth(int w) {width = w;}
void setLength(int l) {length = l;}
void setName(char *n) {strcpy(name,n);}

//get function
int getWidth() {return width;}
int getLength() {return length;}
char* getName() {return name;}

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

//scope operator under class Point 
void Rectangle::show() {
	cout << "Width = " << width << endl;
	cout << "Length = " << length << endl;
	cout << "Name = " << name << endl;
	cout << endl;
}

//Find Area
int Rectangle::areaRec() {
	int area;
	return area = width * length;
}
//Find Perimeter
int Rectangle::perimeterRec() {
	int perimeter;
	return perimeter = (2 * width) + (2 * length);
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
	cout << "Count Object" << endl;
	cout << Rectangle::count() << endl;
	Rectangle a;
	cout << a.getWidth() << endl;
	cout << a.getLength() << endl;
	cout << a.getName() << endl;
	a.show();
	
	{
	Rectangle b(6,7);
	cout << Rectangle::count() << endl;
	
	//Add Width
	b.addWidth(b);
	cout << b.getWidth() << endl;
	cout << b.getLength() << endl;
	cout << b.getName() << endl;
	b.show();
	}
	
	Rectangle c(8,9);
	cout << Rectangle::count() << endl;
	Rectangle d(10,11,"iphone");
	cout << Rectangle::count() << endl;
	
	//Find Area
	c.areaRec();	
	cout << "Area = " << c.areaRec() << endl;
	
	//Find Perimeter
	d.perimeterRec();
	cout << "Perimeter = " << d.perimeterRec() << endl;
	
	//Decrease Length
	d.decreaseLength(c);
	cout << d.getWidth() << endl;
	cout << d.getLength() << endl;
	cout << d.getName() << endl;
	d.show();
}
