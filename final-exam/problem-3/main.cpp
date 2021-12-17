#include "AsciiArt.h"
#include <iostream>
using namespace std;
// Sample driver

int main() {
    AsciiArt pic(14, 24);
    pic.setRow(0, 1, "HERE IS A PICTURE!");
    char s[] = "************";
    for (int i = 1; i < pic.getNumRows() - 1; i++)
        pic.setRow(i, pic.getNumCols() - i, s);
    pic.setRow(pic.getNumRows() - 5, 0, "ZZZZZZZZZZZZZZZZZZZZZZZZ");
    pic.setRow(pic.getNumRows() - 4, 0, "  ZZZZZZZZZZZZZZZZZZZZ  ");
    pic.setRow(pic.getNumRows() - 3, 0, "     ZZZZZZZZZZZZZZ     ");
    pic.setRow(pic.getNumRows() - 2, 0, "         ZZZZZZ         ");
    pic.setRow(pic.getNumRows() - 1, 0, "           ZZ           ");
    pic.draw(cout);
    cout << endl;
    AsciiArt pic2 = pic;
    cout << pic2.flip() << endl << endl;
    pic2.draw(cout);
    cout << (pic2 *= 2) << endl;
    cout << pic2.flip() << endl << endl;
    cout << (pic2 /= 2) << endl;
    cout << ((pic2 *= 3).flip() *= 2) << endl;
    cout << pic2.flip() << endl;
    cout << (pic2 /= 3) << endl;
    cout << (pic2 /= 2) << endl;
    cout << (pic2 /= 2) << endl;
    cout << (pic2 *= 2) << endl;
    return 0;
}