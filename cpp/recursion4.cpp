#include <iostream>
#include <string>

using namespace std;

void printAscDesc(int start, int end, int &depth);

int main() {
    int depth = 0;
    printAscDesc(0, 10, depth);
    return 0;
}

void printAscDesc(int start, int end, int &depth)
{
    depth++;
    string margin = string(depth, ' ');
    if (start == end) {
        cout << margin << start << endl;
    }
    else {
        cout << margin << start << endl;
        printAscDesc(start + 1, end, depth);
        // margin = margin.substr(0, margin.size() - 1);
        cout << margin << start << endl;
    }
}
