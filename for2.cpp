#include <iostream>

using namespace std;

int main() {
    int n, m, line, count, nspaces, nstars;
    cout << "Input a positive number: ";
    cin >> n;

    cout << "Square:\n";
    m = n * n;
    for (line = 1; line <= m; line++) {
        cout << '*';
        if (line % n == 0)
            cout << endl;
    }

    cout << "Triangle (left-aligned):\n";
    for (line = 1; line <= n; line++) {
        for (count = 1; count <= line; count++)
            cout << '*';
        cout << endl;
    }

    cout << "Triangle (right-aligned):\n";
    for (line = 1; line <= n; line++) {
        for (count = 1; count <= n; count++)
            if (count > (n - line))
                cout << '*';
            else
                cout << ' ';
        cout << endl;
    }

    cout << "Triangle (right-aligned + incremental approach):\n";
    for (line = 1, nspaces = (n - 1), nstars = 1;
         line <= n;
         line++, nspaces--, nstars++) {
        for (count = 1; count <= nspaces; count++)
            cout << ' ';
        for (count = 1; count <= nstars; count++)
            cout << '*';
        cout << endl;
    }

    return 0;
}
