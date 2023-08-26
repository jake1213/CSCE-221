#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main(){
	double initial = 1600.0;
	for(int i = 0; i <= 16; i++){
		initial += .0190529*(initial);
	}

	cout << initial << endl;
}

/*
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

// Complete the function to swap two elements
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


int partition(int arr[], int low, int high)
{
	int random = low + rand()%high;
	swap(&arr[high], &arr[random]);

    int pivot = arr[high]; 
    int i = (low - 1);

    for(int j = low; j < high; j++){
        if(arr[j] <= pivot){
            i++;  
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i + 1],&arr[high]);
    return (i + 1);
}


void quickSort(int arr[], int low, int high)
{
	int part = 0;
    if(low < high){
        part = partition(arr, low, high);
        quickSort(arr, low, part - 1);
        quickSort(arr, part + 1, high);

    }
}

*/
/* Function to print an array */
/*
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Driver Code
int main()
{
	srand(time(NULL));
	int size = rand() % 10 + 1;
	int arr[size];
	for( int i = 0; i < size; ++i ) {
    	arr[i] = rand() % 19 + (-9);	
	}

	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Input array\n";
    printArray(arr, n);
    
	quickSort(arr, 0, n - 1);
	
	cout << "Sorted array: \n";
	printArray(arr, n);
	return 0;
}
*/