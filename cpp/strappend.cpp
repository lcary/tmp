#include <iostream>
#include <string>

using namespace std;

int main() {
    string x = " ";
    cout << "t=0,x:" << x << endl;
    x += '0';
    x += 'a';
    cout << "t=1,x:" << x << endl;
    return 0;
}
