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

void swap(int *a, int *b);
// Implement swap function with pointers for "fun".

void bubbleSort(int arr[], int size);
// Sort an array of a given size.

void printArray(int arr[], int size);
// Print each element in an array.

int main() {
    int size = 10;
    int arr[size] = {1, 23, 3, 530, 5, 392, 7, 9, -100, 38};
    bubbleSort(arr, size);
    printArray(arr, size);
    return 0;
}

void swap(int *a, int *b)
{
   int temp = *a;
   *a = *b;
   *b = temp;
}

// Quadratic running time: O(n^2)
void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << endl;
}
