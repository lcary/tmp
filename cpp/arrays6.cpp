/* attempt to implement a function that resizes a dynamic array. written
   in a plaintext file. there were multiple compile errors.
   errors will be notated with ERROR(N) in a comment */
#include <iostream>

// ERROR(1): 'newSize' missing type specifier 'int'
// ERROR(3): 'int& *arr' was wrong, should be 'int *&arr'
void resizeArray(int *&arr, int oldSize, int newSize);
// precondition: non-empty array of a given size is passed.
// postcondition: array is resized to a new size.

int main() {
    int staticArray[10] = {0, 12, 3, 2, 11, 30, 39, 28, 9, 90};

    int *dynamicArray = new int[10];

    for (int i = 0; i < 10; i++) {
        dynamicArray[i] = staticArray[i];
    }
    resizeArray(dynamicArray, 10, 12);
    dynamicArray[10] = 100;
    dynamicArray[11] = 0;

    // does it break for resizing the static array? YES.
    // arrays6.cpp:25:36: error: cannot bind non-const lvalue reference of type 'int*&' to an rvalue of type 'int*'
     // resizeArray(staticArray, 10, 12);
     //                                ^
    // resizeArray(staticArray, 10, 12);

    return 0;
}

// ERROR(2): 'newSize' missing type specifier 'int'
// ERROR(4): 'int& *arr' was wrong, should be 'int *&arr'
void resizeArray(int *&arr, int oldSize, int newSize) {
    // create a pointer to a temporary array of the new size.
    // copy all elements from the old array into the new array.
    // delete the old array on the heap. point its pointer at
    // the new array.

    int *temp = new int[newSize]; // ERROR(5) : was originally 'int *temp[newSize];'
    for (int i = 0; i < oldSize; i++) {
        temp[i] = arr[i];
    }

    delete [] arr;
    arr = temp;
}