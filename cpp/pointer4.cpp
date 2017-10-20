#include <iostream>

using namespace std;

void showArray(int* arr, int arrSize);

void resizeArray(int *&arr, int currentSize, int newSize);

int main() {
    int size = 10;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = i * 10;
    resizeArray(arr, 10, 12);
    arr[10] = 123345;
    arr[11] = 3498910;
    showArray(arr, 12);
    delete [] arr;
    return 0;
}

void resizeArray(int *&arr, int currentSize, int newSize)
{
    int *temp = new int[newSize];
    for (int i = 0; i < currentSize; i++)
        temp[i] = arr[i];
    delete [] arr;
    arr = temp;
}

void showArray(int* arr, int arrSize)
{
    cout << "Array of " << arrSize << " integers: ";
    for (int i = 0; i < arrSize; i++)
        cout << arr[i] << ' ';
    cout << endl;
}
