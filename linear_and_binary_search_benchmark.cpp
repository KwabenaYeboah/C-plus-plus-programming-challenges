/*
CHALLENGE:
Write a program that has an array of at least 20 integers. It should call a function that
uses the linear search algorithm to locate one of the values. The function should keep
a count of the number of comparisons it makes until it finds the value. The program
then should call a function that uses the binary search algorithm to locate the same
value. It should also keep count of the number of comparisons it makes. Display these
values on the screen.
*/

//CODE

#include <iostream>
using namespace std;

//Function Prototype
int linearSearch(const int [], int, int);
int binarySearch(const int [], int, int);

int main(){
    int arraySize = 30;
    int integerNumbers[arraySize];

    //filling the arrays with integers
    for (int index=0; index<arraySize; index++)
        integerNumbers[index]=(index+10)*2;

    //display elements of array before search begins
    for (int i=0; i<arraySize; i++)
        cout<<integerNumbers[i]<<" ";
    cout<<endl;

    //search value using linear search algorithm
    int searchValue=52;
    int linearCount = linearSearch(integerNumbers, searchValue, arraySize );
    if (linearCount == -1)
        cout <<"Search value not found."<<endl;
    else
        cout<<"The linear search algorithm made "<<linearCount<<" comparisons"<<endl;

    // search value using binary search algorithm
    int binaryCount = binarySearch(integerNumbers,searchValue, arraySize);
    if (binaryCount == -1)
        cout <<"Search value not found."<<endl;
    else
        cout<<"The binary search algorithm made "<<binaryCount<<" comparisons"<<endl;

    return 0;
}

//Function to seearch for a value in a array
//The linear search functions accepts three arguments and return a value
//if there is match else it returns -1

int linearSearch( const int array[], int searchNumber, int size)
{
    int index=0, comparisonCount=0;
    while (index < size)
    {
        comparisonCount++;
        if (array[index] == searchNumber)
            return comparisonCount;
        index++;
    }
    //if no search value was found, return -1
    return -1;
}

//The binary search function
int binarySearch(const int array[], int searchNumber, int size)
{
    int firstIndex=0, lastIndex=size-1, index=0, middleIndex, comparisonCount=0;

    while (firstIndex <= lastIndex)
    {
        comparisonCount++;
        middleIndex = (firstIndex + lastIndex)/2;
        if (array[middleIndex] == searchNumber)
            return comparisonCount;

        else if (array[middleIndex] > searchNumber)
            lastIndex = middleIndex - 1;

        else 
            firstIndex = middleIndex + 1;

    }
    //if no search matches user input then
    return -1;
}
