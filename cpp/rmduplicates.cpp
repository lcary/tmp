#include <iostream>

using namespace std;

void printArray(int arr[], int arrSize);

int *rmDuplicates(int arr[], int arrSize, int &resArrSize);

int main() {
    int arr[7] = {2, 3, 4, 1, 5, 4, 3};  // bug: what if it's 11 instead of 1?????
    int arrSize = 7;
    int *noDupArr;
    int noDupArrSize, i;

    noDupArr = rmDuplicates(arr, arrSize, noDupArrSize);

    printArray(noDupArr, noDupArrSize);

    delete [] noDupArr;

    return 0;
}

void printArray(int arr[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

int *rmDuplicates(int arr[], int arrSize, int &resArrSize)
{
    int *countersArray, *resArray;
    int countersArraySize, i, count, writeIndex;

    countersArray = new int[arrSize];
    countersArraySize = arrSize;

    for (i = 1; i <= (arrSize - 1); i++) {
        countersArray[i] = 0;
    }

    for (i = 0; i < arrSize; i++) {
        int value = arr[i];
        countersArray[value]++;
    }

    count = 0;

    for (i = 1; i <= (arrSize - 1); i++) {
        if (countersArray[i] != 0)
            count++;
    }

    resArrSize = count;
    resArray = new int[resArrSize];

    writeIndex = 0;
    for (i = 1; i <= (arrSize - 1); i++) {
        if (countersArray[i] != 0) {
            resArray[writeIndex] = i;
            writeIndex++;
        }
    }

    delete [] countersArray;

    return resArray;
}
