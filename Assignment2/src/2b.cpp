//Exchange Sort
#include <iostream>
#include <vector>
using namespace std;

void sort(int *pointer){
    for(int i = 0; i < 300; i++){
        for(int j = 1; j < 299; j++){
            if(pointer[i] > pointer[j-1] && pointer[i] < pointer[j]){
               int temp = pointer[j];
               pointer[j] = pointer[i];
               pointer[i] = temp;
            }
        }
    }
}

int main(){
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

    //Call sort
    sort(pointer);

    //Print
    for(int i = 0; i < 300; i++){
        if(i < 299){
            cout << pointer[i] << " ";
        }else{
            cout << pointer[i] << endl;
        }
    }

    //Free memory
    free(pointer);
}