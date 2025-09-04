#include <iostream>
#include <string.h>
using namespace std;

class Date {
	
	private:
		int day;
		int month;
		int year;
		char *gift;
		
	public:
		Date() {gift = 0; setBD(0,0,0,"Gift");}
		Date(int d,int m,int y,char* g) {gift = 0; setBD(d,m,y,g);}
		~Date() {delete[] gift;}
		Date& operator=(const Date&da) {	//assignment operator
			if(this==&da) 			
				return *this;
			day = da.day;
			month = da.month;
			year = da.year;	
			delete[] gift;			
			if(da.gift!=0)			
				{gift = new char[strlen(da.gift)+1]; strcpy(gift,da.gift);}
			else
				gift = 0;
				return *this;
		}
		Date(const Date& da) {				//copy constructor
			cout << "copy constructor for class Date is called" << endl;
			
			if(da.gift!=0) {
				day = da.day;
				month = da.month;
				year = da.year;	
				gift = new char[strlen(da.gift)+1]; strcpy(gift,da.gift);
			}else
				gift = 0;
		}
		
void setBD(int d,int m,int y,char* g) {
	day = d;
	month = m;
	year = y;
	delete[] gift; gift = new char[strlen(g)+1]; strcpy(gift,g);}
void setDay(int d) {day = d;}
void setMonth(int m) {month = m;}
void setYear(int y) {year = y;}
void setGift(char* g) {strcpy(gift,g);}

int getDay() {return day;}
int getMonth() {return month;}
int getYear() {return year;}
char* getGift() {return gift;}

void showBD() {cout << "Day = " << day << " / " << "Month = " << month << " / "  << "Year = " << year << " || " << "Gift :" << gift << endl;}
void show(void);

};

void Date::show() {
	cout << "Day :" << day << endl;
	cout << "Month :" << month << endl;
	cout << "Year :" << year << endl;
	cout << "Gift :" << gift << endl;
}

class Address {
	
	private:
		char num[10];
		char road[20];
		char district[20];
		char province[20];
		char code[10];
		char* phone;
		
	public:
		Address() {phone = 0; setLocation("House","Road","Distric","Province","Code","Phone");}
		Address(char* n,char* r,char* d,char* p,char* c,char* ph) {phone = 0; setLocation(n,r,d,p,c,ph);}
		~Address() {delete[] phone;}
		Address& operator=(const Address& a) {		//assignment operator
			if(this==&a)
				return *this;
			strcpy(num,a.num);
			strcpy(road,a.road);
			strcpy(district,a.district);
			strcpy(province,a.province);
			strcpy(code,a.code);
			delete[] phone;
			if(a.phone!=0)
				{phone = new char[strlen(a.phone)+1]; strcpy(phone,a.phone);}
			else
				phone = 0;
				return *this;
		}
		Address(const Address& a) {					//copy constructor
			cout << "copy constructor for class Address is called" << endl;
			strcpy(num,a.num);
			strcpy(road,a.road);
			strcpy(district,a.district);
			strcpy(province,a.province);
			strcpy(code,a.code);
			if(a.phone!=0) {
				phone = new char[strlen(a.phone)+1]; strcpy(phone,a.phone);
			}else
				phone = 0;
		}
		
		
void setLocation(char* n,char* r,char* d,char* p,char* c,char* ph) 
{strcpy(num,n); strcpy(road,r); strcpy(district,d); strcpy(province,p); strcpy(code,c);
delete[] phone; phone = new char[strlen(ph)+1]; strcpy(phone,ph);}
void setNum(char* n) {strcpy(num,n);;}
void setRoad(char* r) {strcpy(road,r);}
void setDistrict(char* d) {strcpy(district,d);}
void setProvince(char* p) {strcpy(province,p);}
void setCode(char* c) {strcpy(code,c);}
void setPhone(char* ph) {strcpy(phone,ph);}

char* getNum() {return num;}
char* getRoad() {return road;}
char* getDistrict() {return district;}
char* getProvince() {return province;}
char* getCode() {return code;}
char* getPhone() {return phone;}

void showLocation() {cout << num << " " << road << " " << district <<" " << province << " " << code << " || " << phone << endl;}
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
		char* nickname;
		Date date;
		Address address;
		
	public:
		Person() {
			nickname = 0; 
			setName("Firstname","Lastname","Nickname");
			date.setBD(0,0,0,"Gift");
			address.setLocation("House","Road","Distric","Province","Code","Phone");
		}
		Person(char* f,char* l,char* n) {
			nickname = 0; 
			setName(f,l,n);
			date.setBD(0,0,0,"Gift");
			address.setLocation("House","Road","Distric","Province","Code","Phone");
		}
		Person(char* f,char* l,char* n,Date d,Address a) {
			nickname = 0; 
			setPerson(f,l,n,d,a);
		}
		~Person() {delete[] nickname;}
		Person& operator=(const Person&p) {				//assignment operator
			if(this==&p)
				return *this;
			strcpy(fname,p.fname);
			strcpy(lname,p.lname);
			date = p.date;
			address = p.address;
			delete[] nickname;
			if(p.nickname!=0)
				{nickname = new char[strlen(p.nickname)+1]; strcpy(nickname,p.nickname);}
			else
				nickname = 0;
				return *this;
		}
		Person(const Person& p) {						//copy constructor
			cout << "copy constructor for class Person is called" << endl;
			strcpy(fname,p.fname);
			strcpy(lname,p.lname);
			date = p.date;
			address = p.address;
			if(p.nickname!=0) {
				nickname = new char[strlen(p.nickname)+1]; strcpy(nickname,p.nickname);
			}else
				nickname = 0;
		}

//Person		
void setName(char* f,char* l,char* n) {strcpy(fname,f); strcpy(lname,l); 
									   delete[] nickname; nickname = new char[strlen(n)+1]; strcpy(nickname,n);}
void setFname(char* f) {strcpy(fname,f);}
void setLname(char* l) {strcpy(lname,l);}
void setNickname(char* n) {strcpy(nickname,n);}
//Date
void setDA(Date date,Address address) {this -> date = date; this -> address = address;}
void setDate(Date date) {this -> date = date;}
//Address
void setAddress(Address address) {this -> address = address;}
//Person, Date, Person
void setPerson(char* f,char* l,char* n,Date date,Address address) 
{strcpy(fname,f); strcpy(lname,l); delete[] nickname; nickname = new char[strlen(n)+1]; strcpy(nickname,n); 
this -> date = date; this -> address = address;}

char* getFname() {return fname;}
char* getLname() {return lname;}
char* getNname() {return nickname;}
Date getDate() {return date;}
Address getAddress() {return address;}

void showName() {cout << fname << " " << lname << " || " << nickname << endl;}
void show(void);
};

void Person::show() {
	cout << "Firstname :" << fname << endl;
	cout << "Lastname :" << lname << endl;
	cout << "Nickname :" << nickname << endl;
	cout << "Date :" << date.getDay() << "/" << date.getMonth() << "/" << date.getYear() << endl;
	cout << "Address :" << address.getNum() << " " << address.getRoad() << " " << address.getDistrict()
	<< " " << address.getProvince() << " " << address.getCode() << endl;
}

//Derived class
class Student:virtual public Person {
	
	private:
		char id[20];
		char* major;
		
	public:
		Student() {
			major = 0;
			setStudent("Student ID","Major");
		}
		Student(char* f,char* l,char* n,char* i,char* m,Date d,Address a):Person(f,l,n,d,a) {
			major = 0;
			setStudent(i,m);
		}
		~Student() {delete[] major;}
		Student& operator=(const Student&s) {					//assignment operator 
			if(this==&s)
				return *this;
			Person::operator=(s);
			strcpy(id,s.id);
			delete[] major;
			if(s.major!=0)
				{major = new char[strlen(s.major)+1]; strcpy(major,s.major);}
			else
				major = 0;
				return *this;
		}
		Student(const Student& s) {								//copy constructor
			cout << "copy constructor for class Student is called" << endl;
			Person::operator=(s);
			strcpy(id,s.id);
			if(s.major!=0) {
				major = new char[strlen(s.major)+1]; strcpy(major,s.major);
			}else
				major = 0;
		}

void setStudent(char* i,char* m) {strcpy(id,i); delete[] major; major = new char[strlen(m)+1]; strcpy(major,m);}
void setID(char* i) {strcpy(id,i);}
void setMajor(char* m) {strcpy(major,m);}

char* getID() {return id;}
char* getMajor() {return major;}

void showStudent() {cout << id << " " << major << endl;}
void show(void);
};

void Student::show() {
	cout << "Firstname :" << getFname() << endl;
	cout << "Lastname :" << getLname() << endl;
	cout << "Nickname :" << getNname() << endl;
	cout << "ID :" << id << endl;
	cout << "Major :" << major << endl;
	getDate().showBD();
	getAddress().showLocation();
}

//Derived class 
class Teacher:virtual public Person {
	
	private:
		char course[20];
		char* degree;
		
	public:
		Teacher() {
			degree = 0;
			setTeacher("Course","Degree");
		}
		Teacher(char* f,char* l,char* n,char *c,char* de,Date d,Address a):Person(f,l,n,d,a) {
			degree = 0;
			setTeacher(c,de);
		}
		~Teacher() {delete[] degree;}
			Teacher& operator=(const Teacher&te) {					//assignment operator 
			if(this==&te)
				return *this;
			Person::operator=(te);
			strcpy(course,te.course);
			delete[] degree;
			if(te.degree!=0)
				{degree = new char[strlen(te.degree)+1]; strcpy(degree,te.degree);}
			else
				degree = 0;
				return *this;
		}
		Teacher(const Teacher& te) {								//copy constructor
			cout << "copy constructor for class Teacher is called" << endl;
			Person::operator=(te);
			strcpy(course,te.course);
			if(te.degree!=0) {
				degree = new char[strlen(te.degree)+1]; strcpy(degree,te.degree);
			}else
				degree = 0;
		}
		
		
void setTeacher(char* c,char* de) {strcpy(course,c); delete[] degree; degree = new char[strlen(de)+1]; strcpy(degree,de);}
void setCourse(char* c) {strcpy(course,c);}
void setDegree(char* de) {strcpy(degree,de);}

char const* getCourse() const {return course;}
char* getDegree() const {return degree;}

void showTeacher() {cout << course << " " << degree << endl;}
void show(void);
};

void Teacher::show() {
	cout << "Firstname :" << getFname() << endl;
	cout << "Lastname :" << getLname() << endl;
	cout << "Nickname :" << getNname() << endl;
	cout << "Course :" << course << endl;
	cout << "Degree :" << degree << endl;
	getDate().showBD();
	getAddress().showLocation();
}

class TeachingAssistant:public Student, public Teacher{
	
	private:
		char skill[20];
		char payment[10];
		char* qualification;
		
	public:
		TeachingAssistant() {
			qualification = 0;
			setTA("Skill","Payment","Qualification");	
		}
		TeachingAssistant(char* s,char* p,char* f,char* l,char* n,char* i,char* m,char *c,char* de,char* q,Date d,Address a):Student(f,l,n,i,m,d,a), Teacher(f,l,n,c,de,d,a), Person(f,l,n,d,a) {
			qualification = 0;
			setTA(s,p,q);
		}
		~TeachingAssistant() {delete[] qualification;}
		TeachingAssistant&operator=(const TeachingAssistant&t) {			//assignment operator
			if(this==&t)
				return *this;
			Student::operator=(t);
			Teacher::setTeacher(const_cast<char*>(t.getCourse()),t.getDegree());
			strcpy(skill,t.skill);
			strcpy(payment,t.payment);
			delete[] qualification;
			if(t.qualification!=0) {
				{qualification = new char[strlen(t.qualification)+1]; strcpy(qualification,t.qualification);}
			}else
				qualification = 0;			
		}
		TeachingAssistant(TeachingAssistant& t)	{							//copy constructor
			cout << "copy constructor for class TeachingAssistant is called" << endl;
			Student::operator=(t);
			Teacher::setTeacher(const_cast<char*>(t.getCourse()),t.getDegree());
			strcpy(skill,t.skill);
			strcpy(payment,t.payment);
			if(t.qualification!=0) {
				qualification = new char[strlen(t.qualification)+1]; strcpy(qualification,t.qualification);
			}else
				qualification = 0;
		}
		
void setTA(char* s,char *p,char* q) {strcpy(skill,s); strcpy(payment,p); delete[] qualification; qualification = new char[strlen(q)+1]; strcpy(qualification,q);}
void setSkill(char* s) {strcpy(skill,s);}
void setPayment(char* p) {strcpy(payment,p);}
void setQualification(char* q) {strcpy(qualification,q);}

char* getSkill() {return skill;}
char* getPayment() {return payment;}
char* getQualification() {return qualification;}

void showTA() {cout << skill << " / " << payment << " || " << qualification;}
void show(void);
};

void TeachingAssistant::show() {
	cout << "Firstname :" << getFname() << endl;
	cout << "Lastname :" << getLname() << endl;
	cout << "Nickname :" << getNname() << endl;
	cout << "ID :" << getID() << endl;
	cout << "Major :" << getMajor() << endl;
	cout << "Course :" << getCourse() << endl;
	cout << "Degree :" << getDegree() << endl;
	getDate().showBD();
	getAddress().showLocation();
	cout << "Skill(s) :" << skill << endl;
	cout << "Payment :" << payment << endl;
	cout << "Qualification :" << qualification << endl;
}

                                
int main()
{
	cout << "Assignment 9 : Other Member Functions" << endl;
	cout << "######AS_6 : Single Interitance######" << endl << endl;
	cout << "-------------Inheriting attributes-------------" << endl << endl;
	cout << "-------------------class Date-------------------" << endl;
	Date d1,d2;
	d1.showBD();
	d1.setBD(01,12,2023,"Cat");
	d1.show();
	cout << endl;
	cout << "============Assignment operator Test============" << endl;
	d2 = d1;		
	d2.show();
	cout << endl;
	cout << "=============Copy Constructor Test=============" << endl;
	Date d3 = d1;
	d3.show();
	cout << endl;
	
	cout << "-----------------class Address-----------------" << endl;
	Address a1,a2;
	a1.showLocation();
	a1.setLocation("1","Jingumae","Shibuya","Tokyo","0001","+1-212-535-7710");
	a1.show();
	cout << endl;
	cout << "============Assignment operator Test============" << endl;
	a2 = a1;
	a2.show();
	cout << endl;
	cout << "=============Copy Constructor Test=============" << endl;
	Address a3 = a1;
	a3.show();
	cout << endl << endl;
	
	cout << "-----------------class Person------------------" << endl;
	Person p1("Geto","Suguru","Gege",d1,a1),p11;
	p1.show();
	cout << endl;
	cout << "============Assignment operator Test============" << endl;
	p11 = p1;
	p11.show();
	cout << endl;
	cout << "=============Copy Constructor Test=============" << endl;
	Person p12 = p1;
	p12.show();
	cout << endl << endl;
	
	cout << "---class Person (class Date,class Address)----" << endl;
	Person p2("Maki","Zenin","Mai",d1,a1),p22;
	p2.show();
	cout << endl;
	cout << "============Assignment operator Test============" << endl;
	p22 = p2;
	p2.show();
	cout << endl;
	cout << "=============Copy Constructor Test=============" << endl;
	Person p23 = p2;
	p23.show();
	cout << endl << endl;
	
	cout << "-------------Inheriting constructors-------------" << endl << endl;
	cout << "-----------------class Person------------------" << endl;
	Person p3("Kota","Miura","Jun",d1,a1),p4;
	p3.show();
	cout << endl;
	cout << "============Assignment operator Test============" << endl;
	p4 = p3;
	p4.show();
	cout << endl;
	cout << "=============Copy Constructor Test=============" << endl;
	Person p5 = p2;
	p5.show();
	cout << endl << endl;
	
	cout << "-----------------class Student-----------------" << endl;
	Student s1("Tobirama","Senju","Tobi","420","Computer Science",d1,a1),s2;
	s1.show();
	cout << endl;
	cout << "============Assignment operator Test============" << endl;
	s2 = s1;
	s2.show();
	cout << endl;
	cout << "=============Copy Constructor Test=============" << endl;
	Student s3 = s1;
	s3.show();
	cout << endl << endl;
	
	cout << "-----------------class Teacher-----------------" << endl;
	Teacher t1("Hashirama","Senju","Hashi","Linguistics","Bachelor",d1,a1),t2;
	t1.show();
	cout << endl;
	cout << "-----------------------------------------------" << endl << endl;
	cout << "============Assignment operator Test============" << endl;
	t2 = t1;
	t2.show();
	cout << endl;
	cout << "=============Copy Constructor Test=============" << endl;
	Teacher t3 = t1;
	t3.show();
	cout << endl << endl;

	cout << "######AS_7 : Multiple Interitance######" << endl << endl;
	cout << "------------class TeachingAssistant------------" << endl;
	TeachingAssistant ta1("Analysis","10000","Tobirama","Senju","Tobi","420","Computer Science","Linguistics","Master","Multitasking",d1,a1),ta2;
	ta1.show();
	cout << endl;cout << "============Assignment operator Test============" << endl;
	ta2 = ta1;
	ta2.show();
	cout << endl;
	cout << "=============Copy Constructor Test=============" << endl;
	TeachingAssistant ta3 = ta1;
	ta3.show();
	cout << endl << endl;

}

