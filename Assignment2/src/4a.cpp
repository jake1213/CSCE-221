//Insertion Sort
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
        void insertion_sort();
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

void swap(node2* a, node2* b){
    node2* temp = new node2(b->prev, b->next, b->data);

    b->next = a;
    b->prev = a->prev;
    a->prev->next = b;
    a->prev = b;
    a->next = temp->next;
    temp->next->prev = a;

    delete(temp);
}

//Append in list
void cubelist::insertion_sort(){
    node2* new_node1 = &head;
    node2* new_node2 = &head;

    int temp = 0;
    new_node1 = new_node1->next;
    while(new_node1->next != NULL){
        temp = new_node1->data;
        new_node2 = new_node1->prev;
 
        while(new_node2 != NULL && new_node2->data > temp){
            swap(new_node2, new_node2->next);

            new_node2 = new_node2->prev->prev;
        }

        new_node2->next->data = temp;
        new_node1 = new_node1->next;
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
    cubelist list1;
    
    //Initalize the list
    for(int i = 150; i < 450; i +=2){
        list1.append_end(i);
    }

    for(int i = 449; i > 149; i -=2){
        list1.append_end(i);
    }

    //Call sort
    list1.insertion_sort();

    list1.print();
}