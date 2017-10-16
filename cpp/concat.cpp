#include <iostream>
#include <string>

using namespace std;

string mystr(){
    string s = "s" + "t";
    return s;
}

int main() {
    cout << mystr() << endl;
    return 0;
}
