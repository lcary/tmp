#include <iostream>

using namespace std;

const int DECLARED_SIZE = 10;

int main() {
    char letter_box[DECLARED_SIZE];
    int index;
    char next;

    index = 0;

    cout << "enter up to " << DECLARED_SIZE << " chars. stop with a period ('.'):\n";
    cin >> next;

    while ((next != '.') && (index < DECLARED_SIZE)) {
        letter_box[index] = next;
        index++;
        cin >> next;
    }

    for (int i = (index - 1); i >= 0; i--) {
        cout << letter_box[i];
    }
    cout << endl;

    return 0;
}
