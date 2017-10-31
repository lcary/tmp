#include <iostream>

void output(int a, int b);

void swap1(int *a, int *b);

void swap2(int &a, int &b);

int main()
{
    int a = 10;
    int b = 30;

    output(a, b);
    swap1(&a, &b);
    output(a, b);
    swap2(a, b);
    output(a, b);

    return 0;
}

void output(int a, int b)
{
    using namespace std;
    cout << "a: " << a << " b: " << b << endl;
}

void swap1(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap2(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
