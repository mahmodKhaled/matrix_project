#include <iostream>
#include <vector>
#include <string>
#include<ctype.h>
#include "input_conversion.h"
#include "operations_view.h"
#include "show_matrix_value.h"
#include "addition.h"
#include "subtraction.h"
#include "transpose.h"
#include "multiplication.h"
#include "division.h"
using namespace std;
int main()
{
    vector<vector<double>> mat1{}, mat2{};
    double matrix1[3][3]{}, matrix2[3][3]{}, result_matrix[3][3]{}, inv_matrix[3][3]{};
    vector<double> fill_matrix{}, vec1{}, vec2{}, vec3{};
    string data{}, sum_numbers{}, choice{};
    double number{}, result{}, detereminant{};
    while (true) {
        cout << "you are allowed to enter two matrices at a time, press exit to close the program" << endl;
        cout << "Make sure that your input of matrices is as following: Y = [x x x; x x x; x x x]" << endl;
        for (int i = 0; i < 2; i++) {
            cout << "Enter the contents of the matrix: ";
            getline(cin, data); // take the input from the user
            if (data == "exit") {
                break;
            }
            else {
                operations_in_input(data, sum_numbers, fill_matrix, number);
                separate_fill_matrix_into_three_vectors(vec1, vec2, vec3, fill_matrix);
                if (i == 0) {
                    fill_vector2D(mat1, vec1, vec2, vec3);
                    fill_array2D(matrix1, mat1);
                    // this if condition fill matrix No 1
                }
                if (i == 1) {
                    fill_vector2D(mat2, vec1, vec2, vec3);
                    fill_array2D(matrix2, mat2);
                    // this if condition fill matrix No 2
                }
                empty_vectors(vec1, vec2, vec3, fill_matrix);
            }
        }
        if (data == "exit") {
            break;
        }
        while (true) {
            show_operations();
            cout << "Enter your choice here: ";
            cin >> choice;
            cin.ignore();
            if (choice == "leave") {
                break;
            }
            else if (choice[0] == 'A') {
                show_matrix(matrix1);
                detereminant = DET(matrix1);
                cout << "the determinant of the matrix is: " << detereminant << endl;
                cout << "---------------------" << endl;
            }
            else if (choice[0] == 'B') {
                show_matrix(matrix2);
                detereminant = DET(matrix2);
                cout << "the determinant of the matrix is: " << detereminant << endl;
                cout << "---------------------" << endl;
            }
            else if (choice == "C=A+B" || choice == "C=B+A") {
                add_two_matrices(matrix1, matrix2, result_matrix);
                show_matrix(result_matrix);
                cout << "---------------------" << endl;
            }
            else if (choice == "C=A-B") {
                subtract_two_matrices(matrix1, matrix2, result_matrix);
                show_matrix(result_matrix);
                cout << "---------------------" << endl;
            }
            else if (choice == "C=B-A") {
                subtract_two_matrices(matrix2, matrix1, result_matrix);
                show_matrix(result_matrix);
                cout << "---------------------" << endl;
            }
            else if (choice == "C=A*B") {
                multiply_two_matrices(matrix1, matrix2, result_matrix);
                show_matrix(result_matrix);

            }
            else if (choice == "C=B*A") {
                multiply_two_matrices(matrix2, matrix1, result_matrix);
                show_matrix(result_matrix);
            }
            else if (choice == "C=A'") {
                transpose_matrix(matrix1, result_matrix);
                show_matrix(result_matrix);
                cout << "---------------------" << endl;
            }
            else if (choice == "C=B'") {
                transpose_matrix(matrix2, result_matrix);
                show_matrix(result_matrix);
                cout << "---------------------" << endl;
            }
            else if (choice == "C=A`") {
                double detereminant = DET(matrix1);
                if (detereminant == 0) {
                    cout << "Can't get the inverse" << endl;
                    continue;
                }
                inv(matrix1, inv_matrix);
                show_matrix(inv_matrix);
            }
            else if (choice == "C=B`") {
                double detereminant = DET(matrix2);
                if (detereminant == 0) {
                    cout << "Can't get the inverse" << endl;
                    continue;
                }
                inv(matrix2, inv_matrix);
                show_matrix(inv_matrix);
            }
            else if (choice == "C=A/B") {
                double detereminant = DET(matrix2);
                if (detereminant == 0) {
                    cout << "Can't get the inverse" << endl;
                    continue;
                }
                inv(matrix2, inv_matrix);
                multiply_two_matrices(matrix1, inv_matrix, result_matrix);
                show_matrix(result_matrix);
            }
            else if (choice == "C=B/A") {
                double detereminant = DET(matrix1);
                if (detereminant == 0) {
                    cout << "Can't get the inverse" << endl;
                    continue;
                }
                inv(matrix1, inv_matrix);
                multiply_two_matrices(matrix2, inv_matrix, result_matrix);
                show_matrix(result_matrix);
            }
            else {
                cout << "Invalid input,please try again..." << endl;
            }
        }
    }
    return 0;
}
