
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

//Testing 2a: Pointer Insertion Sort

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


//Testing 2b: Pointer Exchange Sort

void sort(int *pointer){
    for(int i = 0; i < 300; i++){
        for(int j = 1; j < 299; j++){
            if(pointer[i] > pointer[j-1] && pointer[i] < pointer[j]){
               int temp = pointer[j];
               pointer[j] = pointer[i];
               pointer[i] = temp;
            }
        }
    }
}


//Testing 3a: Vector Selection Sort
/*
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
*/

//Testing 3b: Vector Bubble Sort
/*
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
*/

//Testing 4a: Linked List Insertion Sort
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
        void sort();
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


//4b. Linked List Exchange sort
//Sort
void cubelist::sort(){
    node2* new_node1 = &head;
    node2* new_node2 = &head;

    while(new_node1->next != NULL){
        new_node2 = new_node1->next;
        while(new_node2->next != NULL){
            if(new_node2->data < new_node1->data){
                //swap(new_node2, new_node3);

                int temp = new_node1->data;
                new_node1->data = new_node2->data; 
                new_node2->data = temp;
            }
            new_node2 = new_node2->next;
        }
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

int main(int argc, char **argv){
        
    //<<<POINTER CODE TEST>>>
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
    struct timeval start, end;
    gettimeofday(&start, NULL);

    //2a: Call Sort
    insertion_sort(pointer);

    gettimeofday(&end, NULL);
    printf("%ld\n", ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)));

    struct timeval start1, end1;
    gettimeofday(&start1, NULL);

    //2b: Call Sort
    sort(pointer);

    gettimeofday(&end1, NULL);
    printf("%ld\n", ((end1.tv_sec * 1000000 + end1.tv_usec) - (start1.tv_sec * 1000000 + start1.tv_usec)));

    //Print
    for(int i = 0; i < 300; i++){
        if(i < 299){
            //cout << pointer[i] << " ";
        }else{
            //cout << pointer[i] << endl;
        }
    }

    //Free memory
    free(pointer);

    //<<<VECTOR TEST CODE>>>
    /*
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

    //3a: Call Sort
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

    //3b: Call sort
    print_vect = sort(vect);
    //print_vect = vect;

    //Print
    for(int i = 0; i < 300; i++){
        if(i < 299){
            //cout << print_vect[i] << " ";
        }else{
            //cout << print_vect[i] << endl;
        }
    }
    */


   //4a. Call Sort
   cubelist list1;
    
    //Initalize the list
    for(int i = 150; i < 450; i +=2){
        list1.append_end(i);
    }

    for(int i = 449; i > 149; i -=2){
        list1.append_end(i);
    }

    struct timeval start2, end2;
    gettimeofday(&start2, NULL);

    //Call sort (4a)
    list1.insertion_sort();

    gettimeofday(&end2, NULL);
    printf("%ld\n", ((end2.tv_sec * 1000000 + end2.tv_usec) - (start2.tv_sec * 1000000 + start2.tv_usec)));

    struct timeval start3, end3;
    gettimeofday(&start3, NULL);

    //Call Sort (4b)
    list1.sort();

    //list1.print();

    gettimeofday(&end3, NULL);
    printf("%ld\n", ((end3.tv_sec * 1000000 + end3.tv_usec) - (start3.tv_sec * 1000000 + start3.tv_usec)));

    return 0;
}
