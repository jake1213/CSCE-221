//Selection Sort
#include <iostream>
#include <vector>
using namespace std;

int find_max(vector<int> vect, int start){
    int max = 0;
    for(int i = start; i < 300; i++){
        if(vect.at(i) > max){
            max = vect.at(i);
        }
    }

    vect.erase(vect.begin() + 1, vect.begin()+2);   
    return max;
}

int main(){
    //Initializing
    vector<int> vect;

    //Populating Vector
    for(int i = 150; i < 450; i += 2){
        vect.push_back(i);
    }

    for(int i = 449; i > 149; i -= 2){
        vect.push_back(i);
    }

    for(int i = 0; i < 299; i++){
        int x = find_max(vect, i);
        vect.insert(vect.begin(), x);  

        //Remove largest value from middle of the list
        for(int i = 300; i > 0; i--){
            if(vect[i] == x){
                for(int j = i; j < 300; j++){
                    vect[j] = vect[j+1];
                }
            }
        } 
    }

    vect.insert(vect.begin(), 150);
    vect.erase(vect.begin()+299,vect.begin()+299);

    //Print
    for(int i = 299; i >= 0; i--){
        if(i > 0){
            cout << vect[i] << " ";
        }else{
            cout << vect[i] << endl;
        }
    }
}