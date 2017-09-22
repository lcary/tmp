#include <iostream>

using namespace std;

int main() {

    int n, counter, power;
    cout << "Input a positive number: ";
    cin >> n;    

    # incremental approach
    for (counter = 1, power = 1; counter <= n; counter++, power *= 2) {
        cout << "counter: " << counter << "\t current power: " << power << endl;
    }

    return 0;
}
