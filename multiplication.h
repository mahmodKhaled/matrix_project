#include<iostream>
using namespace std;
void multiply_two_matrices(double matrix1[3][3], double matrix2[3][3], double result_matrix[3][3]) {
	int i,j,k;
		for (i = 0; i < 3; ++i) {
			for (j= 0; j < 3; ++j) {
				result_matrix[i][j] = 0;
			}
		}
			for (i = 0; i < 3; ++i)
			{
				for (j = 0; j < 3; ++j)
				{
					for (k = 0; k < 3; ++k)
					{
						result_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
					}
				}
			}
}
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	