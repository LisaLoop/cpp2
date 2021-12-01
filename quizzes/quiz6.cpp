/*
Write a complete C++ program that
takes a rule for seeding the random number from the command line (as explained below), seeds
the random number generator, and then prints a single random number to the console. 

The seed
rules are: if the argument is a negative number, seed with the time, if zero, do not seed, if
positive, seed with the value. You may print just the random number, without any other text.
Include everything the program needs to compile and run, but no comments.

*/
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv)
{
   int seed;
   if(argc < 2)
   {
       cout << "Usage: " << argv[0] << " seedrule" << endl;
       return -1;
   }
   seed = atoi(argv[1]);
   if(seed == 0)
   {
       srand(time(NULL));
   } 
   else if(seed > 0)
   {
       srand(seed);
   }
   cout << rand() << endl;
   return 0;
}