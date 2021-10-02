//
// text-report.cpp
// CS15 Assignment 2
// Lisa Lehrman
//
// A program that reads lines of text from an input file
// and keeps statistics on the data in the file.

#include <iostream>
#include <cstring> // strlen, strcmp
#include <fstream>
using namespace std;

/* 
isLongestWord takes a c-string word and the
currentLongestWord, also a c-string, and returns 
a boolean value to indicate whether or not the word 
is longer or shorter than the currentLongestWord
In the case of a tie, the word that comes last
in the line will win.
*/
bool isLongestWord(char word[], char currentLongestWord[])
{
    size_t wordLength = strlen(word);
    size_t currentLongestLength = strlen(currentLongestWord);
    return wordLength >= currentLongestLength;
};

/* 
isShortestWord takes a c-string, word, and the
currentShortestWord, also a c-string, and returns 
a boolean value to indicate whether or not the word 
is shorter than the currentShortestWord
In the case of a tie, the word that comes last
in the line will win.
*/
bool isShortestWord(char word[], char currentShortestWord[])
{
    size_t wordLength = strlen(word);
    size_t currentShortestLength = strlen(currentShortestWord);
    return wordLength <= currentShortestLength;
};

/* 
find word takes a word and an array of
uniqueWords. It returns -1 if the word was not found
or the index position where the word was found,
if it was found.
*/
int findWord(char word[], char uniqueWords[100][16])
{
    int i;
    for (i = 0; i < 100; i++)
    {
        if (strcmp(word, uniqueWords[i]) == 0)
        {
            return i; // word was found
        }
    }
    return -1;
}

int main(int argc, char *argv[])
{
    ifstream inputFile;
    ofstream outputFile;

    if (argc < 3)
    {
        cout << "Usage:" << argv[0] << " <input> <output>\n";

        return 0;
    }
    const char *inputFileName = argv[1];
    const char *outputFileName = argv[2];
    inputFile.open(inputFileName);
    outputFile.open(outputFileName);
    if (!inputFile)
    {
        cout << inputFileName << " could not be opened.\n"
                                 "Please check that the file name exists\n"
                                 "and it has appropriate permissions\n"
             << endl;
        return -1;
    }
    if (!outputFile)
    {
        cout << outputFileName << " file could not be opened.\n"
                                  "Please check that the file name exists\n"
                                  "and it has appropriate permissions\n"
             << endl;
        return -1;
    }

    char uniqueWords[100][16] = {0};
    int wordCounts[100] = {0};
    char line[100];
    int lineCount = 0;
    char *word;
    int lastWordIndex = 0;
    int totalWordCount = 0;
    while (!inputFile.eof())
    {
        inputFile.getline(line, sizeof(line));
        if (strlen(line) == 0)
        {
            break;
        }
        outputFile << line << endl;
        lineCount++;
        word = strtok(line, " .");
        while (word)
        {
            // index of word in char array should match
            // index of word in int array
            totalWordCount++;
            int wordIndex = findWord(word, uniqueWords);
            if (wordIndex == -1)
            { // we didn't find the word so we add it to the list
                strcpy(uniqueWords[lastWordIndex], word);
                wordCounts[lastWordIndex]++;
                lastWordIndex++;
            }
            else
            {
                // we found the word, so we increment the count
                wordCounts[wordIndex]++;
            }
            word = strtok(NULL, " .");
        }
    }
    char shortestWord[16] = {0};
    char longestWord[16] = {0};
    strcpy(shortestWord, uniqueWords[0]);
    strcpy(longestWord, uniqueWords[0]);
    for (int i = 0; i < lastWordIndex; i++)
    {
        if (isShortestWord(uniqueWords[i], shortestWord))
        {
            strcpy(shortestWord, uniqueWords[i]);
        };
        if (isLongestWord(uniqueWords[i], longestWord))
        {
            strcpy(longestWord, uniqueWords[i]);
        }
    }

    outputFile << '\n'
               << setw(strlen(longestWord)) << "Word counts" << endl;
    outputFile << "--------------------------------------\n";
    for (int i = 0; i < lastWordIndex; i++)
    {
        outputFile << setw(strlen(longestWord))
                   << uniqueWords[i] << setw(15) << wordCounts[i] << endl;
    }
    outputFile << endl;
    outputFile << "total word count:       " << totalWordCount << endl;
    outputFile << "number of unique words: " << lastWordIndex << endl;
    outputFile << "shortest word is:       " << shortestWord << endl;
    outputFile << "longest word is:        " << longestWord << endl;
    outputFile << "number of lines is:     " << lineCount << endl;
    return 0;
}
