#include <iostream>
#include <vector>
#include <string>
#include<ctype.h>
using namespace std;
// the next function display the operations that our program do to the user
void show_operations() {
    cout << "--------------------------------------------------------" << endl;
    cout << "You can do any operation from the following:" << endl;
    cout << "write your input without spaces..." << endl;
    cout << "Show Matrix Value: A or B" << endl;
    cout << "Addition: C = A + B or C = B + A " << endl;
    cout << "Subtraction: C = A - B or C = B - A" << endl;
    cout << "Multiplication: C = A * B or C = B * A" << endl;
    cout << "Transpose: C = A' or C = B'" << endl;
    cout << "Division: C = A/B or C = B/A" << endl;
    cout << "Inverse: C = A` or C = B`" << endl;
    cout << "press leave to input new two matrices" << endl;
    cout << "-------------------------------------------------" << endl;
}

