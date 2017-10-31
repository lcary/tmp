#include <cmath>
#include <iostream>

using namespace std;

const int SIZE4 = 4;

int main() {

    // static array
    int x[SIZE4];
    cout << x << endl;

    for (int i = 0; i < SIZE4; i++)
        x[i] = pow(i, i + 7);

    for (int i = 0; i < SIZE4; i++)
        cout << x[i] << ' ';
    cout << endl;

    int * y = new int[SIZE4];
    cout << y << endl;

    y[0] = 213467765;
    for (int i = 0, j = SIZE4; i < SIZE4; i++, j--)
        y[j] = x[i];

    for (int i = 0; i < (SIZE4 + 1); i++)
        cout << y[i] << ' ';
    cout << endl;

    delete [] y;

    return 0;
}
