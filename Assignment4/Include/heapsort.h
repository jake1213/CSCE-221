#include <string>
#include <vector>
//#include <iostream>

using namespace std;

//Heap class
class Heap{
    private:
        vector<vector<int>> IndexList;
        
    public:
        Heap(); //Complete
        vector<int> min(); //Complete
        int size(); //Complete
        int leftChild(int index); //Complete
        int rightChild(int index); //Complete
        int parent(int index); //Complete
        bool isEmpty(); //Complete
        void insert(int val, int dest); //Complete
        void upHeap(int index); //Complete
        void downHeap(int index); //Complete
        void removeMin(); //Complete
        void print(); //Complete
};

//Default constructor
Heap::Heap(){
    IndexList = {};
}

//Return size of the heap at any given time
int Heap::size(){
    return IndexList.size();
}

//Return minimum element (root)
vector<int> Heap::min(){
    return {IndexList.at(0).at(0),IndexList.at(0).at(1)};
}

//Return the index of a given nodes left child
int Heap::leftChild(int i){
    return (i * 2) + 1;
}

//Return the index of a given nodes right child
int Heap::rightChild(int i){
    return (i * 2) + 2;
}

//Return the index of a given nodes parent
int Heap::parent(int i){
    return (i - 1)/2;
}

//Return true if empty
bool Heap::isEmpty(){
    //Call size
    if(size() == 0){
        return true;
    }

    return false;
}

//Downheap fixes heap when removing minimum element
void Heap::downHeap(int i){
    //Base case (make sure the heap does attempt to access out of bounds)
    if(leftChild(i) >= size() || rightChild(i) >= size()){
       return;
    }

    //Check left child 
    if(IndexList.at(i) > IndexList.at(leftChild(i))){
        //Swap
        vector<int> temp = IndexList.at(i);
        IndexList.at(i) = IndexList.at(leftChild(i));
        IndexList.at(leftChild(i)) = temp;

        //Recursive downheap with new index
        downHeap(leftChild(i));
    }
    
    //check right child
    if(IndexList.at(i) > IndexList.at(rightChild(i))){
        //Swap
        vector<int> temp = IndexList.at(i);
        IndexList.at(i) = IndexList.at(rightChild(i));
        IndexList.at(rightChild(i)) = temp;

        //Recursive downheap with new index
        downHeap(rightChild(i));
    }

    return;   
}

//Remove minimum element
void Heap::removeMin(){
    //Swap root and last node
    vector<int> temp = IndexList.at(0);
    IndexList.at(0) = IndexList.at(size()-1);
    IndexList.at(size()-1) = temp;
    
    //Erase last node (This is the removing min part)
    IndexList.erase(IndexList.begin() + size() - 1);

    //Call downheap with root as index
    downHeap(0);
}

//Upheap fixes heap when inserting a new element
void Heap::upHeap(int i){
    //Base case
    if(i == 0){
        return;
    }
 
    //Check if parent is greater than child
    if(IndexList.at(parent(i)) > IndexList.at(i)){
        //Swap
        vector<int> temp = IndexList.at(i);
        IndexList.at(i) = IndexList.at(parent(i));
        IndexList.at(parent(i)) = temp;
    }

    //Recursive call to continue to move child to correct location
    upHeap(parent(i));
}

//Inserting a new element
void Heap::insert(int val, int dest){
    //Pushback to vector
    IndexList.push_back({val,dest});

    //Call upheap to fix any issues
    upHeap(IndexList.size()-1);
}

//Printing the heap
void Heap::print(){
    //Traverse and print
    for(unsigned int i = 0; i < IndexList.size(); i++){
        cout << IndexList.at(i).at(0) << "," << IndexList.at(i).at(1) << " ";
    }

    cout << endl;
}