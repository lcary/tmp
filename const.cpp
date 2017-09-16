#include <iostream>

using namespace std;

int main() {
    const double LITERS_PER_GALLON = 3.78533;
    double gallons;
    cout << "Give number of gallons:\n";
    cin >> gallons;
    cout << "Liters: " << (gallons * LITERS_PER_GALLON) << endl;
    return 0;
}
