/* this was an attempt to implement binary search from scratch
   in a plaintext file. worked on the first try. */
#include <iostream>

using namespace std;

int binarySearchIterative(int arr[], int target, int size);
// returns index of value in array if exists. else return -1.
// the array must be sorted before this function is called.

int main() {
    int arr[10] = {0, 14, 22, 39, 42, 53, 60, 71, 82, 99};
    cout << binarySearchIterative(arr, 10, 10) << endl; // prints -1
    cout << binarySearchIterative(arr, 53, 10) << endl; // prints 5
    cout << binarySearchIterative(arr, 82, 10) << endl; // prints 8
    return 0;
}

int binarySearchIterative(int arr[], int target, int size) {
    // this binary search algorithm iterates through values to find a target.
    // the first iteration divides the range of the array in half and
    // retrieves the value of the midpoint. if the midpoint is less than the
    // target value, then the highest value that the algorithm searches within
    // can be the index of the midpoint - 1. if the midpoint is greater than the
    // target value, then the lowest value that the algorithm searches within
    // can be the index of the midpoint + 1. continue until either the index
    // of the target is found or the lowest value that the algorithm searches
    // within is higher than the highest value.
    int low, mid, high, targetIndex;
    bool found;

    low = 0;
    high = size - 1;
    found = false;

    while (!found && low < high) {
        mid = (high + low) / 2;

        if (arr[mid] == target) {
            found = true;
            targetIndex = mid;
        }
        else if (arr[mid] > target) {
            high = mid - 1;
        }
        else { // arr[mid] < target
            low = mid + 1;
        }
    }

    if (found)
        return targetIndex;
    else
        return -1;

}
