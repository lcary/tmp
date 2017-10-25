#include <iostream>

using namespace std;

void printArray(int a[], int aSize);
// Recursively print an array to screen.

int main() {
    int a1[5] = {1, 2, 3, 4, 5};
    printArray(a1, 5);
    cout << endl;

    int a2[0] = {};
    printArray(a2, 0);
    cout << endl;

    return 0;
}

void printArray(int a[], int aSize)
{
    if (aSize == 0) {
        // avoid segmentation faults for empty lists
        return;
    }
    else if (aSize == 1) {
        cout << a[0] << ' ';
    }
    else {
        printArray(a, aSize - 1);
        cout << a[aSize - 1] << ' ';
    }
}
