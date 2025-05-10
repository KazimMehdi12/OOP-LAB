#include<iostream>
#include<exception>
using namespace std;

class DimensionMismatchException : public exception{
	public:
		const char* what() const noexcept override{
			return "DimensionMismatchException - Matrices must have same dimensions";
		}
};

template <typename T>
class Matrix{
	private:
		int rows, cols;
		T** data;

	public:
		Matrix(int r, int c){
			rows = r;
			cols = c;
			data = new T*[rows];
			for(int i=0; i<rows; i++){
				data[i] = new T[cols];
			}
		}

		void input(){
			for(int i=0; i<rows; i++) {
				for(int j=0 ; j<cols; j++){
					cin>>data[i][j];
				}
			}
		}

		void display() 
		const{
			for(int i=0; i<rows; i++) {
				for(int j=0; j<cols; j++){
					cout<<data[i][j]<<" ";
				}   cout << endl;
			}
		}

		Matrix<T> operator+(const Matrix<T>& other){
			if(rows != other.rows || cols != other.cols){
				throw DimensionMismatchException();
			}
			Matrix<T> result(rows, cols);
			for(int i=0; i<rows; i++){
				for (int j=0; j<cols; j++){
					result.data[i][j] = data[i][j] + other.data[i][j];
				}
			}       return result;
		}

		~Matrix(){
			for(int i=0; i<rows; i++) {
				delete[] data[i];
			}
			delete[] data;
		}
};

int main(){
	try{
		Matrix<int> A(2, 2);
		Matrix<int> B(2, 3);

		cout<<"Enter elements for Matrix A - 2x2:"<<endl;
		A.input();

		cout<<"Enter elements for Matrix B - 2x3:"<<endl;
		B.input();

		Matrix<int> C = A+B;
		C.display();
	} 
	catch (const exception& e){
		cout<<e.what() <<endl;
	}

	return 0;
}
