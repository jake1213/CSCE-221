/*
1. List of students: Cory Overgaard
2. External Sources: geeksforgeeks.org
3. Concerns: None
*/
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

//Node Class
class node{
    public:
        node();
        node(node* n, node* p, int d);
        int data;
        node* next;
        node* prev; 
    private:
};

//Node Default
node::node(){
    next = NULL;
    prev = NULL;
}

//Node Paramatrized Constructor
node::node(node* p, node* n, int d){
    next = n;
    prev = p;
    data = d;
}

//CubeList class
class CubeList{
    public:
        CubeList();
        ~CubeList();
        void append_end(int a);
        void append_front(int a);
        int remove_front();
        int remove_front2();
        void remove_end();
        void pop_stack();
        int front();
        int top();
        //int addition(int x, int y);
        //int subtraction(int x, int y);
        //int multiplication(int x, int y);
        //int division(int x, int y);
        void print();
        
    private:
        node tail;
        node head;

};

//CubeList Default
CubeList::CubeList(){
    head = node(NULL, &tail, 0);
    tail = node(&head, NULL, 0);
}

CubeList::~CubeList(){
    node* new_node1 = head.next; 
    
    while(new_node1 != &tail){
        new_node1 = new_node1->next;
        delete new_node1->prev;
    }
}

//Append End
void CubeList::append_end(int a){
    node* new_node = new node(tail.prev, &tail, a);
    //may need if
    if(head.next == &tail){
        head.next = new_node;
        tail.prev = new_node;
    }else{
        new_node->prev->next = new_node;
        tail.prev = new_node;
    }
}

//Append Front
void CubeList::append_front(int a){
    node* new_node = new node(&head, head.next, a);

    new_node->prev->next = new_node;
    head.next = new_node;
    new_node->next->prev = new_node;

}

//Remove Front (Pop operation for queue)
int CubeList::remove_front(){
    int temp = head.next->data;

    head.next->next->prev = &head;
    head.next = head.next->next;

    return temp;
}

int CubeList::remove_front2(){
    int temp = tail.prev->data;

    tail.prev->prev->next = &tail;
    tail.prev = tail.prev->prev;

    return temp;
}

//Returns front (Queue)
int CubeList::front(){
    return tail.prev->data;
}

//Returns top (Stack)
int CubeList::top(){
    return tail.prev->data;
}

void CubeList::pop_stack(){
    if(head.next == &tail){
        return;
    }else{
        tail.prev->prev->next = &tail;
        tail.prev = tail.prev->prev;
    }
}

//Addition
int addition(int x, int y){
   return x + y; 
}

//Subtraction
int subtraction(int x, int y){
    return x - y; 
}

//Multiplication
int multiplication(int x, int y){
    return x*y;  
}

//Division
int division(int x, int y){
    return x/y;   
}

//Print 
void CubeList::print(){
    node* new_node1 = head.next; 
    
    while(new_node1 != &tail){
        cout << new_node1->data << " ";
        new_node1 = new_node1->next;
    }
    cout << endl;
}

//Main
int main(){
    //Stack and Queue initialize
    CubeList Stack;
    CubeList Queue;

    //Vector initialize: Size = 15

    //<<<<YOUR INPUT BELOW>>>>
    vector<string> vect = {"0x601", "0x602", "0x604", "0x504", "0x502", "0x442", "0x603", "0x536", "0x605", "0x603", "0x503", "0x505", "0x335", "0x601", "0x516"};
     int array[7] = {0, 20, 276, 100, 203, 0};
    //<<<<YOUR INPUT ABOVE>>>>

    for(unsigned int i = 0; i < vect.size(); i++){
        string temp = vect.at(i);
        if(temp.size() != 5){
            cout << "Size of opperand inputs should be 5. Please fix and recompile." << endl;
            exit(EXIT_FAILURE);
        }else{
            temp = temp.substr(2, 4);
        }
        vect.at(i) = temp;
    }

    //Main Accessing: Building Stack and Queue and calling functions
    //char temp2 = '\0';
    //int temp3 = 0;
    for(unsigned int i = 0; i < vect.size(); i++){
        string temp1 = vect.at(i);

        if(temp1.substr(0,1) == "6"){ 
            Stack.append_end(array[stoi(temp1.substr(1,2))]);
        }else if(temp1.substr(0,1) == "5"){
            if(temp1.substr(1,2) == "0" || temp1.substr(1,2) == "6"){
                if(stoi(temp1.substr(2,2)) == Stack.top()){
                    Stack.pop_stack();
                    Queue.append_end(array[stoi(temp1.substr(2,2))]);
                    cout << "popS, pushQ" << endl;
                }else{
                    cout << "Stack Wrong opperand selected" << endl;
                    exit(EXIT_FAILURE);
                }
            }else{
                if(array[stoi(temp1.substr(1,2))] == Queue.front()){
                    Queue.pop_stack();
                    Queue.append_front(array[6]);
                }else{
                    if(array[stoi(temp1.substr(1,2))] == Stack.top()){
                        Queue.append_front(Stack.front());
                        Stack.pop_stack();
                        //array[stoi(temp1.substr(1,2))] = array[6];
                        cout << "popS, BypassQ" << endl;
                    }else{
                        Stack.append_end(stoi(temp1.substr(1,2)));
                        Stack.pop_stack();
                        Queue.append_front(array[stoi(temp1.substr(1,2))]);
                        array[stoi(temp1.substr(1,1))] = array[6];
                        cout << "pushS, popS, BypassQ" << endl;
                    }
                }
            }
        }else if(temp1.substr(0,1) == "4"){
            //Division
            int a = stoi(temp1.substr(1,1));
            int b = stoi(temp1.substr(2,3));
            if(array[a] == Queue.remove_front2() && array[b] == Queue.remove_front2()){
                //cout << "Division: " << division(array[a], array[b]) << endl;
                array[6] = division(array[a], array[b]);
            }else{
                cout << "Arithmatic Wrong operand requested4" << endl;
                exit(EXIT_FAILURE);
            }
        }else if(temp1.substr(0,1) == "3"){
            //Multiplication
            int a = stoi(temp1.substr(1,1));
            int b = stoi(temp1.substr(2,3));
            if(array[a] == Queue.remove_front2() && array[b] == Queue.remove_front2()){
                //cout << "Multiplication: " << multiplication(array[a], array[b]) << endl;
                array[6] = multiplication(array[a], array[b]);
            }else{
                cout << "Arithmatic Wrong operand requested3" << endl;
                exit(EXIT_FAILURE);
            }
        }else if(temp1.substr(0,1) == "2"){
            //Subtraction
            int a = stoi(temp1.substr(1,1));
            int b = stoi(temp1.substr(2,3));
            if(array[a] == Queue.remove_front2() && array[b] == Queue.remove_front2()){
                //cout << "Subtraction: " << subtraction(array[a], array[b]) << endl;
                array[6] = subtraction(array[a], array[b]);
            }else{
                cout << "Arithmatic Wrong operand requested2" << endl;
                exit(EXIT_FAILURE);
            }
        }else if(temp1.substr(0,1) == "1"){
            //Addition
            int a = stoi(temp1.substr(1,1));
            int b = stoi(temp1.substr(2,3));
            if(array[a] == Queue.remove_front2() && array[b] == Queue.remove_front2()){
                //cout << "Addition: " << addition(array[a], array[b]) << endl;
                array[6] = addition(array[a], array[b]);
            }else{
                cout << "Arithmatic Wrong operand requested1" << endl;
                exit(EXIT_FAILURE);
            }
        }
    }

    cout << "Operand" << 0 << " " << array[0] << " Operand" << 1 << " " << array[1] << " Operand" << 2 << " " << array[2] << " Operand" << 3 << " " << array[3] << " Operand" << 4 << " " << array[4] << " Operand" << 5 << " " << array[5] << " Operand" << 6 << " " << array[6] << endl;
}