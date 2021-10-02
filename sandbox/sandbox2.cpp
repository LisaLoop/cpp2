#include <iostream>
using namespace std;

size_t strlen(char *word);
// longest
char biggest[16] = "";
void getLongestWord(char word[])
{
    size_t wordLength = strlen(word);
    if (wordLength >= strlen(biggest))
    {
        strcpy(biggest, word);
    }
}
int main(int argc, char *argv[])
{
    return 0;
}

/**
 * The indirection operator is an asterisk (*).
 * When the indirection operator is placed in front of a pointer variable name, it dereferences the pointer. 
 * 
 *  In C++, when you add a value to a pointer, you are actually adding that value times the size of the
 *  data type being referenced by the pointer. In other words, if you add one to numbers,
 *  you are actually adding 1 * sizeof(short) to numbers . 
 */