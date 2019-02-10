#include <iostream>
using namespace std;

// A function to swap two elements 
void swap(int *a, int *b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition (int arr[], int low, int high) 
{
	//initialising pivot
    int pivot = arr[high];
    int i = (low - 1);  // Index of smaller element 
	for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or equal to pivot 
        if (arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
}
//function to perform quicksort using recursion
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
     	int pi = partition(arr, low, high); 
  
        // sort elements before partition
        quickSort(arr, low, pi - 1); 
        // sort elements after partition
        quickSort(arr, pi + 1, high); 
    } 
}
//function to print the array
void print(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        cout<<arr[i]<<"  ";
    cout<<endl;
} 
//initiating main function
int main()
{
	//variable declaration
	int arr[50],size;
	//asking user to enter size of array and elements of the array
	cout<<"Please enter the size of array: "<<endl;
	cin>>size; 
	cout<<"Please enter the array elements: "<<endl;
	for(int i=0;i<size;i++)
		cin>>arr[i];
	
	//callinfg function to sort the array
	quickSort(arr,0,size-1);
	
	//display the sorted array
	cout<<"The sorted array is "<<endl;
	print(arr,size);
	
	return 0;
}
