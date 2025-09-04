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
		//cout << "count Rec(0,0) = " << num << endl;
	}
	Rectangle(int w) {
		num++;
		set(w,0);
		//cout << "count Rec(w,0) = " << num << endl;
	}
	Rectangle(int w, int l) {
		num++;
		set(w,l);
		//cout << "count Rec(w,l) = " << num << endl;
	}
	~Rectangle() {			//destructor
		num--;
		//cout << "count Rec(-) = " << num << endl;
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
int areaRec();
int perimeterRec();
void show(void);

//count function
static int count() {return num;}	
};

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

void Rectangle::show() {
	int area, perimeter;
	cout << "Width = " << width << endl;
	cout << "Length = " << length << endl;
	cout << "Area = " << areaRec() << endl;
	cout << "Perimeter = " << perimeterRec() << endl;
}

//static num = 0
int Rectangle::num;

class MyRect {
	
	private:
		
		int row, col;
		Rectangle**a;
		
		void initial() {						
			a = new Rectangle*[row];			
			for(int i = 0; i < row; i++)
				a[i] = new Rectangle[col];
		}
				
		void del() {
			if(a!=0) {
			for(int i = 0; i < row; i++)
				delete[] a[i];				
			delete[] a;						
			}
		}
		
	public:
		
		MyRect();
		MyRect(int r,int c);
		~MyRect();
		
		void reset(int r, int c);
		void setRect();
		
		void setRect(int r, int c, int w, int l) {a[r][c].set(w,l);}
		Rectangle getRect(int r, int c);
		
		void show();
};

MyRect::MyRect() {
	//a = 0;
	row = 2;
	col = 3;
	MyRect::initial();
}

MyRect::MyRect(int r,int c) {
	row = r;
	col = c;
	MyRect::initial();
}

MyRect::~MyRect() {
	MyRect::del();
}

void MyRect::reset(int r,int c) {
	MyRect::del();
	row = r;
	col = c;
	MyRect::initial();
}

void MyRect::setRect() {
	int data, data2;
	for (int i=0; i<row; i++) {
		for(int j=0; j<col; j++) {
		cout << "Input data a["<< i <<"]["<< j <<"] = ";
		cout << "Width = " ; cin >> data;
		cout << "Input data a["<< i <<"]["<< j <<"] = ";					
		cout << "Length = "; cin >> data2;
		
		//ref - a[r][c].set(w,l)
		a[i][j].setWidth(data);
		a[i][j].setLength(data2); 		
		}
	}
}

Rectangle MyRect::getRect(int r,int c) {
	return a[r][c];
}

void MyRect::show() {
	for (int i=0; i<row; i++) {
		for(int j=0; j<col; j++) {
			cout << "Width a["<< i <<"]["<< j <<"] = " << a[i][j].getWidth() << endl;
			cout << "Length a["<< i <<"]["<< j <<"] = " << a[i][j].getLength() << endl;
			cout << "Area a["<< i <<"]["<< j <<"] = " << a[i][j].areaRec() << endl;
			cout << "Perimeter a["<< i <<"]["<< j <<"] = " << a[i][j].perimeterRec() << endl;
		}
	}
}

int main() 
{
	cout << "Assignment 3 : Dynamic Object & Dynamic Array of Objects" << endl;
	
	MyRect z;
	z.setRect();
	z.show();
	cout << "\n*****************************************************\n" << endl;
	
	z.reset(1,2);
	z.setRect();
	z.show();
	cout << "\n*****************************************************\n" << endl;
	
	z.reset(2,3);
	z.setRect(1,2,3,4);
	z.show();
	cout << "\n*****************************************************\n" << endl;
	
	Rectangle p;
	p = z.getRect(0,0);
	p.show();
	p = z.getRect(0,1);
	p.show();
	p = z.getRect(0,2);
	p.show();
	p = z.getRect(1,0);
	p.show();
	p = z.getRect(1,1);
	p.show();
	p = z.getRect(1,2);
	p.show();
	
	MyRect y;
	y.setRect();
	y.show();
	
	y.reset(2,2);
	y.setRect();
	y.show();
	
	Rectangle g;
	g = y.getRect(0,0);
	g.show();
	g = y.getRect(0,1);
	g.show();
	g = y.getRect(0,2);
	g.show();
	g = y.getRect(1,0);
	g.show();
	g = y.getRect(1,1);
	g.show();
	g = y.getRect(1,2);
	g.show();
	g = y.getRect(2,0);
	g.show();
	g = y.getRect(2,1);
	g.show();
	g = y.getRect(2,2);
	g.show();
	
}
