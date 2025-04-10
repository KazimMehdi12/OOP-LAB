#include<iostream>
using namespace std;

class Matrix2x2;
class MatrixHelper{
	public:
		void setElement(Matrix2x2& m, int row, int col, int value);
};

class Matrix2x2{
	private:
		int a, b, c, d;

	public:
		Matrix2x2(int a1=0, int b1=0, int c1=0, int d1=0){
			a = a1;
			b = b1;
			c = c1;
			d = d1;
		}

		Matrix2x2 operator+(const Matrix2x2& m) 
		const{
			return Matrix2x2(a+m.a, b+m.b, c+m.c, d+m.d);
		}

		Matrix2x2 operator-(const Matrix2x2& m) 
		const{
			return Matrix2x2(a-m.a, b-m.b, c-m.c, d-m.d);
		}

		Matrix2x2 operator*(const Matrix2x2& m) 
		const{
			int aa = a*m.a+b*m.c;
			int bb = a*m.b+b*m.d;
			int cc = c*m.a+d*m.c;
			int dd = c*m.b+d*m.d;
			return Matrix2x2(aa, bb, cc, dd);
		}

		friend int determinant(const Matrix2x2& m);
		friend ostream& operator<<(ostream& out, const Matrix2x2& m);
		friend class MatrixHelper;
};

  void MatrixHelper::setElement(Matrix2x2& m, int row, int col, int value) {
	if(row==0 && col==0){
		m.a = value;
	}
	else if(row==0 && col==1){
		m.b = value;
	}
	else if(row==1 && col==0){
		m.c = value;
	}
	else if(row==1 && col==1){
		m.d = value;
	}
}

  int determinant(const Matrix2x2& m){
	  return (m.a * m.d - m.b * m.c);
}

  ostream& operator<<(ostream& out, const Matrix2x2& m){
	out<<"["<<m.a<<" "<<m.b<<"]"<<endl;
	out<<"["<<m.c<<" "<<m.d<<"]";
	return out;
}

int main() {
	Matrix2x2 m1(1, 2, 3, 4);
	Matrix2x2 m2(5, 6, 7, 8);

	Matrix2x2 add = m1 + m2;
	Matrix2x2 sub = m1 - m2;
	Matrix2x2 mul = m1 * m2;

	cout<<"Matrix 1:\n"<<m1<<endl;
	cout<<"Matrix 2:\n"<<m2<<endl;
	cout<<"Addition:\n"<<add<<endl;
	cout<<"Subtraction:\n"<<sub<<endl;
	cout<<"Multiplication:\n"<<mul<<endl;

	int det = determinant(m1);
	cout<<"Determinant of Matrix 1: "<<det<<endl;

	MatrixHelper helper;
	helper.setElement(m1, 0, 0, 9);
	cout<<"Updating m1[0][0] to 9:\n"<<m1<<endl;
}
