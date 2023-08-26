#include <iostream>
#include <vector>
using namespace std;

int main(){
    //A. Initialize a vector of size 8
    vector<int> vector_1{100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000};

    //B. Pushback and Print
    vector_1.push_back(8000);
    vector_1.push_back(9000);
    vector_1.push_back(7000);

    cout << "b:" << endl;
    for(int i = 0; i < 11; i++){
        cout << vector_1[i] << endl; 
    }

    //C. Use pop_back
    vector_1.pop_back();
    vector_1.pop_back();
    vector_1.pop_back();
    vector_1.pop_back();
    vector_1.pop_back();

    cout << "c:" << endl;
    for(int i = 0; i < 6; i++){
        cout << vector_1[i] << endl; 
    }

    //D. Size
    cout << "d:" << endl;
    cout << vector_1.size() << endl;

    //E. Insert
    vector_1.insert(vector_1.begin(), 89748);
    cout << "e:" << endl;
    for(int i = 0; i < 7; i++){
        cout << vector_1[i] << endl;
    }

    //F. Emplace
    vector_1.emplace(vector_1.begin(), 50000);
    cout << "f:" << endl;
    for(int i = 0; i < 8; i++){
        cout << vector_1[i] << endl;
    }

    //G. Emplace_back and Print
    vector_1.emplace_back(78);

    cout << "g:" << endl;
    for(int i = 0; i < 9; i++){
        cout << vector_1[i] << endl;
    }

    //H. Insert, Pop_back, and Print
    vector_1.insert(vector_1.begin() + 1, 20);
    vector_1.insert(vector_1.begin() + 3, 20);
    vector_1.insert(vector_1.begin() + 6, 20);
    vector_1.pop_back();

    cout << "h:" << endl;
    for(int i = 0; i < 11; i++){
        cout << vector_1[i] << endl; 
    }
}