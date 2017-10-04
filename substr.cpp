#include <iostream>
#include <string>

using namespace std;

int main() {
    string str, str_reversed;

    // str input:
    cout << "input name: ";
    getline(cin, str);

    cout << str << endl;

    // slicing:
    str = "abcdef";
    cout << str << endl;
    cout << str.substr(3, 2) << endl;

    // length
    cout << str.length() << endl;

    // reversed
    for (int i = (str.length() - 1); i >= 0; i--)
    {
        str_reversed[i] = str[i];
        cout << str[i];
    }
    cout << endl;

    cout << (str_reversed >= str) << endl;

    str = "asdf jkl zxcv";
    cout << str.find(' ') << endl;
    cout << str.find(' ', 5) << endl;

    return 0;
}
