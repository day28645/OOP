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
		Rectangle(int w, int l, char*n) {
		num++;
		set(w,l,"0");
		cout << num << endl;
	}
	~Rectangle() {			//destructor
		num--;
		cout << num << endl;
	}
	
	//operator overloading 
	//member
	Rectangle operator++() {		//prefix
		++width;
		return *this;
	} 
	//member
	Rectangle operator++(int) {		//postfix
		++length;
		return *this;
	}
	//operator overloading
	//friend 
	friend Rectangle operator--(Rectangle & x) {		//prefix
		if(x.width > 1)
		{
			x.width--;
			return x;
		}
		else
		{
			cout << "The mininum width of rectangle must be one";
			return x;
		}
	}
	//operator overloading
	//friend 
	friend Rectangle operator--(Rectangle & y, int) {	//postfix
		if(y.length > 1)
		{
			y.length--;
			return y;
		}
		else
		{
			cout << "The mininum length of rectangle must be one";
			return y;
		}
	}

//binary operator
bool operator < (Rectangle);
bool operator <= (Rectangle);
bool operator > (Rectangle);
bool operator >= (Rectangle);
bool operator != (Rectangle);

//subscript operator
int operator[](int);

//function call operator
int operator()(int,int);
int operator()(int);
int operator()();

//set function
void set(int w, int l, char*n) {	
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
void Rectangle::show() {
	cout << "Width = " << width << endl;
	cout << "Length = " << length << endl;
	cout << "Area = " << areaRec() << endl;
	cout << "Perimeter = " << perimeterRec() << endl;
	cout << endl;
}
//Find Area
int Rectangle::areaRec() {
	int area;
	area = width * length;
}
//Find Perimeter
int Rectangle::perimeterRec() {
	int perimeter;
	perimeter = (2 * width) + (2 * length);
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

//binary operator
bool Rectangle::operator < (Rectangle m) {
	return (areaRec() < m.areaRec()) ? true : false;
}
bool Rectangle::operator <= (Rectangle m) {
	return (areaRec() <= m.areaRec()) ? true : false;
}
bool Rectangle::operator > (Rectangle m) {
	return (areaRec() > m.areaRec()) ? true : false;
}
bool Rectangle::operator >= (Rectangle m) {
	return (areaRec() >= m.areaRec()) ? true : false;
}
bool Rectangle::operator != (Rectangle m) {
	return (areaRec() != m.areaRec()) ? true : false;
}

//subscript operator
int Rectangle::operator[](int i) {
	switch(i) {
		case 1 : return width;
		case 2 : return length;
		case 3 : return areaRec();
		case 4 : return perimeterRec();
		default : return 0;
	}
}

//function call operator
int Rectangle::operator()(int a,int b) {
	return (width + a) + (length + b);
}
int Rectangle::operator()(int a) {
	return perimeterRec() * a;
}	
int Rectangle::operator()() {
	return areaRec() * 2;
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
	Rectangle d(10,11,"iphone");
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
	
	cout << "---------------------------------------------"<< endl;
	
	cout << "Assignment 8 : Operator Overloading" << endl;
	cout << endl;
	
	//operator overloading 
	Rectangle Operator1;
	Operator1.show();
	
	Rectangle Operator11;
	Operator11.show();
	
	Rectangle Operator2(0,0);
	Operator2.show();
	
	Rectangle Operator3(1,1);
	Operator3.show();
	
	Rectangle Operator33(3,3);
	Operator33.show();
	
	Rectangle Operator4(2,2);
	Operator4.show();
	
	Rectangle Operator5, Operator6;
	cout << endl;	
	
	cout << "------------call prefix / postfix------------"<< endl;	
	//call member - prefix(++Operator2)
	//Operator1 = (0,0)	/ ++Operator2 : (0,0) > (1,0)
	Operator1 = ++Operator2;	
	Operator1.show();
	Operator2.show();
	
	//call member - postfix(Operator3++)
	//Operator3++ : (1,1) > (1,2)
	Operator5 = Operator3++;
	Operator5.show();
	Operator3.show();
	
	//call friend - prefix(--Operator33)
	//Operator11 = (0,0) / --Operator33 : (3,3) > (2,3)
	Operator11 = --Operator33; 
	Operator11.show();
	Operator33.show();
	
	//call friend - postfix(Operator4--)
	//Operator4-- : (2,2) > (2,1)
	Operator6 = Operator4--;
	Operator6.show();
	Operator4.show();
	cout << endl;
	
	cout << "---------------binary operator---------------"<< endl;		
	Operator3.show();		//Operator3(1,2)
	Operator4.show();		//Operator4(2,1)
	cout << endl;
	
	cout << "############ Case : Area < Area #############" << endl;	
	//Operator3(1,2) < Operator4(2,1)
	if(Operator3 < Operator4)
		cout << "Operator3" << " < " << "Operator4" << endl;
	else
		cout << "Operator3" << " >= " << "Operator4" << endl;
		cout << endl;
	
	cout << "############ Case : Area > Area #############" << endl;
	//Operator3(1,2) > Operator4(2,1)
	if(Operator3 > Operator4)
		cout << "Operator3" << " > " << "Operator4" << endl;
	else
		cout << "Operator3" << " <= " << "Operator4" << endl;
		cout << endl;
	
	cout << "############ Case : Area != Area #############" << endl;
	//Operator3(1,2) > Operator4(2,1)	
	if(Operator3 != Operator4)
		cout << "Operator3" << " is not equal " << "Operator4" << endl;
	else
		cout << "Operator3" << " equal " << "Operator4" << endl;
		cout << endl;
		
	cout << "--------------subscript operator--------------"<< endl;
		
	Rectangle Sub(2,3);
	cout << "Width = " << Sub[1] << endl;
	cout << "Length = " << Sub[2] << endl;
	cout << "Area = " << Sub[3] << endl;
	cout << "Perimeter = " << Sub[4] << endl;
	cout << "Default = " << Sub[0] << endl;
	cout << endl;
	
	cout << "------------function call operator------------"<< endl;
	
	Rectangle call1(2,4);
	call1.show();
	/*int Rectangle::operator()(int a,int b) {
	return (width + a) + (length + b);
	}*/
	cout << "(width + 0) + (length + 0) = " << call1(0,0) << endl;
	cout << "(width + 1) + (length + 1) = " << call1(1,1) << endl;
	cout << "(width + 1) + (length + 2) = " << call1(1,2) << endl;
	
	/*int Rectangle::operator()(int a) {
		return perimeterRec() * a;
	}*/	
	cout << "Perimeter * 0 = " << call1(0) << endl;
	cout << "Perimeter * 1 = " << call1(1) << endl;
	cout << "Perimeter * 2 = " << call1(2) << endl;
	
	/*int Rectangle::operator()() {
		return areaRec() * 2;
	}*/
	cout << "Area * 2 = " << call1() << endl;
	
}
