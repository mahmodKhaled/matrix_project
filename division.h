#include <iostream>
using namespace std;
void inv(double matrix2[3][3], double result_matrix[3][3])
{
	double Determinant_value = 0, indet = 0;
	Determinant_value = ((matrix2[0][0] * (matrix2[1][1] * matrix2[2][2] - matrix2[1][2] * matrix2[2][1])) - (matrix2[0][1] * (matrix2[1][0] * matrix2[2][2] - matrix2[1][2] * matrix2[2][0])) + (matrix2[0][2] * (matrix2[1][0] * matrix2[2][1] - matrix2[1][1] * matrix2[2][0])));
	indet = 1 / Determinant_value;

	result_matrix[0][0] = (matrix2[1][1] * matrix2[2][2] - matrix2[2][1] * matrix2[1][2]) * indet;
	result_matrix[0][1] =(matrix2[0][2] * matrix2[2][1] - matrix2[0][1] * matrix2[2][2]) * (indet);
	result_matrix[0][2] = (matrix2[0][1] * matrix2[1][2] - matrix2[0][2] * matrix2[1][1]) * indet;
	result_matrix[1][0] = (matrix2[1][2] * matrix2[2][0] - matrix2[1][0] * matrix2[2][2]) * (indet);
	result_matrix[1][1] = (matrix2[0][0] * matrix2[2][2] - matrix2[0][2] * matrix2[2][0]) * indet;
	result_matrix[1][2] =(matrix2[1][0] * matrix2[0][2] - matrix2[0][0] * matrix2[1][2]) *(indet);
	result_matrix[2][0] = (matrix2[1][0] * matrix2[2][1] - matrix2[2][0] * matrix2[1][1]) * indet;
	result_matrix[2][1] = (matrix2[2][0] * matrix2[0][1] - matrix2[0][0] * matrix2[2][1]) *(indet);
	result_matrix[2][2] = (matrix2[0][0] * matrix2[1][1] - matrix2[1][0] * matrix2[0][1]) * indet;
}





