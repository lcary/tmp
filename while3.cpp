#include <iostream>

using namespace std;

int main() {
    int count = 3;
    while (--count > 0)
    {
        cout << count << ' ';
    }
    cout << endl;

    int n = 1;
    do
        cout << n << " ";
    while (n++ <= 3);
    cout << endl;

    n = 1;
    do
        cout << n << " ";
    while (++n <= 3);
    cout << endl;

    return 0;
}
