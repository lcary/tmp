#include <iostream>

using namespace std;

int binarySearch(int arr[], int size, int val);
// Returns index of a value if it exists in a sorted array;
// Else returns -1

int main() {
    int arr1Size = 10;
    int arr1[arr1Size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << binarySearch(arr1, arr1Size, 1) << endl;       // 0
    cout << binarySearch(arr1, arr1Size, 10) << endl;      // 9
    cout << binarySearch(arr1, arr1Size, 100) << endl;     // -1

    int arr2Size = 1000000;
    int arr2[arr2Size];
    for (int i = 0; i < arr2Size; i++)
        arr2[i] = i + 1;

    cout << binarySearch(arr2, arr2Size, 112340) << endl;  // 112339

    return 0;
}

// time = O(log n)
int binarySearch(int arr[], int size, int val)
{
    int low, mid, high, index;
    bool found = false;

    low = 0;
    high = size - 1;
    index = -1;
    
    while(!found && (low <= high)) {
        mid = (low + high) / 2;

        if (arr[mid] == val) {
            index = mid;
            found = true;
        }
        else if (arr[mid] > val) {
            high = mid - 1;
        }
        else if (arr[mid] < val) {
            low = mid + 1;
        }
        else {
            throw;
        }
    }

    return index;
}
