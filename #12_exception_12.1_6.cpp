#include <iostream>
#include <string.h>
#include <exception>
using namespace std;

class A {
	private:
		int x;
	public: 
		A() {x = 1;}
		virtual ~A() {cout << "A Destructored called\n" << endl;}
		int getA() {return x;}	
		virtual void throwf() throw(char,double,int,float) {
			throw 017;
		}
};
class B: public A {
	private:
		double x;
	public:
		B() {x = 1.23;}
		~B() {cout << "B Destructored called\n" << endl;}
		double getB() {return x;}
		void throwf() throw(int) {
			throw 123;
		}
};
class C: public B {
	private:
		char x;
	public:
		C() {x = 'C';}
		~C() {cout << "C Destructored called\n" << endl;}
		char getC() {return x;}
		void throwbase() {
			throwf();
		}
		void f() throw(float) {
			throw 0.75;
		}
};
class D: public C {
	private:
		char* x;
	public:
		D() {
		x = new char;
		strcpy(x,"class D");
		}
		~D() {
			delete x;
			cout << "D Destructored called\n" << endl;
		}
		char* getD() {
			return x;
		}
		void f() throw(double) {
			throw 0.25;
		}
		void func2() throw(double){
			cout << "func2()" << endl;
			throw 1.23;
		}
		void func1() throw(double){
			cout << "func1()" << endl;
			func2();
			throw 2.34;
		}
		void func() throw(double){
			cout << "func()" << endl;
			func1();
			throw 3.45;
		}
};

class MyException: public exception {
	public:
		virtual const char* what() const throw() {
			return "There is/are Exception";
		}
};
template <class T>
T catchx(T x) {
	try {
		throw x;
	}
	catch(int x) {
		cout << "Exception : Int = " << x << endl;
	}
	catch(double x) {
		cout << "Exception : Double = " << x << endl;
	}
	catch(char x) {
		cout << "Exception : Char = " << x << endl;
	}
	catch(...) {
		cout << "Other Exception = " << x << endl;
	}
}
void catchorder() throw(A) {
	cout << "Throw B" << endl;
	B b;
	throw b;
}
int main()
{
	cout << "Assignment 12 : Exception Handling(12.1 , 12.2)" << endl << endl;
	A a;
	B b;
	C c;
	D d;
	cout << "Throw A" << endl;
	catchx(a.getA());
	cout << "Throw B" << endl;
	catchx(b.getB());
	cout << "Throw C" << endl;
	catchx(c.getC());
	cout << "Throw D" << endl;
	catchx(d.getD());
	
	cout << "\n*******************************************\n" << endl;
	
	cout << "Assignment 12 : Exception Handling(12.3)" << endl << endl;
	try {
		catchorder();
	}
	catch(D) {
		cout << "catch D" << endl;
	}
	catch(C) {
		cout << "catch C" << endl;
	}
	catch(B) {
		cout << "catch B" << endl;
	}
	catch(A) {
		cout << "catch A" << endl;
	}
	catch(...) {
		cout << "no catch" << endl;
	}
	
	cout << "\n-------------new catch order-------------\n" << endl << endl;
	
	try {
		catchorder();
	}
	catch(A) {
		cout << "catch A" << endl;
	}
	catch(B) {
		cout << "catch B" << endl;
	}
	catch(C) {
		cout << "catch C" << endl;
	}
	catch(D) {
		cout << "catch D" << endl;
	}
	catch(...) {
		cout << "no catch" << endl;
	}
	
	cout << "\n*******************************************\n" << endl;
	
	cout << "Assignment 12 : Exception Handling(12.4)" << endl << endl;
	try {
		try {
			try {
				d.func();
			}
			catch(char* d) {
				throw;
			}
		}
		catch(...) {
			throw;
		}
	}
	catch(double i) {
		cout << "Exception : " << i << endl;
	}

	cout << "\n*******************************************\n" << endl;
	
	cout << "Assignment 12 : Exception Handling(12.5)" << endl << endl;
	A* x = new D();
	try {
		cout << "call from class D" << endl;
		x->throwf();
	}
	catch(int i) {
		cout << "Exception : " << i << endl;
	}
	delete x;
	
	try {
		cout << "call from class C" << endl;
		c.throwf();
	}
	catch(int i) {
		cout << "Exception : " << i << endl;
	}
	
	try {
		cout << "call from class B" << endl;
		b.throwf();
	}
	catch(int i) {
		cout << "Exception : " << i << endl;
	}
	
	cout << "\n*******************************************\n" << endl;
	
	cout << "Assignment 12 : Exception Handling(12.6)" << endl << endl;
	MyException ex;
	try {
		throw ex;
	}
	catch(exception& e) {
		cout << e.what() << endl;
	}
	
	cout << "\n*******************************************\n" << endl;

	return 0;
}
