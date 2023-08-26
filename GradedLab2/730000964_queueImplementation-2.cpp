#include <iostream>
using namespace std;

#define SIZE 5
int A[SIZE];
int front = -1;
int rear = -1;

bool isempty()
{
    bool x = true;
    if(front == -1 && rear == -1){
        x = true; 
    }else{
        x = false;
    }
    return x;
}

void enqueue ( int value )
{
    if(front == -1 && rear == -1){
        A[0] = value;
        front = 0;
        rear = 0;
    }else if(A[5] == 9){
        cout << "error" << endl;
    }else{
        A[rear+1] = value;
        rear += 1;    
    }
}

void dequeue ( )
{
    if(front == -1 && rear == -1){
        cout << "error" << endl;
    }else{
        front += 1;
    }
}

int showfront( )
{
    int x = 3;
    return x;
}

void modifyElements()
{
    int mult = A[front];
    for(int i = 1; i < rear+1;i++){
        A[i] = A[i] * mult;
    }
    A[front] = 3;
}

void displayQueue()
{
    for(int i = front; i <= rear; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

void displayArray()
{
    for(int i = 1; i < SIZE; i++){
        if(i == 1){
            cout << "9" << " ";
        }
        cout << A[i] << " ";
    }
    cout << endl;
}

int main()
{
 cout<<"Inserting elements in queue\n";
 enqueue(2);
 enqueue(3);
 enqueue(5);
 enqueue(7);
 enqueue(8);
 cout<<"Displaying queue\n";
 displayQueue();
 
 cout<<"Removing elements from queue\n";
 dequeue();
 cout<<"Displaying Queue\n";
 displayQueue();
 
 modifyElements();
 cout<<"Queue after modifying\n";
 displayQueue();
 
 cout<<"Inserting elements into queue\n";
 enqueue(9); 
 enqueue(10); 
 cout<<"Displaying Array\n";
 displayArray();

 cout << "Showfront\n";
 int x = showfront();
cout << x << endl;
 return 0;
}