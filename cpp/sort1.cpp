#include <iostream>

using namespace std;

// sorting algorithms:
//  - selection sort
//  - insertion sort
//  - bubble    sort
//  - merge     sort
//  - quick     sort
//  - heap      sort
//  - ...

int findIndexOfMinimum(int arr[], int start, int end);
// Find index of minimum element in an array.

void swap(int *a, int *b);
// Implement swap function with pointers for "fun".

void selectionSort(int arr[], int size);
// Sorts an array in place in increasing order.

void printArray(int arr[], int size);
// Print each element in an array.

int main() {
    int size = 10;
    int arr[size] = {1, 23, 3, 530, 5, 392, 7, 9, -100, 38};
    selectionSort(arr, size);
    printArray(arr, size);
    return 0;
}

int findIndexOfMinimum(int arr[], int start, int end)
{
    int min = arr[start];
    int minIndex = start;

    for (int i = start + 1; i <= end; i++) {
        if (arr[i] < min) {
            minIndex = i;
            min = arr[i];
        }
    }

    return minIndex;
}

void swap(int *a, int *b)
{
   int temp = *a;
   *a = *b;
   *b = temp;
}

// Quadratic running time: O(n^2)
void selectionSort(int arr[], int size)
{
    int minIndex;

    for (int i = 0; i < size; i++) {
        minIndex = findIndexOfMinimum(arr, i, size - 1);
        swap(arr[i], arr[minIndex]);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << endl;
}
