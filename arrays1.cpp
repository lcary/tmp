#include <iostream>

using namespace std;

const int MAX_SIZE = 10;

void input_number(int index, int (&arr)[MAX_SIZE]);

double get_average(int size, int arr[MAX_SIZE]);

int main() {
    double avg;
    int i, size, sum;
    int arr[MAX_SIZE];

    cout << "Enter size <= " << MAX_SIZE << ": ";
    cin >> size;

    for (i = 0; i < size; i++)
    {
        input_number(i, arr);
    }

    avg = get_average(size, arr);
    cout << "The average is: " << avg << endl;

    return 0;
}

void input_number(int index, int (&arr)[MAX_SIZE])
{
    cout << "Enter a number: ";
    cin >> arr[index];
}

double get_average(int size, int arr[MAX_SIZE])
{
    int i;
    int sum = 0;
    for (i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return (double)sum / size;
}
