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

void merge(int arr[], int lhsStart, int lhsEnd, int rhsEnd);
// Merge two halves of an array into one array.

void mergeSort(int arr[], int start, int end);
// Sorts an array in place in increasing order.

void printArray(int arr[], int size);
// Print each element in an array.

int main() {
    int size = 10;
    int arr[size] = {1, 23, 3, 530, 5, 392, 7, 9, -100, 38};
    mergeSort(arr, 0, size - 1);
    printArray(arr, size);
    return 0;
}

void merge(int arr[], int lhsStart, int lhsEnd, int rhsEnd)
{
    int *tmp;
    int size = rhsEnd - lhsStart + 1;
    int rhsStart = lhsEnd + 1;
    int lhsIndex = lhsStart;
    int rhsIndex = rhsStart;
    int tmpIndex = 0;

    tmp = new int[size];

    while(lhsIndex <= lhsEnd && rhsIndex <= rhsEnd) {
        if (arr[lhsIndex] < arr[rhsIndex]) {
            tmp[tmpIndex] = arr[lhsIndex];
            lhsIndex++;
            tmpIndex++;
        }
        else {
            // arr[lhsIndex] > arr[rhsIndex]
            tmp[tmpIndex] = arr[rhsIndex];
            rhsIndex++;
            tmpIndex++;
        }
    }

    // In case there's still a tail on left hand side
    while (lhsIndex <= lhsEnd) {
        tmp[tmpIndex] = arr[lhsIndex];
        lhsIndex++;
        tmpIndex++;
    }

    // In case there's still a tail on right hand side
    while (rhsIndex <= rhsEnd) {
        tmp[tmpIndex] = arr[rhsIndex];
        rhsIndex++;
        tmpIndex++;
    }

    // copy temporary "merged" array into original array
    for (int i = lhsStart, tmpIndex = 0; tmpIndex < size; i++, tmpIndex++) {
        arr[i] = tmp[tmpIndex];
    }

    delete [] tmp;

    return;
}

// running time: n*log(n)
void mergeSort(int arr[], int start, int end)
{
    int mid;

    if (start == end)
        return;
    else {
        mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << endl;
}
