#include <iostream>
using namespace std;

void mergeArrays(int array1[], int array2[], int array3[],
                  int size1,int size2 );

int main()
{
    int array1[] = {1, 3, 5, 7};
    int size1 = sizeof(array1) / sizeof(array1[0]);

    int array2[] = {2,4,6,8};
    int size2 = sizeof(array2) / sizeof(array2[0]);

    int array3[size1 + size2];

    mergeArrays(array1, array2, array3, size1, size2);

    cout <<"Array after mergin: ";
    for (int index = 0; index < (size1+size2); index++)
        cout <<array3[index]<<" ";
    cout <<endl;


    return 0;
}

void mergeArrays(int array1[], int array2[], int array3[],
                  int size1,int size2)
{
    int index1 = 0, index2 = 0, index3 = 0;

    //Traversing both arrays to rearrange it in ascending order
    while (index1 < size1 && index2 < size2)
    {
        if (array1[index1] < array2[index2])
            array3[index3++] = array1[index1++];
        else
            array3[index3++] = array2[index2++];
    }

    //Storing remaining elements of first array
    while (index1 < size1)
        array3[index3++] = array1[index1++];
    
    //storing remaining elements of second array
    while (index2 < size2)
        array3[index3++] = array2[index2++];
}