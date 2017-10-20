#include <iostream>

using namespace std;

int main() {
    int x;
    int *px;

    x = 7;
    px = &x;
    cout << x << ' ' << px << endl;

    *px = 8;

    cout << x << ' ' << px << endl;

    return 0;
}
