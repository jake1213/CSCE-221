//D. Adding a ninth element
    /*
        Commented in order to prevent errors when compiling
        - When attempting to add a ninth element you will get an out of bounds error

        Ex. 
        Array[8] = 612341;

        This will give an out of bounds error as it is attempting to access a part of the array that does not exist (out of bounds)

    */

#include <iostream>
using namespace std;

int main(){
    //A. Initializing Array
    int array_1[8] = {63556, 9887, 54321, 56789, 87906, 73654, 842368, 8672364};

    //B. Reversing the Array
    cout << "b:" << endl; 
    for(int i = 0; i < 8; i++){
        cout << array_1[7-i] << endl;
    } 

    //C. Printing memory addresses
    cout << "c:" << endl;
    for(int i = 0; i < 8; i++){
        cout << &array_1[7-i] << endl;
    }

    //D. Adding a ninth element
    /*
        Commented in order to prevent errors when compiling
        - When attempting to add a ninth element you will get an out of bounds error

        Ex. 
        Array[8] = 612341;

        This will give an out of bounds error as it is attempting to access a part of the array that does not exist (out of bounds)

    */
}