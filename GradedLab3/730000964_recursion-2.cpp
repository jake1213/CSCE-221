#include <iostream>
using namespace std;
 
void towerOfHanoi(int n, int type, int src, int temp, int dest)
{   
    //Replace something with the base condition for this recursive function
    if (n == 0){
        return;
    }
    else{
    // Recursively call the function to move from src to temp using dest as the temporary rod
        towerOfHanoi(n-1, 0, src, dest, temp);
    // Print the move in the format :  "Move disk <n> of type <type> from rod <src> to rod <dest>"
        cout << "Move disk " << n << " of type " << temp <<  " from rod " << src << " to rod " << dest << endl;
    // Move from temp to dest using src as the temporary rod
        towerOfHanoi(n-1, 0, temp, src, dest);
    }
}

void modifiedTOH(int n){
    // YOUR CODE HERE: Type in the parameters that you have to pass to the function below. 
    // Refer to the Hint given in the PDF
    towerOfHanoi(n,0,0,3,1);
    cout << "-------------------"<<endl;
    towerOfHanoi(n,1,2,3,0);
    cout << "-------------------"<<endl;
    towerOfHanoi(n,0,1,3,2);
    cout << "-------------------"<<endl;
    
}

// Driver code
int main()
{   
    //Rods are numbered as 0,1,2,3 -> In class, we used A,B,C
    int n = 3; // Number of disks

    cout << "Part(a) Solution"<<endl;
    towerOfHanoi(n,0,0,1,2);

    cout << "Part(b) Solution"<<endl;
    modifiedTOH(n); 

    return 0;
}