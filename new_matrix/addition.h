// the next function add two matrices and store the result into result_matrix
void add_two_matrices(double matrix1[3][3], double matrix2[3][3], double result_matrix[3][3]) {
    for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
            result_matrix[j][k] = matrix1[j][k] + matrix2[j][k];

        }
    }
}