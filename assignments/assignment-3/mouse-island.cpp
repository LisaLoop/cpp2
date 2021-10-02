//
// Lisa Lehrman
// Oct 1, 2021
// CS15
// Assignment 3
// A program that does something
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
/*

parse command line parameters, open files ✅
if needed, seed the random number generator
read the map && save initial positions of the mouse and bridges
initialize the count map to all zeros
print the file names, seed rule, island map
loop over 100 lives
 put mouse at starting point on map
 loop until 100 moves made, or mouse escapes or drowns
 move mouse
 count move to target square
 if( drowned )
 handle drowning
 else if( escaped )
 handle escaping
 end if
 end loop until 100 moves, etc.
 if( starved )
 handle starving
 end if
end loop over 100 lives
print life statistics and count map
close files

*/

int main(int argc, char *argv[])
{

    char *seed;
    if (argc < 2)
    {
        cout << "Usage: " << argv[0] << " <input> <output> [<seed>]" << endl;
        cout << "Enter either the seed value or the string TIME" << endl;
        cout << "to seed the random number generator using the" << endl;
        cout << "current time." << endl;
        return 0;
    }
    if (argc == 3)
    {
        seed = argv[3];
    }
    if (seed && strcmp(seed, "TIME") == 0)
    {
        srand(time(0));
    }
    else if (seed)
    {
        int s = stoi(seed,nullptr,0);
        srand(s);
    } else
    {
        rand();
    }

    ifstream inputFile;
    ofstream outputFile;
    const char *inputFileName = argv[1];
    const char *outputFileName = argv[2];

    inputFile.open(inputFileName);
    outputFile.open(outputFileName);
    if (!inputFile)
    {
        cout << "There was a problem opening input file " << inputFileName << endl;
    }
    if (!outputFile)
    {
        cout << "There was a problem opening output file " << outputFileName << endl;
    }

    return 0;
}