#include <iostream>

using namespace std;

int main() {
    double savings, expenses;

    cout << "Input Savings and Expenses:\n";
    cin >> savings >> expenses;

    if (savings > expenses)
    {
        savings -= expenses;
        expenses = 0;
    }
    else
        cout << "Bankrupt\n";

    cout << "Savings: " << savings << endl;
    cout << "Expenses: " << expenses << endl;

    return 0;
}
