#include <iostream>
#include <vector>
#include <string>
#include<ctype.h>
#include "input_conversion.h"
#include "operations_view.h"
#include "show_matrix_value.h"
#include "addition.h"
#include "subtraction.h"
using namespace std;
int main()
{
    vector<vector<double>> mat1{}, mat2{};
    double matrix1[3][3]{}, matrix2[3][3]{}, result_matrix[3][3]{};
    vector<double> fill_matrix{}, vec1{}, vec2{}, vec3{};
    string data{}, sum_numbers{}, choice{};
    int num_of_matrices{};
    double number{},result;
    cout << "Enter the number of matrices: ";
    cin >> num_of_matrices;
    cin.ignore(); // take number of matrices from the user
    for (int i = 0; i < num_of_matrices; i++) {
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

    while (true) {
        show_operations();
        cin >> choice;
        if (choice == "exit") {
            break;
        }
        else if(choice[0]=='A') {
            show_matrix(matrix1);
        }
        else if (choice[0] == 'B') {
            show_matrix(matrix1);
        }
        if (choice == "C=A+B") {
            add_two_matrices(matrix1,matrix2,result_matrix);
            show_matrix(result_matrix);
            cout << "---------------------" << endl;
        }
        else if (choice == "C=A-B") {
            subtract_two_matrices(matrix1,matrix2,result_matrix);
            show_matrix(result_matrix);
            cout << "---------------------" << endl;
        }
    }
    return 0;
}


