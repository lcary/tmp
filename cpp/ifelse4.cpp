#include <iostream>

using namespace std;

int main() {
    int temperature, pressure;
    cout << "Please enter temperature and pressure:\n";
    cin >> temperature >> pressure;
    if ((temperature >= 100) || (pressure >= 200))
        cout << "Warning\n";
    else
        cout << "OK\n";
    cout << "temperature: " << temperature << endl;
    cout << "pressure: " << pressure << endl;
    return 0;
}
