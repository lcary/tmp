#include <iostream>

using namespace std;

int main() {
    int score;

    cout << "Input score:\n";
    cin >> score;
    
    if (score > 100)
        cout << "High\n";
    else
        cout << "Low\n";

    return 0;
}
