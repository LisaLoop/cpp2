//  
// lab3.cpp
// Lisa Lehrman, Antonio Mixon, Carlo Garate
// 9/19/2021
// CS15 Lab 3
// A program that reports the actual vs expected output of running lines of
// C++ code. 

#include <iostream>
using namespace std;

int main()
{
    char str[100] = "This is a simple C-string";
    const char *pstr = "This is a declaration of a pointer to a C-string";
    char *qstr = const_cast<char *>(pstr);
    char *rstr = str;
    cout << "1. -------------------------------------" << endl;
    cout << "Can we change str[10] to a new value?" << endl;
    str[10] = '0';
    cout << "Yes, we can as long as that new value is also a char. " << endl;
    cout << "Result: If you change str[10] = 0 the output is " << endl;
    cout << str << endl; 
    cout << "---------------------------------------\n"
         << endl;
    cout << "2. -------------------------------------" << endl;
    cout << "pstr[10] to a new value ?" << endl;
    // pstr[10] = 'Z';
    // cout << pstr << endl;
    cout << "No, because it's declared as a constant." << endl;
    cout << "result: error: read-only variable is not assignable" << endl;
    cout << "---------------------------------------\n"
         << endl;
    cout << "3. ---------------------------------------" << endl;
    cout << "Can we change pstr to a different string ?" << endl;
    cout << "Expected: No, because it was declared as a constant. (we were wrong)" << endl;
    cout << "result: We can change the entire string, but we can't" << endl;
    cout << "change a piece of the existing string" << endl;
    cout << "---------------------------------------\n"
         << endl;

    cout << "4. ---------------------------------------" << endl;
    cout << "Can we change str to a different string?" << endl;
    cout << "str = some other string' doesn't work." << endl;
    cout << "The error is error: array type 'char [100]' is not assignable" << endl;
    // str = "some other string";
    cout << "\n5. ---------------------------------------" << endl;
    cout << "If we change pstr to point to a different string: pstr = 'Hello';" << endl;
    cout << "What happens to qstr? Will qstr then point to the old" << endl;
    cout << "string or the new string?" << endl;
    cout << "Expected: qstr will point to the old string" << endl;
    cout << qstr << endl; 
    cout << "Result: Correct!" << endl;
    pstr = "Hello";
    cout << qstr << endl;
    cout << "---------------------------------------\n"
         << endl;

    cout << "6. ---------------------------------------" << endl;

    cout << "Can we assign str = 'Goodbye'? Why or why not?" << endl;
    // str = "Goodbye";
    cout << "Expected: Yes, we can it wasn't declared as a const." << endl;
    cout << "when we declare an array it will normally be a const." << endl;
    cout << "Result: error: array type char [100] is not assignable" << endl;
    cout << "---------------------------------------\n"
         << endl;

    cout << "7. ---------------------------------------" << endl;
    cout << "If we change rstr[5], what happens to str?" << endl;
    cout << "Expected: Yes, it's going to change str[5] too." << endl;
    cout << "Result: We were correct!" << endl;
    rstr[5]= 'Z';
    cout << str[5] << endl;
    cout << "---------------------------------------\n"
         << endl;

    cout << "8. ---------------------------------------" << endl;
    cout << "If we change str[10], what happens to rstr?" << endl;
    cout << "Expected : It will also change." << endl;
    cout << "Result: We were correct! " << endl;
    rstr[5] = 'Z';
    cout << str << endl;
    str[10] = 'Z';
    cout << rstr << endl;
    cout << "---------------------------------------\n" << endl;

    cout << "9. ---------------------------------------" << endl;
    cout << "What happens if you print pstr, *pstr, or (void *)pstr?" << endl;
    cout << "pstr - " << endl;
    cout << "Expected: It's going to print the string: " << endl;
    cout << pstr << endl;
    cout << "Result: We were right! " << endl;
    cout << "*pstr -:" << endl;
    cout << "Expected: The address in memory of the base of the pstr array" << endl;
    cout << "Result: T - It gives us the value stored at the start of the array pstr" << endl;
    cout << "(void *) pstr" << endl;
    cout << "Expected : The address of the pointer Result : 0x10466ef24(Some address)" << endl;
    cout << "Result: We were right!"<< endl;
    cout << pstr << endl;
    cout << *pstr << endl;
    cout << (void *)pstr << endl;
    cout << "---------------------------------------\n" << endl;
    return 0;
}
