#include <iostream>

using namespace std;

bool isEven(int n);

bool allEven(int arr[], int size);

int main() {
    int size = 5;
    int arr1[size] = {1, 3, 5, 7, 9};
    cout << allEven(arr1, size) << endl;  // 0

    int arr2[size] = {0, 2, 4, 6, 8};
    cout << allEven(arr2, size) << endl;  // 1

    int arr3[size] = {1, 2, 4, 6, 8};
    cout << allEven(arr3, size) << endl;  // 0

    return 0;
}

bool isEven(int n)
{
    return n % 2 == 0;
}

bool allEven(int arr[], int size)
{
    if (size == 1) {
        return isEven(arr[0]);
    }
    else {
        if (allEven(arr, size - 1)) {
            return isEven(arr[size - 1]);
        }
        else {
            return false;
        }
    }
}
