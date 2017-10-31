#include <iostream>
#include <string>

using namespace std;

struct Cup
{
    bool isCracked;
    int totalVolume;
    int usedVolume;
    string volumeUnits;
};

void fillCupInfo(Cup& aCup);

void printCupInfo(Cup aCup);

int main() {

    Cup myCup;

    fillCupInfo(myCup);
    printCupInfo(myCup);

    return 0;
}

void fillCupInfo(Cup& aCup)
{
    aCup.isCracked = false;    
    aCup.totalVolume = 8;
    aCup.usedVolume = 4;
    aCup.volumeUnits = "oz";
}

void printCupInfo(Cup aCup)
{
    cout << "Out of a total of " << aCup.totalVolume << aCup.volumeUnits;
    cout << ", my cup is " << aCup.usedVolume << aCup.volumeUnits << " full.\n";

    cout << "Also, my cup is ";
    if (!aCup.isCracked)
        cout << "not ";
    cout << "cracked.\n";
}
