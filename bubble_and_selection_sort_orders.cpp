/*
CHALLENGE:
Write a program that uses two identical arrays of just eight integers. It should display
the contents of the first array, then call a function to sort the array using an ascending
order bubble sort modified to print out the array contents after each pass of the sort.
Next, the program should display the contents of the second array, then call a function
to sort the array using an ascending order selection sort modified to print out the array
contents after each pass of the sort.
*/

//CODE

#include <iostream>
using namespace std;

//Function Prototypes
void bubbleSort(int [], int);
//void selectionSort(int [], int);
void showArray(const int [], int);

int main()
{
    int arraySize = 8;
    //initializing arrays with values
    int bubbleSortIntegers[arraySize] = {5,8,4,9,15,12,1,7};
    int selectionSortIntegers[arraySize] = {5,8,4,9,15,12,1,7};

    //diplay the array before bubble sort
    cout<<"\t\tBUBBLE SORT"<<endl;
    cout<<"\t\t------------"<<endl;
    cout<<"Array Values before bubble sort: ";
    showArray(bubbleSortIntegers, arraySize);

    //calling bubble sort function
    bubbleSort(bubbleSortIntegers, arraySize);

    /*//displaying the array values before selection sort
    cout<<"\t\tSELECTION SORT"<<endl;
    cout<<"\t\t---------------"<<endl;
    cout<<"Array values before Selection sort: ";
    showArray(selectionSortIntegers, arraySize);

    //calling selection sort function.
    selectionSort(selectionSortIntegers, arraySize);*/

    return 0;
}

//Bubble sort function
void bubbleSort(int array[], int size)
{
    bool swap;
    int temp;
    int index = 0;
    while (index < size)
    {
        swap = false;
        for (int count=0; count < (size - 1); count++)
        {
            if (array[count] > array[count + 1])
            {
                temp = array[count];
                array[count] = array[count + 1];
                array[count + 1] = temp;
                swap = true;

                //Display array values after each swap
                cout <<"Array values after pass #"<<count+1<<": ";
                showArray(array, size);
            } 
        }
        if (swap==false)
            break;
        index++;
    }
} 

//Show array function
void showArray(const int array[], int size)
{
    for (int index = 0; index < size; index++)
        cout << array[index] <<" ";
    cout<<endl;
}