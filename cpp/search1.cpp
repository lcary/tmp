#include <iostream>

using namespace std;

int linearSearch(int arr[], int arrSize, int val);
// Returns index of a value if it exists in a sorted array;
// Else returns -1. Precondition: array must be sorted.

int main() {
    int arrSize = 10;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << linearSearch(arr, arrSize, 1) << endl;    // 0
    cout << linearSearch(arr, arrSize, 10) << endl;   // 9
    cout << linearSearch(arr, arrSize, 100) << endl;  // -1
    return 0;
}

// time = O(n)
int linearSearch(int arr[], int arrSize, int val)
{
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] == val)
            return i;
    }
    return -1;
}
