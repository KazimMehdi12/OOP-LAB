#include<iostream>
#include<string>
using namespace std;

int main(){
    int row1, col1, row2, col2;
    cout<<"Enter Rows and Columns For (1st Mat): ";
    cin>>row1>>col1;
    cout<<"Enter Rows and Columns For (2nd Mat): ";
    cin>>row2>>col2;
    
    int** a = new int*[row1];
    for(int i=0; i<row1; i++){
    	 a[i] = new int[col1];
	}
    int** b = new int*[row2];
    for(int i=0; i<row2; i++){
    	b[i] = new int[col2];
	}
    int** res = new int*[row1];
    for(int i=0; i<row1; i++){
	    res[i] = new int[col2]{};
    }
    cout<<"Enter elements of first matrix:\n";
    for(int i=0; i<row1; i++){
        for(int j=0; j<col1; j++){
            cout<<"Element ["<<i+1<<"]["<<j+1<<"]: ";
            cin>>a[i][j];
        }
  }
    cout<<"Enter elements of second matrix:\n";
    for(int i=0; i<row2; i++){
        for(int j=0; j<col2; j++){
            cout<<"Element ["<<i+1<<"]["<<j+1<<"]: ";
            cin>>b[i][j];
        }
  }   
    for(int i=0; i<row1; i++){
        for(int j=0; j<col2; j++){
            for(int k=0; k<col1; k++){
                res[i][j] += a[i][k] * b[k][j];
        }       } 
 }
    cout<<"Results is: "<<endl;
    for(int i=0; i<row1; i++){
        for(int j=0; j<col2; j++) {
            cout<<res[i][j]<<" ";
        }
        cout << endl;
    }
    
    for(int i=0; i<row1; i++){
    	delete[] a[i];
	}
        delete[] a;
    for(int i=0; i<row2; i++){
    	delete[] b[i];
	}
        delete[] b;
    for(int i=0; i<row1; i++){
    	delete[] res[i];
	}
        delete[] res;
}
