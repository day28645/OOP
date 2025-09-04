#include <iostream>
using namespace std;

template <class T>
T findMax(T x,T y,T z) {
	T max = x;
	
	if(max < y)
		max = y;
	if(max < z)
		return z;
	else
		return max;	
}
int main()
{
	cout << "Assignment 11 : Template" << endl << endl;
	cout << "Max value is " << findMax(4.1,5.2,6.3) << endl;	
	cout << "Max value is " << findMax(9,8,7) << endl;	
	cout << "Max value is " << findMax(11,13,12) << endl;
	
	cout << "--------------------------------" << endl << endl;
	
	char ch1 = 'a', ch2 = 'b', ch3 = 'c';
	cout << int(ch1) << endl;
	cout << int(ch2) << endl;
	cout << int(ch3) << endl;
	cout << "Max value is "	<< int(findMax(ch1,ch2,ch3)) << endl << endl;
	
	char a = 65, b = 66, c = 67;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << "Max value is "	<< findMax(a,b,c) << endl << endl;
}
