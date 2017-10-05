#include <iostream>
#include <string>

using namespace std;

string readText();

int countSymbolsWhile(string text, char symbol);

int countSymbolsRecursively(string text, char symbol);

int countSymbolsRecursively(string text, int start, char symbol, int &count);

int countWords(string text);

int main() {
    string text = readText();
    int words = countWords(text);
    cout << words << " words were found.\n";
    return 0;
}

string readText()
{
    string text;

    cout << "Please enter text (separated by spaces): ";
    getline(cin, text);

    return text;
}

int countSpaces(string text)
{
    return countSymbolsRecursively(text, ' ');
}

int countSymbolsWhile(string text, char symbol)
{
    int counter = -1;
    int currIndex = -1;
    do
    {
        currIndex++;
        currIndex = text.find(' ', currIndex);
        counter++;
    }
    while (currIndex != string::npos);
    return counter;
}

int countSymbolsRecursively(string text, char symbol)
{ 
    int start = 0;
    int count = 0;
    return countSymbolsRecursively(text, start, symbol, count);
}

int countSymbolsRecursively(string text, int start, char symbol, int &count)
{
    int currIndex = text.find(symbol, start);
    if (currIndex == string::npos)
        return count;
    else
    {
        currIndex++;
        count++;
        return countSymbolsRecursively(text, currIndex, symbol, count);
    }
}

int countWords(string text)
{
    int spaces = countSpaces(text);
    // assume 1 more word than number of spaces
    return spaces + 1;
}
