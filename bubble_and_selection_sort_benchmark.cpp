/*
CHALLENGE
Write a program that uses two identical arrays of at least 20 integers. It should call
a function that uses the bubble sort algorithm to sort one of the arrays in ascending
order. The function should keep a count of the number of exchanges it makes. The
program then should call a function that uses the selection sort algorithm to sort the
other array. It should also keep count of the number of exchanges it makes. Display
these values on the screen.
*/

//CODE

#include <iostream>
using namespace std;

//Function Prototypes
int bubbleSort(int [], int);
int selectionSort(int [], int);
void showArray(const int [], int);

int main()
 {
    int arraySize = 21;
    //initializing arrays with values
    int bubbleSortIntegers[arraySize] = {5,8,4,9,15,12,1,7,10,3,19,20,23,21,32,41,25,2,6,14,30};
    int selectionSortIntegers[arraySize] = {5,8,4,9,15,12,1,7,10,3,19,20,23,21,32,41,25,2,6,14,30};

    //diplay the array before sorting
    cout<<"\t\tBUBBLE SORT"<<endl;
    cout<<"\t\t------------"<<endl;
    cout<<"Array Values before bubble sort: ";
    showArray(bubbleSortIntegers, arraySize);
    
    //calling bubble sort function
    int countBubblesort = bubbleSort(bubbleSortIntegers, arraySize);
    cout<<"The bubble sort algorithm made "<<countBubblesort<<" exchanges"<<endl;

    //displaying the array values after bubble sort
    cout<<"Array values after bubble sort: ";
    showArray(bubbleSortIntegers, arraySize);
    cout<<endl;

    cout<<"\t\tSELECTION SORT"<<endl;
    cout<<"\t\t---------------"<<endl;
    //displaying the array values before selection sort
    cout<<"Array values before Selection sort: ";
    showArray(selectionSortIntegers, arraySize);

    //calling selection sort function.
    int countSelectionsort = selectionSort(selectionSortIntegers, arraySize);
    cout<<"The selection sort algorithm made "<<countSelectionsort<<" exchanges"<<endl;
    
    //displaying array values after selection sort
    cout<<"Array values after selection sort: ";
    showArray(selectionSortIntegers, arraySize);
    return 0;
}

int bubbleSort(int array[], int size)
{
    bool swap;
    int temp;
    int index = 0, countSwap=0;
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
                countSwap++;
            }
        }
        if (swap==false)
            break;
        index++;
    }
    return countSwap;
}

int selectionSort(int array[], int size)
{
    int startScan, minIndex, minValue, countSwap=0;

    for (startScan=0; startScan < size-1; startScan++)
    {
        minIndex= startScan;
        minValue= array[startScan];

        for(int index=startScan+1; index < size; index++)
        {
            if(array[index] < minValue)
            {
                minValue = array[index];
                minIndex = index;
            }
        }
        //Swap only takes place if minvalue was updated in the inner loop.
        if (minValue != array[startScan])
        {
            array[minIndex] = array[startScan];
            array[startScan] = minValue;
            countSwap++;
        }    
    }
    return countSwap;
} 

void showArray(const int array[], int size)
{
    for (int count = 0; count < size; count++)
        cout << array[count] <<" ";
    cout<<endl;
}


