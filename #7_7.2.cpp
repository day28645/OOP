#include <iostream>
#include <string.h>
using namespace std;

class Date {
	
	private:
		int day;
		int month;
		int year;
	public:
		Date() {setBD(0,0,0);}
		Date(int d,int m,int y) {setBD(d,m,y);}
		~Date() {}
		
void setBD(int d,int m,int y) {
	day = d;
	month = m;
	year = y;}
void setDay(int d) {day = d;}
void setMonth(int m) {month = m;}
void setYear(int y) {year = y;}

int getDay() {return day;}
int getMonth() {return month;}
int getYear() {return year;}

void showBD() {cout << "Day = " << day << " / " << "Month = " << month << " / "  << "Year = " << year << endl;}
void show(void);
};

void Date::show() {
	cout << "Day :" << day << endl;
	cout << "Month :" << month << endl;
	cout << "Year :" << year << endl;
}

class Address {
	
	private:
		char num[10];
		char road[20];
		char district[20];
		char province[20];
		char code[10];
		
	public:
		Address() {setLocation("House","Road","Distric","Province","Code");}
		Address(char* n,char* r,char* d,char* p,char* c) {setLocation(n,r,d,p,c);}
		~Address() {}
		
void setLocation(char* n,char* r,char* d,char* p,char* c) 
{strcpy(num,n); strcpy(road,r); strcpy(district,d); strcpy(province,p); strcpy(code,c);}
void setNum(char* n) {strcpy(num,n);;}
void setRoad(char* r) {strcpy(road,r);}
void setDistrict(char* d) {strcpy(district,d);}
void setProvince(char* p) {strcpy(province,p);}
void setCode(char* c) {strcpy(code,c);}

char* getNum() {return num;}
char* getRoad() {return road;}
char* getDistrict() {return district;}
char* getProvince() {return province;}
char* getCode() {return code;}

void showLocation() {cout << num << " " << road << " " << district <<" " << province << " " << code << endl;}
void show(void);
};

void Address::show() {
	cout << "House no :" << num << endl;
	cout << "Road :" << road << endl;
	cout << "District :" << district << endl;
	cout << "Province :" << province << endl;
	cout << "Code :" << code << endl;
}

//Base class
class Person {
	
	private:
		char fname[20];
		char lname[20];
		Date date;
		Address address;
		
	public:
		Person() {
			setName("Firstname","Lastname");
			date.setBD(0,0,0);
			address.setLocation("House","Road","Distric","Province","Code");
		}
		Person(char* f,char* l) {
			setName(f,l);
			date.setBD(0,0,0);
			address.setLocation("House","Road","Distric","Province","Code");
		}
		Person(char* f,char* l,Date d,Address a) {
			setPerson(f,l,d,a);
		}
		~Person() {}

//Person		
void setName(char* f,char* l) {strcpy(fname,f); strcpy(lname,l);}
void setFname(char* f) {strcpy(fname,f);}
void setLname(char* l) {strcpy(lname,l);}
//Date
void setDA(Date date,Address address) {this -> date = date; this -> address = address;}
void setDate(Date date) {this -> date = date;}
//Address
void setAddress(Address address) {this -> address = address;}
//Person, Date, Person
void setPerson(char* f,char* l,Date date,Address address) 
{strcpy(fname,f); strcpy(lname,l); this -> date = date; this -> address = address;}

char* getFname() {return fname;}
char* getLname() {return lname;}
Date getDate() {return date;}
Address getAddress() {return address;}

void showName() {cout << fname << " " << lname << endl;}
void show(void);
};

void Person::show() {
	cout << "Firstname :" << fname << endl;
	cout << "Lastname :" << lname << endl;
	cout << "Date :" << date.getDay() << "/" << date.getMonth() << "/" << date.getYear() << endl;
	cout << "Address :" << address.getNum() << " " << address.getRoad() << " " << address.getDistrict()
	<< " " << address.getProvince() << " " << address.getCode() << endl;
}

//Derived class
class Student:virtual public Person {
	
	private:
		char id[20];
		
	public:
		Student() {
			setID("Student ID");
		}
		Student(char* f,char* l,char* i,Date d,Address a):Person(f,l,d,a) {
			setID(i);
		}
		~Student() {}

void setID(char* i) {strcpy(id,i);}
char* getID() {return id;}

void showID() {cout << "ID:" << id << endl;}
void show(void);
};

void Student::show() {
	cout << "Firstname :" << getFname() << endl;
	cout << "Lastname :" << getLname() << endl;
	cout << "ID :" << id << endl;
	getDate().showBD();
	getAddress().showLocation();
}

//Derived class 
class Teacher:virtual public Person {
	
	private:
		char course[20];
		
	public:
		Teacher() {
			setCourse("Course");
		}
		Teacher(char* f,char* l,char *c,Date d,Address a):Person(f,l,d,a) {
			setCourse(c);
		}
		~Teacher() {}
		
void setCourse(char* c) {strcpy(course,c);}
char* getCourse() {return course;}

void showCourse() {cout << "Course:" << course << endl;}
void show(void);
};

void Teacher::show() {
	cout << "Firstname :" << getFname() << endl;
	cout << "Lastname :" << getLname() << endl;
	cout << "Course :" << course << endl;
	getDate().showBD();
	getAddress().showLocation();
}

class TeachingAssistant:public Student, public Teacher{
	
	private:
		char skill[20];
		char payment[10];
		
	public:
		TeachingAssistant() {
			setTA("Skill","Payment");	
		}
		TeachingAssistant(char* s,char* p,char* f,char* l,char* i,char *c,Date d,Address a):Student(f,l,i,d,a), Teacher(f,l,c,d,a), Person(f,l,d,a) {
			setTA(s,p);
		}
		~TeachingAssistant() {}
		
void setTA(char* s,char *p) {strcpy(skill,s); strcpy(payment,p);}
void setSkill(char* s) {strcpy(skill,s);}
void setPayment(char* p) {strcpy(payment,p);}

char* getSkill() {return skill;}
char* getPayment() {return payment;}

void showTA() {cout << skill << " / " << payment;}
void show(void);
};

void TeachingAssistant::show() {
	cout << "Firstname :" << getFname() << endl;
	cout << "Lastname :" << getLname() << endl;
	cout << "ID :" << getID() << endl;
	cout << "Course :" << getCourse() << endl;
	getDate().showBD();
	getAddress().showLocation();
	cout << "Skill(s) :" << skill << endl;
	cout << "Payment :" << payment << endl;
}

                                
int main()
{
	cout << "Assignment 6 : Single Interitance" << endl << endl;
	cout << "-------------Inheriting attributes-------------" << endl << endl;
	cout << "-------------------class Date-------------------" << endl;
	Date d1;
	d1.showBD();
	d1.setBD(01,12,2023);
	d1.show();
	cout << endl;
	
	cout << "-----------------class Address-----------------" << endl;
	Address a1;
	a1.showLocation();
	a1.setLocation("1","Jingumae","Shibuya","Tokyo","0001");
	a1.show();
	cout << endl;
	
	cout << "-----------------class Person------------------" << endl;
	Person p1("Geto","Suguru",d1,a1);
	p1.show();
	cout << endl;
	
	cout << "---class Person (class Date,class Address)----" << endl;
	Person p2("Maki","Zenin",d1,a1);
	p2.show();
	cout << endl;
	
	cout << "-------------Inheriting constructors-------------" << endl;
	cout << endl;
	cout << "-----------------class Person------------------" << endl;
	Person p3("Kota","Miura",d1,a1);
	p3.show();
	cout << endl;
	
	cout << "-----------------class Student-----------------" << endl;
	Student s1("Tobirama","Senju","420",d1,a1);
	s1.show();
	cout << endl;
	
	cout << "-----------------class Teacher-----------------" << endl;
	Teacher t1("Hashirama","Senju","Linguistics",d1,a1);
	t1.show();
	cout << endl;
	cout << "-----------------------------------------------" << endl;
	cout << endl;

	cout << "Assignment 7 : Multiple Interitance" << endl;
	cout << endl;
	cout << "------------class TeachingAssistant------------" << endl;
	TeachingAssistant ta1("Analysis","10000","Tobirama","Senju","420","Linguistics",d1,a1);
	ta1.show();
}

