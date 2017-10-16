#include <iostream>
#include <string>

using namespace std;

const int MAX_WORDS = 100;

string readText();

int readWordIndex();

int countSymbolsWhile(string text, string words[], char symbol);

int countSymbolsRecursively(string text, string words[], char symbol);

int countSymbolsRecursively(string text, string words[], int start, char symbol, int &count);

int countWords(string text, string words[]);

int main() {
    int index;
    string words[MAX_WORDS];

    // count and index words
    string text = readText();
    int count = countWords(text, words);
    cout << count << " words were found.\n";

    // read word request and display word
    index = readWordIndex();
    cout << "Here's your word: " << words[index] << "\n";

    return 0;
}

string readText()
{
    string text;

    cout << "Please enter no more than " << MAX_WORDS << " words (separated by spaces): ";
    getline(cin, text);

    return text;
}

int readWordIndex()
{
    int n;
    cout << "Enter index (0 = first) of word you want printed: ";
    cin >> n;
    return n;
}

int countSpaces(string text, string words[])
{
    return countSymbolsWhile(text, words, ' ');
}

int countSymbolsWhile(string text, string words[], char symbol)
{
    bool endOfSentence = false;
    int count = 0;
    int start = 0;
    int currIndex;
    while (endOfSentence == false)
    {
        currIndex = text.find(symbol, currIndex);
        if (currIndex == string::npos)
        {
            string word = text.substr(start, (text.size() - currIndex));
            endOfSentence = true;
            cout << "Indexing " << word << " at index " << count << endl;
            words[count] = word;
        }
        else
        {
            string word = text.substr(start, (currIndex - start));
            cout << "Indexing " << word << " at index " << count << endl;
            words[count] = word;
            currIndex++;
            start = currIndex;
            count++;
        }
    }
    return count;
}

int countSymbolsRecursively(string text, string words[], char symbol)
{ 
    int start = 0;
    int count = 0;
    return countSymbolsRecursively(text, words, start, symbol, count);
}

int countSymbolsRecursively(string text, string words[], int start, char symbol, int &count)
{
    int currIndex = text.find(symbol, start);
    if (currIndex == string::npos)
    {
        words[count] = text.substr(start, text.size());
        return count;
    }
    else
    {
        words[count] = text.substr(start, (currIndex - start));
        currIndex++;
        count++;
        return countSymbolsRecursively(text, words, currIndex, symbol, count);
    }
}

int countWords(string text, string words[])
{
    int spaces = countSpaces(text, words);
    // assume 1 more word than number of spaces
    return spaces + 1;
}
