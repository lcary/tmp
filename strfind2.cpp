#include <iostream>
#include <string>

using namespace std;

int main() {
    int found;
    string no_spaces = "asdfasdf";
    string has_spaces = "asdf asdf";

    cout << "spaces in " << no_spaces << ": ";
    found = no_spaces.find(' ');
    cout << found << endl;
    if (found == string::npos)
        cout << no_spaces << " HAS NO SPACES!!!!!\n";
    cout << "spaces in " << has_spaces << ": ";
    found = has_spaces.find(' ');
    cout << found << endl;
    if (found == string::npos)
        cout << has_spaces << " HAS NO SPACES!!!!!\n";
    return 0;
}
