#include <iostream>
using namespace std;

#define SIZE 5
int A[SIZE];
int front = -1;
int rear = -1;

//Hint : Update Front and Rear 

//function to check if queue is empty
bool isempty()
{
    if(front == -1 && rear == -1){
        return false;
    }else{
        return true;
    }
}


//function to insert element in queue
void enqueue (int value)
{
    if(front == -1 && rear == -1){
        A[0] = value;
        front = 0;
        rear = 0;
    }else{
        A[rear+1] = value;
        rear += 1;
    }
}


//function to remove element from queue
void dequeue ( )
{
    if(front == -1 && rear == -1){
        cout << "error" << endl;
    }else{
        rear -= 1;
    }
}


//function to display element at front
void showfront()
{
    cout << "front " << A[0] << endl;
}


//function to display elements of the queue
void displayQueue()
{
    for(int i = 0; i < rear; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

int main()
{
 cout<<"Inserting elements in queue\n";
 enqueue(2);
 displayQueue();
 enqueue(3);
 displayQueue();
 enqueue(5);
 displayQueue();
 enqueue(7);
 displayQueue();
 enqueue(8);

 displayQueue();
 enqueue(9);

 showfront();

 cout<<"Removing elements from queue\n";
 dequeue();
 displayQueue();
 dequeue();
 displayQueue();
 dequeue();
 displayQueue();
 dequeue();
 displayQueue();
 dequeue();

 return 0;
}