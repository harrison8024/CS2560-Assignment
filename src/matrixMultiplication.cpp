#include <iostream>
#include <fstream>
using namespace std;

int ** createMatrix(int, int);                      //Int function that creates a matrix by dynamically allocating memory and store in a pointer
void inputMatrix(ifstream &, int**, int, int);      //Void function that gets input from file to fill matrix
void inputMatrix(int**, int, int);                  //Void function that gets input from file to fill matrix
void printMatrix(int**, int, int);                  //Void function that prints out the matrix
void addMatrix(int**, int**, int**, int, int);      //Void function that add two matrices and stroe the result in matrixNew
void subMatrix(int**, int**, int**, int, int);      //Void function that subtract two matrices and stroe the result in matrixNew
void mulMatrix(int**, int**, int**, int, int, int); //Void function that multiplies two matrices and stroe the result in matrixNew

// Main Program
int main(){

    //Variable
    ifstream file("matrixInput.txt") ;
    int rowCount1;
    int colCount1;
    int rowCount2;
    int colCount2;
    int ** matrix1;
    int ** matrix2;
    int ** matrixFinal;
    int option;
    bool endCreateLoop = false;
    bool endFunctionLoop = false;

    //Menu
    while(!endCreateLoop){
        cout << "1. Create Matrix from file.\n";
        cout << "2. Create Matrix from input.\n";
        cout << "Please select a method:";
        cin >> option;
        switch(option){
            case 1:
                // First matrix
                if(file.is_open()){
                    file >> rowCount1;
                    file >> colCount1;
                }
                matrix1 = createMatrix(rowCount1, colCount1);
                inputMatrix(file, matrix1, rowCount1, colCount1);

                // Second matrix
                if(file.is_open()){
                    file >> rowCount2;
                    file >> colCount2;
                }
                matrix2 = createMatrix(rowCount2, colCount2);
                inputMatrix(file, matrix2, rowCount2, colCount2);
                file.close();
                endCreateLoop = true;
                break;
            case 2:
                cout << "Enter number of row:";
                cin >> rowCount1;
                cout << "Enter number of column:";
                cin >> colCount1;
                matrix1 = createMatrix(rowCount1, colCount1);
                inputMatrix(matrix1, rowCount1, colCount1);
                cout << "Enter number of row:";
                cin >> rowCount2;
                cout << "Enter number of column:";
                cin >> colCount2;
                matrix2 = createMatrix(rowCount2, colCount2);
                inputMatrix(matrix2, rowCount2, colCount2);
                endCreateLoop = true;
                break;
        }
    }
    cout << "First Matirx :\n";
    printMatrix(matrix1, rowCount1, colCount1);
    cout << "Second Matrix :\n";
    printMatrix(matrix2, rowCount2, colCount2);
    // Matrix functions
    while(!endFunctionLoop){
        cout << "1. Matrix Multiplication.\n";
        cout << "2. Matrix Addition\n";
        cout << "3. Matrix Subtraction\n";
        cin >> option;
        switch(option){
            case 1:
                if(colCount1 == rowCount2){
                    matrixFinal = createMatrix(rowCount1, colCount2);
                    mulMatrix(matrixFinal, matrix1, matrix2, rowCount1, colCount2, colCount1);
                    cout << "New Matrix:\n";
                    printMatrix(matrixFinal, rowCount1, colCount2);
                } else {
                    cout << "Error: matrices cannot perform multiplication." << endl;
                }
                endFunctionLoop = true;
                break;
            case 2:
                //Matrix validation
                if(rowCount1 == rowCount2 && colCount1 == colCount2){
                    matrixFinal = createMatrix(rowCount1, colCount1);
                    addMatrix(matrixFinal, matrix1, matrix2, rowCount1, colCount1);
                    cout << "New Matrix:\n";
                    printMatrix(matrixFinal, rowCount1, colCount1);
                } else {
                    cout << "Error: matrices cannot perform addition." << endl;
                }
                endFunctionLoop = true;
                break;
            case 3:
                //Matrix validation
                if(rowCount1 == rowCount2 && colCount1 == colCount2){
                    matrixFinal = createMatrix(rowCount1, colCount1);
                    subMatrix(matrixFinal, matrix1, matrix2, rowCount1, colCount1);
                    cout << "New Matrix :\n";
                    printMatrix(matrixFinal, rowCount1, colCount1);
                } else {
                    cout << "Error: matrices cannot perform subtraction." << endl;
                }
                endFunctionLoop = true;
                break;

        }

    }
}

/**
* Int function that creates a matrix by dynamically allocating memory and store in a pointer
* @param row, integer value that specify the row of matrix
* @param col, integer value that specify the column of matrix
*/
int ** createMatrix(int row, int col) {
    int** matrix = new int*[row];
    for(int i = 0; i < row; i++){
        matrix[i] = new int[col];
    }
    return matrix;
}

/**
* Void function that gets input from file to fill matrix
* @param ifstream, a refference of the input file
* @param matrix, integer pointer that points to the matrix
* @param row, integer value that specify the row of matrix
* @param col, integer value that specify the column of matrix
*/
void inputMatrix(ifstream &file, int **matrix, int row, int col) {
    int element;
    if(file.is_open()){
        for(int **i = matrix; i < matrix + row; i++){
            for(int *j = *i; j < *i + col; j++){
                file >> element;
                *j = element;
            }
        }
    }
}

/**
* Void function that gets input from user to fill matrix
* @param matrix, integer pointer that points to the matrix
* @param row, integer value that specify the row of matrix
* @param col, integer value that specify the column of matrix
*/
void inputMatrix(int **matrix, int row, int col) {
    int element;
    for(int **i = matrix; i < matrix + row; i++){
        cout << "Enter " << col << " number(s) in row " << row << ":";
        for(int *j = *i; j < *i + col; j++){
            cin >> element;
            *j = element;
        }
    }  
}

/**
* Void function that add two matrices and stroe the result in matrixNew
* @param matrixNew a pointer of the matrix that will be the result
* @param matrix1 a pointer of the matrix that is being added
* @param matrix2 a pointer of the matrix that is adding
* @param row the number of rows of the matrices
* @param col the number of colums of the matrices
*/
void addMatrix(int** matrixNew, int** matrix1, int** matrix2, int row, int col){
    for(int **i1 = matrix1, **i2 = matrix2 , **inew = matrixNew; i1 < matrix1 + row; i1++, i2++, inew++){
        for(int *j1 = *i1, *j2 = *i2, *jnew = *inew; j1 < *i1 + col; j1++, j2++, jnew++){
            cout << *j1 << " " << *j2 << endl;
            *jnew = *j1 + *j2;
        }
    }
}

/**
* Void function that subtract two matrices and stroe the result in matrixNew
* @param matrixNew a pointer of the matrix that will be the result
* @param matrix1 a pointer of the matrix that is being subtracted
* @param matrix2 a pointer of the matrix that is subtracting
* @param row the number of rows of the matrices
* @param col the number of colums of the matrices
*/
void subMatrix(int** matrixNew, int** matrix1, int** matrix2, int row, int col){
    for(int **i1 = matrix1, **i2 = matrix2 , **inew = matrixNew; i1 < matrix1 + row; i1++, i2++, inew++){
        for(int *j1 = *i1, *j2 = *i2, *jnew = *inew; j1 < *i1 + col; j1++, j2++, jnew++){
            cout << *j1 << " " << *j2 << endl;
            *jnew = *j1 - *j2;
        }
    }
}

/**
* Void function that multiplies two matrices and stroe the result in matrixNew
* @param matrixNew a pointer of the matrix that will be the result
* @param matrix1 a pointer of the matrix that is being multiplied
* @param matrix2 a pointer of the matrix that is multipling
* @param row the number of rows of the new matrix
* @param col the number of colums of the new matrix
* @param join the number of rows/colums of the old matrix
*/
void mulMatrix(int** matrixNew, int** matrix1, int** matrix2, int row, int col, int join) {
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            for(int k = 0; k < join; k++){
                *(*(matrixNew + i) + j) += *(*(matrix1 + i) + k) * (*(*(matrix2 + k) + j));
            }
        }
    }
}

/**
* Void function that prints out the matrix
* @param matrix a pointer of the matrix to be printed
* @param row the number of rows of the matrix
* @param col the number of colums of the matrix
*/
void printMatrix(int **matrix, int row, int col) {
    for(int **i = matrix; i < matrix + row; i++){
            for(int *j = *i; j < *i + col; j++){
                cout << *j << " ";
            }
            cout << "\n";
        }
}

