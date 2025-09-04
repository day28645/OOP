#include <iostream>
using namespace std;

class Rectangle {
	private:
		int width;
		int length;
		static int count;
	public:
		Rectangle() {
			setRectangle(0,0);
			setWidth(0);
			setLength(0);
			count++;
		}
		Rectangle(int w,int l) {
			setRectangle(w,l);
			setWidth(w);
			setLength(l);
			count++;
		}
		~Rectangle() {
			cout << "\nDestructor class Rectangle" << endl;
			count--;
		}
		void setRectObj(Rectangle rectangle) {
			width = rectangle.getWidth();
			length = rectangle.getLength();
		}
		void setRectangle(int w,int l) {
			width = w;
			length = l;
		}
		void setWidth(int w) {width = w;}
		void setLength(int l) {length = l;}
		int getWidth() {return width;}
		int getLength() {return length;}
		int findArea() {
			int area = width * length;
			return area;
		}
		int findPerimeter() {
			int perimeter = (width * 2) + (length * 2);
			return perimeter;
		}
		void show() {
			cout << "\n-----------Rectangle" << endl;
			cout << "width : " << width << endl;
			cout << "length : " << length << endl;
			cout << "area : " << findArea() << endl;
			cout << "perimeter : " << findPerimeter() << endl;
		}
		static int getCount() {return count;}
};
int Rectangle::count;

class MyRect {
	private:
		int row;
		int col;
		Rectangle **array;
		
		void createArray() {
			array = new Rectangle*[row];
			for(int i = 0; i < row; i++)
				array[i] = new Rectangle[col];
		}
		void deleteArray() {
			if(array!=0)
			for(int i = 0; i < row; i++) 
				delete[] array[i];
			delete[] array;	
		}
	public:
		MyRect() {
			row = 1;
			col = 2;
			createArray();
		}
		MyRect(int r,int c) {
			row = r;
			col = c;
			createArray();
		}
		~MyRect() {
			deleteArray();
		}
		//no parameter
		void setRect() {
			int data1,data2;
			for(int i = 0; i < row; i++) {
				for(int j = 0; j < col; j++) {
					cout << "Input data array["<< i <<"]["<< j <<"] = ";
					cout << "width = "; 
					cin >> data1;
					
					cout << "Input data array["<< i <<"]["<< j <<"] = ";
					cout << "length = "; 
					cin >> data2;
					
					array[i][j].setWidth(data1);
					array[i][j].setLength(data2);
				}
			}
		}
		//all parameter
		void setRect(int r,int c,int w,int l) {array[r][c].setRectangle(w,l);}
		void setRect2(Rectangle rectangle,int r,int c) {
			//rectangle.show();
			rectangle.getWidth();
			rectangle.getLength();
			//# setRectangle(w,l)
			//# setRectangle(rectangle.getWidth(),rectangle.getLength())
			array[r][c].setRectangle(rectangle.getWidth(),rectangle.getLength());	
		}
		void reset(int r,int c) {
			deleteArray();
			row = r;
			col = c;
			createArray();
		}
		Rectangle getRect(int r,int c) {
			return array[r][c];
		}
		void show() {
			cout << "\n-----------MyRect" << endl;
			for(int i = 0; i < row; i++) {
				for(int j = 0; j < col; j++) {
					cout << "width in array["<< i <<"]["<< j <<"] = " << array[i][j].getWidth() << endl;
					cout << "length in array["<< i <<"]["<< j <<"] = " << array[i][j].getLength() << endl;
					cout << "area in array["<< i <<"]["<< j <<"] = " << array[i][j].findArea() << endl;
					cout << "perimeter in array["<< i <<"]["<< j <<"] = " << array[i][j].findPerimeter() << endl;
				}
			}
		}
};

int main()
{
	cout << "Assignment 3 : Dynamic Object and Dynamic Array of Objects" << endl << endl;
	cout << "Count : " << Rectangle::getCount() << endl << endl;
	Rectangle r1; 
	r1.setWidth(7);
	r1.setLength(9);
	r1.show();
	cout << "Count : " << Rectangle::getCount() << endl << endl;
	
	Rectangle r2(5,7); 
	r2.findArea();
	r2.findPerimeter();
	r2.show();
	cout << "Count : " << Rectangle::getCount() << endl << endl;
	
	cout << "\n*****************************************************\n" << endl;
	
	MyRect myrec1;
	Rectangle r3(2,3);
	myrec1.setRect2(r3,0,1);
	myrec1.show();
	
	/*
	MyRect myrec1;
	myrec1.setRect();
	myrec1.show();
	cout << "Count default: " << Rectangle::getCount() << endl << endl;
	
	myrec1.reset(2,3);
	myrec1.setRect();
	myrec1.show();
	cout << "Count 2 parameter: " << Rectangle::getCount() << endl << endl;
	
	myrec1.reset(2,3);
	myrec1.setRect(1,2,3,4);
	myrec1.show();
	cout << "Count 4 parameter: " << Rectangle::getCount() << endl << endl;
	*/
	Rectangle rec;
	rec = myrec1.getRect(0,0);
	rec.show();
	rec = myrec1.getRect(0,1);
	rec.show();
	rec = myrec1.getRect(1,0);
	rec.show();
	rec = myrec1.getRect(1,1);
	rec.show();
	
	return 0;
}
