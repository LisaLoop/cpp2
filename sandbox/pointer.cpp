#include <iostream>
using namespace std;

int main () {
  int a[] = {1,2,3};
  const int *b = a;
  int c[] = {4,5,6};
  b = c;
  a[0] = 5; 
  cout << b[0] << endl; // 4
  
//   b[1] = 9;
  cout << a[1] << endl; // 2
  return 0;
}
