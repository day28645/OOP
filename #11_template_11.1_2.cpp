#include <iostream>
#include <cstdlib>
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

template <class T>
class Array {
private:
   	T array[5];

public:
    Array() {
        for (int i = 0; i < 5; i++) 
            array[i] = (T)rand() / 1000;
    }

    ~Array() {
        cout << "Array Destructor Called\n";
    }

    T operator[](int index) {
        return array[index];
    }

    T findMax() {
    	T max = array[0];
        for (int i = 0; i < 5; i++) {
            if (array[i] > max) {
                max = array[i];
            }
        }
    return max;
    }

    T findMin() {
    	T min = array[0];
        for (int i = 0; i < 5; i++) {
            if (array[i] < min) {
                min = array[i];
            }
        }
    return min;
    }
};
    
int main()
{
	cout << "Assignment 11 : Template(11.1)" << endl << endl;
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
	
	cout << "******************************************************" << endl << endl;

	cout << "Assignment 11 : Template(11.2)" << endl << endl;

    Array<int> myArray;
    for (int i = 0; i < 5; i++) {
        cout << myArray[i] << " ";
    }

    cout << endl << endl;
    cout << "Max = " << myArray.findMax() << endl;
    cout << "Min = " << myArray.findMin() << endl;

    cout << "\n-----------------------------------------\n";

    Array<double> myArray2;
    for (int i = 0; i < 5; i++) {
        cout << myArray2[i] << " ";
    }

    cout << endl << endl;
    cout << "Max = " << myArray2.findMax() << endl;
    cout << "Min = " << myArray2.findMin() << endl;
	
	return 0;
}
