#include <iostream>

using namespace std;

//CLASS
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
        void append_mid(int a);
        void remove_mid();
        void remove_first();
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

//Append Mid
void CubeList::append_mid(int a){
    node* new_node = new node(&head, head.next, a);

    node* node1 = &head;
    node* node2 = &head;

    

    while(node1->next != &tail && node1->next->next != &tail){
        node2 = node2->next;
        node1 = node1->next->next;
    }

    new_node->next = node2->next;
    node2->next->prev = new_node;
    new_node->prev = node2;
    node2->next = new_node;
}

//Remove Mid
void CubeList::remove_mid(){
    node* node1 = &head;
    node* node2 = &head;

    while(node1->next != &tail && node1->next->next != &tail){
        node2 = node2->next;
        node1 = node1->next->next;
    }

    //node2 = node2->prev; 

    node2->prev->next = node2->next;
    node2->next->prev = node2->prev;

    delete node2;
}

//Remove first
void CubeList::remove_first(){
    node* node1 = head.next->next;

    node1->next->prev = node1->prev;
    node1->prev->next = node1->next;

    delete node1;  
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

//Struct
//trying to access memory that you have not allocated


//Node Class
struct node1{
    public:
        node1();
        node1(node1* n, node1* p, int d);
        int data;
        node1* next;
        node1* prev;
        
    private:
};

//node1 Default
node1::node1(){
    next = NULL;
    prev = NULL;
}

//node1 Paramatrized Constructor
node1::node1(node1* p, node1* n, int d){
    next = n;
    prev = p;
    data = d;
}

//cube_list class
struct cube_list{
    public:
        cube_list();
        ~cube_list();
        void append_end(int a);
        void append_front(int a);
        void append_mid(int a);
        void remove_mid();
        void remove_first();
        void print();
        
    private:
        node1 tail;
        node1 head;

};

//cube_list Default
cube_list::cube_list(){
    head = node1(NULL, &tail, 0);
    tail = node1(&head, NULL, 0);
}

cube_list::~cube_list(){
    node1* new_node1 = head.next; 
    
    while(new_node1 != &tail){
        new_node1 = new_node1->next;
        delete new_node1->prev;
    }
}

//Append End
void cube_list::append_end(int a){
    node1* new_node = new node1(tail.prev, &tail, a);
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
void cube_list::append_front(int a){
    node1* new_node = new node1(&head, head.next, a);

    new_node->prev->next = new_node;
    head.next = new_node;
    new_node->next->prev = new_node;
}

//Append Mid
void cube_list::append_mid(int a){
    node1* new_node = new node1(&head, head.next, a);

    node1* node4 = &head;
    node1* node5 = &head;

    while(node4->next != &tail && node4->next->next != &tail){
        node5 = node5->next;
        node4 = node4->next->next;
    }

    new_node->next = node5->next;
    node5->next->prev = new_node;
    new_node->prev = node5;
    node5->next = new_node;
}

//Remove Mid
void cube_list::remove_mid(){
    node1* node4 = &head;
    node1* node5 = &head;

    while(node4->next != &tail && node4->next->next != &tail){
        node5 = node5->next;
        node4 = node4->next->next;
    }

    node5->prev->next = node5->next;
    node5->next->prev = node5->prev;

    delete node5;
}

//Remove first
void cube_list::remove_first(){
    node1* node4 = head.next->next;

    node4->next->prev = node4->prev;
    node4->prev->next = node4->next;

    delete node4;  
}

//Print struct
void cube_list::print(){
    node1* new_node1 = head.next; 
    
    while(new_node1 != &tail){
        cout << new_node1->data << " ";
        new_node1 = new_node1->next;
    }
    cout << endl;
}





//Main
int main(){
    CubeList new_cube;
    cube_list new_cube1;

    //A
    new_cube.append_end(1); //1
    new_cube.append_end(8); //2
    new_cube.append_end(27); //3
    new_cube.append_end(64); //4
    new_cube.append_end(125); //5
    new_cube.append_end(216); //6
    new_cube.append_end(343); //7
    new_cube.append_end(512); //8
    new_cube.append_end(729); //9
    new_cube.append_end(1000); //10
    new_cube.append_end(1331); //11
    new_cube.append_end(1728); //12
    new_cube.append_end(2197); //13
    new_cube.append_end(2744); //14
    new_cube.append_end(3375); //15
    new_cube.append_end(4096); //16
    new_cube.append_end(4913); //17
    new_cube.append_end(5832); //18
    new_cube.append_end(6859); //19
    new_cube.append_end(8000); //20
    new_cube.append_end(9261); //21
    new_cube.append_end(10648); //22
    new_cube.append_end(12167); //23
    new_cube.append_end(13824); //24
    new_cube.append_end(15625); //25
    new_cube.append_end(117576); //26
    new_cube.append_end(19683); //27
    new_cube.append_end(21952); //28
    new_cube.append_end(24389); //29
    new_cube.append_end(27000); //30

    new_cube1.append_end(1); //1
    new_cube1.append_end(8); //2
    new_cube1.append_end(27); //3
    new_cube1.append_end(64); //4
    new_cube1.append_end(125); //5
    new_cube1.append_end(216); //6
    new_cube1.append_end(343); //7
    new_cube1.append_end(512); //8
    new_cube1.append_end(729); //9
    new_cube1.append_end(1000); //10
    new_cube1.append_end(1331); //11
    new_cube1.append_end(1728); //12
    new_cube1.append_end(2197); //13
    new_cube1.append_end(2744); //14
    new_cube1.append_end(3375); //15
    new_cube1.append_end(4096); //16
    new_cube1.append_end(4913); //17
    new_cube1.append_end(5832); //18
    new_cube1.append_end(6859); //19
    new_cube1.append_end(8000); //20
    new_cube1.append_end(9261); //21
    new_cube1.append_end(10648); //22
    new_cube1.append_end(12167); //23
    new_cube1.append_end(13824); //24
    new_cube1.append_end(15625); //25
    new_cube1.append_end(117576); //26
    new_cube1.append_end(19683); //27
    new_cube1.append_end(21952); //28
    new_cube1.append_end(24389); //29
    new_cube1.append_end(27000); //30

    //B - Add front
    new_cube.append_front(125000);
    cout << "b:" << endl;
    new_cube.print();

    new_cube1.append_front(125000);
    new_cube1.print();

    //C - Add end
    new_cube.append_end(216000);
    cout << "c:" << endl;
    new_cube.print();

    new_cube1.append_end(216000);
    new_cube1.print();

    //D - Add middle
    new_cube.append_mid(64000);
    cout << "d:" << endl;
    new_cube.print();

    new_cube1.append_mid(64000);
    new_cube1.print();

    //E - Remove mid
    new_cube.remove_mid();
    cout << "e:" << endl;
    new_cube.print();

    new_cube1.remove_mid();
    new_cube1.print();

    //F - Remove first
    new_cube.remove_first();
    cout << "f:" << endl;
    new_cube.print();

    new_cube1.remove_first();
    new_cube1.print();

}