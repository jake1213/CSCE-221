#include <iostream>

using namespace std;

int main() {
    //A. Create pointer
    int *pointer = (int *) malloc(8*sizeof(int));

    pointer[0] = 65536;
    pointer[1] = 78890;
    pointer[2] = 12345;
    pointer[3] = 98765;
    pointer[4] = 87906;
    pointer[5] = 45637;
    pointer[6] = 863248;
    pointer[7] = 4632768;

    //B. Print Integers
    cout << "b:" << endl;
    for(int i = 0; i < 8; i++){
        cout << pointer[i] << endl;
    }

    //C. Print Addresses 
    cout << "c:" << endl;
    for(int i = 0; i < 8; i++){
        cout << &pointer[i] << endl;
    }

    //D. Reallocate
    pointer = (int *) realloc(pointer, 12*sizeof(int));

    pointer[8] = 768;
    pointer[9] = 765;
    pointer[10] = 92034;
    pointer[11] = 65789;

    

    cout << "d:" << endl;
    for(int i = 0; i < 12; i++){
        cout << pointer[i] << endl;
    }
    free(pointer);
}