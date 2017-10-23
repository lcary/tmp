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
        int mid = (start + end) / 2;
        printAsc(start, mid);
        printAsc(mid + 1, end);
    }
}
