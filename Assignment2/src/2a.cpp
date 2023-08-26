//Insertion Sort
#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(int* pointer){
    int j = 0;
    int temp = 0;
    for(int i = 0; i < 300; i++){
        temp = pointer[i];
        j = i-1;
 
        while (j >= 0 && pointer[j] > temp){
            pointer[j + 1] = pointer[j];
            j -= 1;
        }

        pointer[j + 1] = temp;
    }
}

//Pointer 
int main(){
    //Initialize Pointer
    int *pointer = (int *) malloc(300*sizeof(int));

    //Initialize list
    int even_index = 0;
    for(int i = 150; i < 450; i += 2){
        pointer[even_index] = i;
        even_index++;
    }

    int odd_index = 150;
    for(int i = 449; i > 149; i -= 2){
        pointer[odd_index] = i;
        odd_index++;
    }

    //Call Sort
    insertion_sort(pointer);

    //Print
    for(int i = 0; i < 300; i++){
        if(i < 299){
            cout << pointer[i] << " " ;
        }else{
            cout << pointer[i] << endl;
        }
    }

    free(pointer);
}