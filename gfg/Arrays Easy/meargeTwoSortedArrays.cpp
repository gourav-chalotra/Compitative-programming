#include <iostream>
using namespace std;

void merge(int arr1[], int arr2[], int n, int m, int arr3[], int newSize)
{
    int i = 0, j = 0, k = 0;
    for (j; (j < m) && (i < n); j)
    {
        if (arr1[i] <= arr2[j])
        {
            arr3[k] = arr1[i];
            k++;
            i++;
        }
        else
        {
            arr3[k] = arr2[j];
            k++;
            j++;
        }
    }
    if(j < m)
    {
        while(j < m)
        {
            arr3[k] = arr2[j];
            j++;
            k++;
        }
    }
    if(i < n)
    {
         while(i < n)
        {
            arr3[k] = arr1[i];
            i++;
            k++;
        }
    } 
}
void show(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << " " << arr[i];
    }
}
int main()
{
    int arr1[] = {1, 3, 5, 7}, arr2[] = {0, 2, 6, 8, 9}, newSize;
    int sizeOfArr1 = sizeof(arr1) / sizeof(int);
    int sizeOfArr2 = sizeof(arr2) / sizeof(int);
    newSize = sizeOfArr1 + sizeOfArr2;

    int sortedArray[newSize];

    merge(arr1, arr2, sizeOfArr1, sizeOfArr2, sortedArray, newSize);

    show(sortedArray, newSize);
    return 0;
}