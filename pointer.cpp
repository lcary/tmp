#include <iostream>

using namespace std;

int main() {
    int x;

    // referencing a value with the "address-of" operator
    x = 1;
    cout << "&x:\t" << &x << endl;     // reference
    cout << " x:\t" << x << endl;      // value

    int *ptr = &x;
    cout << " ptr:\t" << ptr << endl;  // reference
    cout << "*ptr:\t" << *ptr << endl; // dereference

    *ptr = 5;
    cout << "*x = 5;" << endl;    
    cout << " x:\t" << x << endl;      // value

    return 0;
}
