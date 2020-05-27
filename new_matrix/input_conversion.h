#include <iostream>
#include <vector>
#include <string>
#include<ctype.h>
using namespace std;
// the next function after every loop delete the content of these vectors to fill in another matrix
void empty_vectors(vector<double>& vec1, vector<double>& vec2, vector<double>& vec3, vector<double>& fill_matrix) {
    vec1.clear();
    vec2.clear();
    vec3.clear();
    fill_matrix.clear();
}
// the next function responsible for converting input from string to double to be usable
void separate_fill_matrix_into_three_vectors(vector<double>& vec1, vector<double>& vec2, vector<double>& vec3, vector<double>& fill_matrix) {
    /*the next three for loop we take every three element strored in the fill_matrix vector
        and put every three in one single vector then we put the three in the vector 2D to have
        the known shape of the matrix as we know like that
        1 2 3
        4 5 6
        7 8 9*/
    for (int i = 0; i < 3; i++) {
        vec1.push_back(fill_matrix[i]);
    }
    for (int i = 3; i < 6; i++) {
        vec2.push_back(fill_matrix[i]);
    }
    for (int i = 6; i < 9; i++) {
        vec3.push_back(fill_matrix[i]);
    }
}
//the next function fill the vector 2D to form the matrix from the small three vectors

void operations_in_input(string data, string sum_numbers, vector<double>& fill_matrix, double number,int found) {
    /* in the next loop, we will loop through the input and check every character, we only need
        the number characters and we will ignore the ; and A and [], just we will take numbers and convert
        them into double*/
    if (found != -1) {
        for (auto sub_sub_data : data) {
            if (sub_sub_data == '1' || sub_sub_data == '2' || sub_sub_data == '3' || sub_sub_data == '4' || sub_sub_data == '5' || sub_sub_data == '6' || sub_sub_data == '7' || sub_sub_data == '8' || sub_sub_data == '9' || sub_sub_data == '.' || sub_sub_data == '-') {
                sum_numbers += sub_sub_data;
                if (sum_numbers.length() == 3 && sum_numbers[0] != '-') {
                    number = stod(sum_numbers); // convert numbers from strings into double
                    fill_matrix.push_back(number); // this matrix will take all the converted numbers
                }
                // the next if condition made for numbers who have negative sign
                else if (sum_numbers.length() == 4) {
                    number = stod(sum_numbers);
                    fill_matrix.push_back(number);
                }
            }
            else {
                sum_numbers.clear();
                /*after every number is in complete form (because the number form after three loops like that
                1 . 2 then we add the three to be 1.2) then we delete the content of the variable
                to store a new number on it*/
            }
        }
    }
    else if (found == -1) {
        for (auto sub_sub_data : data) {
            if (sub_sub_data == '1' || sub_sub_data == '2' || sub_sub_data == '3' || sub_sub_data == '4' || sub_sub_data == '5' || sub_sub_data == '6' || sub_sub_data == '7' || sub_sub_data == '8' || sub_sub_data == '9' || sub_sub_data == '.' || sub_sub_data == '-') {
                sum_numbers += sub_sub_data;
                if (sum_numbers.length() == 1 && sum_numbers[0] != '-') {
                    number = stod(sum_numbers); // convert numbers from strings into double
                    fill_matrix.push_back(number); // this matrix will take all the converted numbers
                }
                // the next if condition made for numbers who have negative sign
                else if (sum_numbers.length() == 2) {
                    number = stod(sum_numbers);
                    fill_matrix.push_back(number);
                }
            }
            else {
                sum_numbers.clear();
                /*after every number is in complete form (because the number form after three loops like that
                1 . 2 then we add the three to be 1.2) then we delete the content of the variable
                to store a new number on it*/
            }
        }
    }
}
// the next function put the three small vectors into a vector2D
void fill_vector2D(vector<vector<double>>& matrix, vector<double>& vec1, vector<double>& vec2, vector<double>& vec3) {
    matrix.push_back(vec1);
    matrix.push_back(vec2);
    matrix.push_back(vec3);
}
// the next function take contents of vector2D and put into a 2D_array to be usable in operations
void fill_array2D(double matrix[3][3], vector<vector<double>>mat) {
    for (int i = 0;i < 3;i++) {
        for (int j = 0;j < 3;j++) {
            matrix[i][j] = mat[i][j];
        }
    }
}
