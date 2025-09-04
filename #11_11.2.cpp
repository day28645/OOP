#include <iostream>
#include <cstdlib>

using namespace std;

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

int main() {
    cout << "Assignment 11 : Template" << endl << endl;

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
