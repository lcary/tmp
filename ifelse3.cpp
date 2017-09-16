#include <iostream>

using namespace std;

int main() {
    double exam, programs_done;
    cout << "Please enter exam score and number of programs done:\n";
    cin >> exam >> programs_done;
    if ((exam >= 60) && (programs_done >= 10))
        cout << "Passed\n";
    else
        cout << "Failed\n";
    cout << "exam: " << exam << endl;
    cout << "programs_done: " << programs_done << endl;
    return 0;
}
