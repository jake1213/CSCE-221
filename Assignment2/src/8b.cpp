//Binary search 279
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
        node2* middle(node2* start, node2* end);
        void search_linked(int val);
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

void insertion_sort(int* pointer){
    int j = 0;
    int temp = 0;
    for(int i = 0; i < 300; i++){
        temp = pointer[i];
        j = i-1;
 
        while (j >= 0 && pointer[j] > temp){
            pointer[j + 1] = pointer[j];
            j -= 1;
        }

        pointer[j + 1] = temp;
    }
}

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

node2* cubelist::middle(node2* start, node2* end){
    node2* current = start;
    node2* forward = start;
    
    while(forward->next != end && forward->next->next != end){
            current = current->next;
            forward = forward->next->next;
    }
    return current;
}

void cubelist::search_linked(int val){
    node2* new_node1 = &head;
    node2* new_node2 = &tail;

    while(new_node1 != new_node2){
        node2* mid = middle(new_node1, new_node2);

        if(mid->data == val){
            cout << &mid << endl;
            return;
        }else{
            if(mid->data > val){
                new_node2 = mid;
            }else{
                new_node1 = mid->next;
            }
        }
    }
}

void pointer_binary(int* point, int left1, int right1, int val1){
    int middle = (left1+right1)/2;
    if(point[middle] == val1){
        cout << &point[middle] << " " << middle << endl;
    }else if(point[middle] != val1 && middle == 1){
        cout << "279 Not found in Pointer array";
    }else{
        //cout << "3";
        if(val1 > point[middle]){
            left1 = middle;
            return pointer_binary(point, left1, right1, val1);
        }else{
            right1 = middle;
            return pointer_binary(point, left1, right1, val1);
        }
    }
}

void vector_binary(vector<int> vec, int left2, int right2, int val2){
    int middle = (left2+right2)/2;
    if(vec.at(middle) == val2){
        cout << &vec.at(middle) << " " << middle << endl;
    }else if(vec.at(middle) != val2 && middle == 1){
        cout << "279 Not found in Vector array";
    }else{
        //cout << "3";
        if(val2 > vec.at(middle)){
            left2 = middle;
            return vector_binary(vec, left2, right2, val2);
        }else{
            right2 = middle;
            return vector_binary(vec, left2, right2, val2);
        }
    }
}

//Pointer 
int main(){
    //Initialize Pointer
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

    //Call Sort
    insertion_sort(pointer);

    /*
    //Print
    for(int i = 0; i < 300; i++){
        if(i < 299){
            cout << pointer[i] << " " ;
        }else{
            cout << pointer[i] << endl;
        }
    }
    */

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

    /*
    //Print
    for(int i = 299; i >= 0; i--){
        if(i > 0){
            cout << vect[i] << " ";
        }else{
            cout << vect[i] << endl;
        }
    }
    */

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

    //list1.print();

    //Binary Search - Pointer
    int begin = 0;
    int end = 300;
    int val = 279;
    pointer_binary(pointer, begin, end, val);

    //Binary Search - Vector
    vector_binary(vect, begin, end, val);

    //Binary Search - Linked List
    list1.search_linked(val);

    free(pointer);
}