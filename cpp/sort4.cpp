/* this was an attempt to write mergeSort from scratch
   in a plaintext file. there were multiple compile errors.
   errors will be notated with ERROR(N) in a comment */

#include <iostream>  // ERROR(1): forgot <>'s around iostream include.

using namespace std;

void merge(int arr[], int leftArrayLow, int leftArrayHigh, int rightArrayHigh);
// Merges two portions of a given array in a sorted manner.
// The two portions can be determined from the indices.

void mergeSort(int arr[], int low, int high);
// Sorts an array by recursively dividing
// the array into smaller and smaller arrays,
// sorting the results, and merging their contents
// into the larger arrays or the original array.

int main() {
    int arr[10] = {0, 12, 23, 30, 3, 2, 93, 1, 0, 20};
    mergeSort(arr, 0, 9);
    for (int i = 0; i < 10; i++){
        cout << arr[i] << ' ';
    } // ERROR(2): forgot to close the for-loop initially. had to add this.
    cout << endl;
}

void merge(int arr[], int leftArrayLow, int leftArrayHigh, int rightArrayHigh) {
    // to merge two internal portions of an array,
    // determine the bounds of the arrays from the indices
    // provided, then loop through each array, inserting
    // values from lowest to highest into a temporary array.
    // ensure the temporary array is sorted by comparing the
    // values in the left or right arrays, and inserting whichever
    // is least on each loop. this requires creating variables for
    // 3 indices: the temporary array, the right array, and the left
    // array. after doing this until either the right array or left
    // array is exhausted, loop through the other array and append
    // all remaining values to the temporary array. finally, after
    // all of this, loop through the temporary array and copy the
    // values into the original array.
    int rightArrayLow = leftArrayHigh + 1;  // ERROR(5): originally had "rightArrayHigh + 1" instead.
    int tempArraySize = rightArrayHigh - leftArrayLow + 1;
    int * temp = new int[tempArraySize];
    int leftIndex = leftArrayLow;
    int rightIndex = rightArrayLow;
    int tempIndex = 0;

    while ((leftIndex <= leftArrayHigh) && (rightIndex <= rightArrayHigh)) {

        if (arr[leftIndex] < arr[rightIndex]) {
            temp[tempIndex] = arr[leftIndex];
            leftIndex++;
            tempIndex++;
        }
        else {  // arr[leftIndex] >= arr[rightIndex]
            temp[tempIndex] = arr[rightIndex];
            rightIndex++;
            tempIndex++;
        }

    } // ERROR(4): forgot to add closing brace. additionally didn't indent while block contents.

    while (leftIndex <= leftArrayHigh) {
        temp[tempIndex] = arr[leftIndex];
        leftIndex++;
        tempIndex++;
    }

    while (rightIndex <= rightArrayHigh) {
        temp[tempIndex] = arr[rightIndex];
        rightIndex++;
        tempIndex++;
    }

    tempIndex = 0;

    for (int i = leftArrayLow; i <= rightArrayHigh; i++) {
        arr[i] = temp[tempIndex];  // ERROR(3): originally had "temp[tempIndex]" instead.
        tempIndex++;
    }

    delete [] temp;

}

void mergeSort(int arr[], int low, int high) {
    if (low >= high) {
        // base case: 
        // if there is nothing else to sort, return.
        // so, if the value of low >= high, then return.
        return;
    }
    else {
        // recursive step:
        // in this case, we have an unsorted array of some size.
        // to sort it, lets try dividing and conquering by
        // finding the midpoint and recursively calling this
        // function to sort a portion of the array that this function
        // was called with. once that portion is sorted, sort the next
        // portion and then merge them together.
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
    return;
}
