#include <iostream>

using namespace std;

const int MAX_ARRAY_SIZE = 5;

int readArr(int arr[], int maxSize);
// read a list of values from stdin into array, returns size of array

void printAboveValue(int arr[], int arrSize, double value);

double getAverage(int arr[], int arrSize);

int main() {
    int arr[MAX_ARRAY_SIZE];
    double avg;
    int size;

    // read array
    size = readArr(arr, MAX_ARRAY_SIZE);

    // get average
    avg = getAverage(arr, size);
    cout << "average value: " << avg << endl;

    // print vals above average
    cout << "values > average: ";
    printAboveValue(arr, size, avg);

    return 0;
}

int readArr(int arr[], int maxSize)
{
    int size;
    cout << "Enter size of array (must be less than " << maxSize << "): ";
    cin >> size;

    cout << "Input " << size << " values in order: ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    return size;
}

void printAboveValue(int arr[], int arrSize, double value)
{
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] > value)
        {
            cout << arr[i];
            cout << " ";
        }
    }
    cout << endl;

}

double getAverage(int arr[], int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
        sum += arr[i];

    return (double)sum / (double)size;
}
