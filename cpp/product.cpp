#include <iostream>

using namespace std;

void outputProduct(int a, int b, int c);
// Output product of three integers.

int main()
{
    int a, b, c;

    cout << "input 3 ints: ";
    cin >> a >> b >> c;

    outputProduct(a, b, c);

    return 0;
}

void outputProduct(int a, int b, int c)
{
    cout << (a * b * c) << endl;
}
