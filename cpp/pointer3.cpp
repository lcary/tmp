#include <iostream>

using namespace std;

int main() {

    int * ptr = new int[20];

    // pointer arithmetic
    for (int i = 0; i < 20; i++) {
        ptr[i] = i;
    }

    // ptr starts with address of 0
    // ptr moves to next element in array with ptr++

    for (int i = 0; i < 20; i++) {
        cout << *ptr << ' ' << ptr << endl;
        ptr++;
    }

    return 0;
}
