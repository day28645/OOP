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
void setGift(char* g) {delete[] gift; gift = new char[10]; strcpy(gift,g);}

int getDay() {return day;}
int getMonth() {return month;}
int getYear() {return year;}
char* getGift() {return gift;}

void showBD() {cout << "Day = " << day << " / " << "Month = " << month << " / "  << "Year = " << year << " || " << "Gift :" << gift << endl;}
void show(void);

//ostream operator
void print(ostream& os) {
	os << "Date of Birth :" << day << "/" << month << "/" << year << endl;
	os << "Gift :" << gift << endl;
}
//istream operator
void input(istream& is) {
	cout << "Enter day :"; is >> day;
	cout << "Enter month :"; is >> month;
	cout << "Enter year :"; is >> year;
	cout << "Enter gift :"; delete[] gift; gift = new char[10]; is >> gift;
}
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
void setPhone(char* ph) {delete[] phone; phone = new char[10]; strcpy(phone,ph);}

char* getNum() {return num;}
char* getRoad() {return road;}
char* getDistrict() {return district;}
char* getProvince() {return province;}
char* getCode() {return code;}
char* getPhone() {return phone;}

void showLocation() {cout << num << " " << road << " " << district <<" " << province << " " << code << " || " << phone << endl;}
void show(void);

//ostream operator
void print(ostream& os) {
	os << "Address :" << num << " " << road << " " << district <<" " << province << " " << code << endl;
	os << "Phone :" << phone << endl;
}
//istream operator
void input(istream& is) {
	cout << "Enter address no :"; is >> num; 
	cout << "Enter road :"; is >> road;
	cout << "Enter district :"; is >> district;
	cout << "Enter province :"; is >> province;
	cout << "Enter code :"; is >> code;
	cout << "Enter phone :"; delete[] phone; phone = new char[10]; is >> phone;
}
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
void setNickname(char* n) {delete[] nickname; nickname = new char[10]; strcpy(nickname,n);}
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

//ostream operator
void print(ostream& os) {
	os << "Full Name :" << fname << " " << lname << endl;
	os << "Nickname :" << nickname << endl;
	os << "Date of Birth :" << date.getDay() << "/" << date.getMonth() << "/" << date.getYear() << endl;
	os << "Gift :" << date.getGift() << endl;
	os << "Address :" << address.getNum() << " " << address.getRoad() << " " << address.getDistrict() << " " << address.getProvince() << " " << address.getCode() << endl;
	os << "Phone :" << address.getPhone() << endl;
}
//istream operator
void input(istream& is) {
	int d,m,y; char g[10];
	char no[10],ro[10],dis[10],pro[10],co[10],ph[10];
	cout << "Enter first name :"; is >> fname; 
	cout << "Enter last name :"; is >> lname;
	cout << "Enter nickname :"; delete[] nickname; nickname = new char[10]; is >> nickname;
	cout << "Enter day :"; is >> d;
	cout << "Enter month :"; is >> m;
	cout << "Enter year :"; is >> y;
	cout << "Enter gift :"; is >> g;
	date.setBD(d,m,y,g);
	//date.input(is);
	cout << "Enter address no :"; is >> no; 
	cout << "Enter road :"; is >> ro;
	cout << "Enter district :"; is >> dis;
	cout << "Enter province :"; is >> pro;
	cout << "Enter code :"; is >> co;
	cout << "Enter phone :"; is >> ph;
	address.setLocation(no,ro,dis,pro,co,ph);
	//address.input(is);
}
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
void setMajor(char* m) {delete[] major; major = new char[10]; strcpy(major,m);}

char* getID() {return id;}
char* getMajor() {return major;}

void showStudent() {cout << id << " " << major << endl;}
void show(void);

//ostream operator
void printStudent(ostream& os) {
	Person::print(os);
	os << "ID :" << id << endl;
	os << "Major :" << major << endl;
}
//istream operator
void inputStudent(istream& is) {
	Person::input(is);
	cout << "Enter id :"; is >> id; 
	cout << "Enter major :"; delete[] major; major = new char[10]; is >> major;
}
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
			Teacher& operator=(const Teacher&t) {					//assignment operator 
			if(this==&t)
				return *this;
			Person::operator=(t);
			strcpy(course,t.course);
			delete[] degree;
			if(t.degree!=0)
				{degree = new char[strlen(t.degree)+1]; strcpy(degree,t.degree);}
			else
				degree = 0;
				return *this;
		}
		Teacher(const Teacher& t) {									//copy constructor
			cout << "copy constructor for class Teacher is called" << endl;
			Person::operator=(t);
			strcpy(course,t.course);
			if(t.degree!=0) {
				degree = new char[strlen(t.degree)+1]; strcpy(degree,t.degree);
			}else
				degree = 0;
		}
			
void setTeacher(char* c,char* de) {strcpy(course,c); delete[] degree; degree = new char[strlen(de)+1]; strcpy(degree,de);}
void setCourse(char* c) {strcpy(course,c);}
void setDegree(char* de) {delete[] degree; degree = new char[10]; strcpy(degree,de);}

char const* getCourse() const {return course;}
char* getDegree() const {return degree;}

void showTeacher() {cout << course << " " << degree << endl;}
void show(void);

//ostream operator
void printTeacher(ostream& os) {
	Person::print(os);
	os << "Course :" << course << endl;
	os << "Degree :" << degree << endl;
}
//istream operator
void inputTeacher(istream& is) {
	Person::input(is);
	cout << "Enter course :"; is >> course; 
	cout << "Enter degree :"; delete[] degree; degree = new char[10]; is >> degree;
}
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
		TeachingAssistant&operator=(const TeachingAssistant&t) {				//assignment operator
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
		TeachingAssistant(const TeachingAssistant& t)	{						//copy constructor
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
void setQualification(char* q) {delete[] qualification; qualification = new char[10]; strcpy(qualification,q);}

char* getSkill() {return skill;}
char* getPayment() {return payment;}
char* getQualification() {return qualification;}

void showTA() {cout << skill << " / " << payment << " || " << qualification;}
void show(void);

//ostream operator
void print(ostream& os) {
	Student::printStudent(os);
	os << "Course :" << getCourse() << endl;
	os << "Degree :" << getDegree() << endl;
	os << "Skill :" << skill << endl;
	os << "Payment :" << payment << endl;
	os << "Qualification :" << qualification << endl;
}
//istream operator
void input(istream& is) {
	char c[10],de[10];
	Student::inputStudent(is);
	cout << "Enter course :"; is >> c;
	cout << "Enter degree :"; is >> de;
	cout << "Enter skill :"; is >> skill; 
	cout << "Enter payment :"; is >> payment;
	cout << "Enter qualification :"; delete[] qualification; qualification = new char[10]; is >> qualification;
	Teacher::setTeacher(c,de);
}
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
ostream& operator<<(ostream& os, Date& d) {
	d.print(os);
	return os;
}
istream& operator>>(istream& is, Date& d) {
	d.input(is);
	return is;
}
ostream& operator<<(ostream& os, Address& a) {
	a.print(os);
	return os;
}
istream& operator>>(istream& is, Address& a) {
	a.input(is);
	return is;
}
ostream& operator<<(ostream& os, Person& p) {
	p.print(os);
	return os;
}
istream& operator>>(istream& is, Person& p) {
	p.input(is);
	return is;
}
ostream& operator<<(ostream& os, Student& s) {
	s.print(os);
	return os;
}
istream& operator>>(istream& is, Student& s) {
	s.input(is);
	return is;
}
ostream& operator<<(ostream& os, Teacher& t) {
	t.print(os);
	return os;
}
istream& operator>>(istream& is, Teacher& t) {
	t.input(is);
	return is;
}
ostream& operator<<(ostream& os, TeachingAssistant& ta) {
	ta.print(os);
	return os;
}
istream& operator>>(istream& is, TeachingAssistant& ta) {
	ta.input(is);
	return is;
}                     
int main()
{
	cout << "Assignment 9 : Other Member Functions" << endl << endl;
	cout << "-------------------class Date-------------------" << endl << endl;

	cout << "Obj d1_is >>" << endl;
	Date d1;
	cin >> d1;
	cout << endl;
	cout << "Obj d1_os <<" << endl;
	cout << d1 << endl;
	cout << "Obj d2 = Obj d1" << endl;
	Date d2 = d1;
	cout << endl;
	cout << "Obj d2_os <<" << endl;
	cout << d2;
	cout << endl;
	
	cout << "-----------------class Address-----------------" << endl << endl;
	cout << "Obj a1_is >>" << endl;
	Address a1;
	cin >> a1;
	cout << a1;
	cout << endl;
	cout << "Obj a1_os <<" << endl;
	cout << a1 << endl;
	cout << "Obj a2 = Obj d1" << endl;
	Address a2 = a1;
	cout << endl;
	cout << "Obj a2_os <<" << endl;
	cout << a2;
	cout << endl;
	
	cout << "-----------------class Person------------------" << endl << endl;
	cout << "Obj p1_is >>" << endl;
	Person p1;
	cin >> p1;
	cout << p1;
	cout << endl;
	cout << "Obj p1_os <<" << endl;
	cout << p1 << endl;
	cout << "Obj p2 = Obj p1" << endl;
	Person p2 = p1;
	cout << endl;
	cout << "Obj p2_os <<" << endl;
	cout << p2;
	cout << endl;
	
	cout << "-----------------class Student-----------------" << endl << endl;
	cout << "Obj s1_is >>" << endl;
	Student s1;
	cin >> s1;
	cout << s1;
	cout << endl;
	cout << "Obj s1_os <<" << endl;
	cout << s1 << endl;
	cout << "Obj s2 = Obj s1" << endl;
	Student s2 = s1;
	cout << endl;
	cout << "Obj s2_os <<" << endl;
	cout << s2;
	cout << endl;
	
	cout << "-----------------class Teacher-----------------" << endl << endl;
	cout << "Obj t1_is >>" << endl;
	Teacher t1;
	cin >> t1;
	cout << t1;
	cout << endl;
	cout << "Obj t1_os <<" << endl;
	cout << t1 << endl;
	cout << "Obj t2 = Obj t1" << endl;
	Teacher t2 = t1;
	cout << endl;
	cout << "Obj t2_os <<" << endl;
	cout << t2;
	cout << endl;
	
	cout << "------------class TeachingAssistant------------" << endl << endl;
	cout << "Obj ta1_is >>" << endl;
	TeachingAssistant ta1;
	cin >> ta1;
	cout << ta1;
	cout << endl;
	cout << "Obj ta1_os <<" << endl;
	cout << ta1 << endl;
	cout << "Obj ta2 = Obj ta1" << endl;
	TeachingAssistant ta2 = ta1;
	cout << endl;
	cout << "Obj ta2_os <<" << endl;
	cout << ta2;
	cout << endl;	
}

