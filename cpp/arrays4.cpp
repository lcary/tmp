#include <iostream>

using namespace std;

const int DECLARED_SIZE = 10;

int main()
{
    int arr[DECLARED_SIZE];
    int index, next;

    cout << "enter up to 10 non negative ints. end by entering negative int.\n";
    index = 0;
    cin >> next;

    while ((next >= 0) && (index < DECLARED_SIZE)) {
        arr[index] = next;
        index++;
        cin >> next;
    }

    for (int i = 0; i < index; i++)
        cout << arr[i] << ' ';
    cout << endl;

    return 0;
}
