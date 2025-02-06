#include<iostream>
#include<string>
using namespace std;

struct Book{
	string title;
	string author;
	int year;
};

int main(){
	int n;
	
	cout<<"Enter The Number of Books: ";
	cin>>n;
	
	Book* books = new Book[n];
	
	for(int i=0 ; i<n ; i++){
		cout<<"Enter Deatil for Book "<<i+1<<": "<<endl;
		cout<<"Enter Title: ";
		cin>>books[i].title;
		cout<<"Enter Author Name: ";
		cin>>books[i].author;
		cout<<"Enter The Year: ";
		cin>>books[i].year;
		cout<<endl;
	}
	
	int specific_year;
	cout<<"\nEnter Year For Showing Books Published After It: ";
	cin>>specific_year;
	
	cout<<"Books Published: "<<endl;
	for(int i=0 ; i<n ; i++){
		if(books[i].year > specific_year) {
            cout<<"Title: "<<books[i].title<<"\nAuthor: "<<books[i].author;
            cout<<"\nYear: "<<books[i].year;
        }
	}
	delete[] books;
	
}
