/*
CHALLENGE
Modify the program you wrote for Problem 1 (Charge Account Validation) so it performs
a binary search to locate valid account numbers. Use the selection sort algorithm
to sort the array before the binary search is performed.

        5658845 4520125 7895122 8777541 8451277 1302850
        8080152 4562555 5552012 5050552 7825877 1250255
        1005231 6545231 3852085 7576651 7881200 4581002
*/

//CODE

#include<iostream>
using namespace std;

//function prototype
void selectionSort(int [], int);
int binarySearch(const int[], int, int);

int main()
{
    int arraySize = 18, searchValue, userInput;
    int  accountNumbers[arraySize] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850,
                                      8080152, 4562555, 5552012, 5050552, 7825877, 1250255,
                                      1005231, 6545231, 3852085, 7576651, 7881200, 4581002};

    //calling the selection function rearrange the account numbers
    selectionSort(accountNumbers, arraySize);

    //asking user to enter a charge account number
    cout <<"Enter a charge account number: ";
    cin >> userInput;

    //calling the binary search function
    searchValue = binarySearch(accountNumbers, userInput, arraySize);

    //Displaying message to user baased on search value results
    if (searchValue == -1)
        cout<<"Sorry! the charge account number is not valid.";
    else
        cout<<"The charge account number is valid.";
    return 0;
}

//The selection sort function:
void selectionSort(int array[], int size)
{
    int beginScan, minIndex, minValue;

    for (beginScan=0; beginScan<size-1; beginScan++)
    {
        minIndex = beginScan;
        minValue = array[beginScan];

        for (int index=beginScan+1; index < size; index++)
        {
            if (array[index] < minValue)
            {
                minValue = array[index];
                minIndex = index;
            }
        }
        //swap any minimun value the inner loop encounntered
        array[minIndex] = array[beginScan];
        array[beginScan] = minValue;
    }
}

//The binary search function
int binarySearch(const int array[], int userInput, int size)
{
    int firstIndex=0, lastIndex=size-1, index=0, middleIndex;

    while (firstIndex <= lastIndex)
    {
        middleIndex = (firstIndex + lastIndex)/2;

        if (array[middleIndex] == userInput)
            return array[middleIndex];

        else if (array[middleIndex] > userInput)
            lastIndex = middleIndex - 1;

        else 
            firstIndex = middleIndex + 1;

    }
    //if no search matches user input then:
    return -1;
}
