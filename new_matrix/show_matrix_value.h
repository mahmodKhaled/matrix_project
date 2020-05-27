#include <iostream>
#include <vector>
#include <string>
#include<ctype.h>
// the next function do the show matrix value operation to the user
void show_matrix(double matrix[3][3]) {
    cout << matrix[0][0] << " " << matrix[0][1] << " " << matrix[0][2] << endl;
    cout << matrix[1][0] << " " << matrix[1][1] << " " << matrix[1][2] << endl;
    cout << matrix[2][0] << " " << matrix[2][1] << " " << matrix[2][2] << endl;
}