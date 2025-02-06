#include<iostream>
#include<string>
using namespace std;

void Allocation(int** &matrix, int rows, int cols){
    matrix = new int*[rows];
    for(int i=0; i<rows; i++){
        matrix[i] = new int[cols];
    }    
}    

void INPUT(int** matrix, int rows, int cols){
    for (int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cout<<"Enter Element ["<<i+1<<"]["<<j+1<<"]: ";
            cin>>matrix[i][j];
        }
    } 
}

void ADDITION(int** mat1, int** mat2, int** result, int rows, int cols){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }   
}

void SUBTRACTION(int** mat1, int** mat2, int** result, int rows, int cols){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void DISPLAY(int** matrix, int rows, int cols){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cout << matrix[i][j]<<" ";
        }   cout<<endl;
    }
}

void deallocateMatrix(int** &matrix, int rows){
    for(int i=0; i<rows; i++){
        delete[] 
		matrix[i];
    }   delete[] matrix;
}
				
int main(){
    int rows, cols;
    cout<<"Enter Number Of Rows: ";
    cin>>rows;
    cout<<"Enter Number Of Columns: ";
    cin>>cols;

    int** mat1;
    int** mat2;
    int** sum;
    int** diff;
    Allocation(mat1, rows, cols);
    Allocation(mat2, rows, cols);
    Allocation(sum, rows, cols);
    Allocation(diff, rows, cols);

    cout<<"Enter Elements For 1st Matrix: "<<endl;
    INPUT(mat1, rows, cols);
    cout<<"Enter Elements For 2nd Matrix: "<<endl;
    INPUT(mat2, rows, cols);

    ADDITION(mat1, mat2, sum, rows, cols);
    SUBTRACTION(mat1, mat2, diff, rows, cols);
    
    cout<<"\nMatrix Addition :"<<endl;
    DISPLAY(sum, rows, cols);
    cout<<"\nMatrix Subtraction :"<<endl;
    DISPLAY(diff, rows, cols);

    deallocateMatrix(mat1, rows);
    deallocateMatrix(mat2, rows);
    deallocateMatrix(sum, rows);
    deallocateMatrix(diff, rows);
    
}
