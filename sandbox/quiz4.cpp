#include <iostream>
using namespace std;
/*
Write a function StringCat() that takes
two C-strings, t and s; concatenates s to the end of t, then returns the resulting string t. For
example, if t is "cat" and s is "dog", t becomes "catdog", s is unchanged, and you return the
resulting string t. In other words, it works exactly like strcat() from the C-string library. Use
all pointer notation and direct pointer access. Do not include any comments. Write only the
function, no other code. You may not use any functions from the C-string library

strcmp return
<0	the first character that does not match has a lower value in ptr1 than in ptr2
0	the contents of both strings are equal
>0	the first character that does not match has a greater value in ptr1 than in ptr2


*/
int strCmp(char *str1, char *str2)
{
    int str1Len = 0;
    int str2Len = 0;
    while (str1[str1Len])
    {
        str1Len++;
    }
    while(str2[str2Len])
    {
        str2Len++;
    }
    
    int count = 0;
    while(count < max(str1Len, str2Len))
    {
      if(str1[count] != str2[count])
      {
          cout << "they're the different. return: " << (str1[count] < str2[count] ? 1 : -1) << endl;
          return str1[count] < str2[count] ? 1 : -1;
      }
      count++;
    }
    cout << "they're the same " << endl;
    return 0;
}

char *stringCat(char *t, char *s)
{
    int tlength = 0;
    int slength = 0;
    while (t[tlength])
    {
        tlength++;
    }

    while (s[slength])
    {
        slength++;
    }

    for (int i = 0; i < slength; i++)
    {
        t[tlength + i] = s[i];
    }
    t[tlength + slength] = '\0';
    cout << "t is: " << t << endl;
    return t;
}

int main()
{
    // char t[] = "cat";
    // char s[] = "cat";
    // "abcd", "ab"
    // stringCat(t, s);
    strCmp("ab", "ab");

    return 0;
}