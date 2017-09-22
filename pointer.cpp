#include <iostream>

using namespace std;

int main() {
    int x, *reference, dereference;

    x = 1;
    cout << "x:\t" << x << endl;

    reference = &x;
    cout << "&x:\t" << reference << endl;

    dereference = *reference;
    cout << "*x:\t" << dereference << endl;

    *reference = 5;
    cout << "*x = 5;" << endl;    
    cout << "x:\t" << x << endl;

    return 0;
}
