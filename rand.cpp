#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int x;

    cout << "seed: " << time(0) << endl;

    srand(time(0));

    for (x = 0; x < 10000; x++)
    {
        cout << rand() % 100 + 1;
        if (x % 70 == 0)
            cout << endl;
        else
            cout << " ";
    }

    cout << endl;

    return 0;
}