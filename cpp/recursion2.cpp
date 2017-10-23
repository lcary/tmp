#include <iostream>

using namespace std;

void printAsc(int start, int end);

int main() {
    printAsc(0, 10);
    return 0;
}

void printAsc(int start, int end)
{
    if (start == end) {
        cout << start << endl;
    }
    else {
        cout << start << endl;
        // cout << "printAsc(" << start + 1 << ", " << end << ") ";
        printAsc(start + 1, end);
    }
}
