#include <iostream>
using namespace std;


int pivot(int arr[], int start, int end){
    int piv = 0;
    int piv_index = 0;
    int temp = 0;

    piv = arr[end];
    piv_index = start;

    for(int i = start; i < end; i++){
        if(arr[i] < piv){
            temp = arr[i];
            arr[i] = arr[piv_index];
            arr[piv_index] = temp;
            piv_index++;   
        }
    }

    temp = arr[end];
    arr[end] = arr[piv_index];
    arr[piv_index] = temp;

    return piv_index;
}

void quick_sort(int arr[], int start, int end){
    int partition = 0;
    if(start < end){
        partition = pivot(arr, start, end);
        quick_sort(arr, start, partition - 1);
        quick_sort(arr, partition + 1, end);

    }
}

int main(){
    int array [9] = {0,2,4,1,7,9,10,3,9};

    quick_sort(array, 0, 8);

    for(int i = 0; i < 9; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}