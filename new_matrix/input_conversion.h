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

void operations_in_input(string data, string sum_numbers, vector<double>& fill_matrix, double number) {
    /* in the next loop, we will loop through the input and check every character, we only need
        the number characters and we will ignore the ; and A and [], just we will take numbers and convert
        them into double*/
    int found1{}, found2{};
    found1 = data.find('[');
    found2 = data.find(']');
    string edited_data = data.substr(found1 + 1, found2 - (found1 + 1));
    for (auto sub_data : edited_data) {
        if (isspace(sub_data) != 0 || sub_data == ';') {
            number = stod(sum_numbers); // convert numbers from strings into double
            fill_matrix.push_back(number);
            sum_numbers.clear();// this matrix will take all the converted numbers
        }
        else {
            sum_numbers += sub_data;
                /*after every number is in complete form (because the number form after three loops like that
                1 . 2 then we add the three to be 1.2) then we delete the content of the variable
                to store a new number on it*/
        }
    }
    number = stod(sum_numbers);
    fill_matrix.push_back(number);
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
