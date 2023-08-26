//Bubble Sort
#include <iostream>
#include <vector>
using namespace std;

vector<int> sort(vector<int> vect){
    int temp = 0;
    bool sorted = false;
      while(sorted == false){
        sorted = true;
        for(int i = 0; i < 299; i++) {
            if (vect[i] < vect[i+1]){
                temp = vect[i];
                vect[i] = vect[i+1];
                vect[i+1] = temp;
                sorted = false;
            }
        }
    }
    return vect;
}

int main(){
    //Initializing
    vector<int> vect;
    vector<int> print_vect;

    //Populating Vector
    for(int i = 150; i < 450; i += 2){
        vect.push_back(i);
    }

    for(int i = 449; i > 149; i -= 2){
        vect.push_back(i);
    }

    //Call sort
    print_vect = sort(vect);
    //print_vect = vect;

    //Print
    for(int i = 0; i < 300; i++){
        if(i < 299){
            cout << print_vect[i] << " ";
        }else{
            cout << print_vect[i] << endl;
        }
    }
}