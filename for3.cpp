#include <iostream>

using namespace std;

int main() {
    for (int count = 1; count < 5; count++)
        cout << (2 * count) << " ";

    cout << endl;

    for (int n = 10; n > 0; n = n - 2)
    {
        cout << "Hello ";
        cout << n << endl;
    }

    return 0;
}
