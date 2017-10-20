#include <iostream>

using namespace std;

int main() {

    int * ptr = new int[20];

    ptr[1] = 20;

    cout << ptr[1] << endl;

    delete [] ptr;
    // delete [] ptr;  // pointer being freed was not allocated

    ptr = nullptr;

    delete [] ptr;
    delete [] ptr;  // works!

    return 0;
}
