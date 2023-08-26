#include <iostream>
#include <vector>
using namespace std;

//Node Class
class node2{
    public:
        node2();
        node2(node2* n, node2* p, int d);
        int data;
        node2* next;
        node2* prev;
        
    private:
};

//Node Default
node2::node2(){
    next = NULL;
    prev = NULL;
}

//Node Paramatrized Constructor
node2::node2(node2* p, node2* n, int d){
    next = n;
    prev = p;
    data = d;
}

//CubeList class
class cubelist{
    public:
        cubelist();
        ~cubelist();
        void append_end(int a);
        void print();

        
    private:
        node2 tail;
        node2 head;

};

//CubeList Default
cubelist::cubelist(){
    head = node2(NULL, &tail, 0);
    tail = node2(&head, NULL, 0);
}

//CubeList Destructor
cubelist::~cubelist(){
    node2* new_node1 = head.next; 
    
    while(new_node1 != &tail){
        new_node1 = new_node1->next;
        delete new_node1->prev;
    }
}

//Append End
void cubelist::append_end(int a){
    node2* new_node1 = new node2(tail.prev, &tail, a);

    if(head.next == &tail){
        head.next = new_node1;
        tail.prev = new_node1;
    }else{
        new_node1->prev->next = new_node1;
        tail.prev = new_node1;
    }
}

//Print 
void cubelist::print(){
    node2* new_node1 = head.next; 
    
    while(new_node1 != &tail){
        cout << new_node1->data << " ";
        new_node1 = new_node1->next;
    }
    cout << endl;
}

int main(){
    //Pointer 
    int *pointer = (int *) malloc(300*sizeof(int));

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

    for(int i = 0; i < 300; i++){
        if(i < 299){
            cout << pointer[i] << " ";
        }else{
            cout << pointer[i] << endl;
        }
    }

    //Vector
    vector<int> vect;

    for(int i = 150; i < 450; i += 2){
        vect.push_back(i);
    }

    for(int i = 449; i > 149; i -= 2){
        vect.push_back(i);
    }

    for(int i = 0; i < 300; i++){
        if(i < 299){
            cout << vect[i] << " ";
        }else{
            cout << vect[i] << endl;
        }
    }

    //Linked List
    cubelist list1;
    for(int i = 150; i < 450; i +=2){
        list1.append_end(i);
    }

    for(int i = 449; i > 149; i -=2){
        list1.append_end(i);
    }

    list1.print();

    free(pointer);
}