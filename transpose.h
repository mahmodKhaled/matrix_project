#include <iostream>
using namespace std;
void transpose_matrix(double matrix1[3][3],double result_matrix[3][3])
{
    for (int j = 0; j < 3; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            result_matrix[k][j] = matrix1[j][k];
        }
    }
}