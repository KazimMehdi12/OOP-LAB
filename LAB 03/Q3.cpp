#include<iostream>
using namespace std;

class Library{
  private:
	string List[50];
    string borrowedBooks[50];
    int totalBooks;
    int borrowedCount;

  public:
    void Initialize(){
        totalBooks = 0;
        borrowedCount = 0;
    }

    void addBook(string bookName){
        if(totalBooks < 50){
            List[totalBooks] = bookName;
            totalBooks++;
        }
    }

    void Lend(string bookName){
      for(int i=0; i<totalBooks; i++){
          if(List[i] == bookName){
              borrowedBooks[borrowedCount] = bookName;
              borrowedCount++;
                for(int j=i; j<totalBooks-1; j++){
                  List[j] = List[j+1];
                }   totalBooks-- ;
                return;          }  
            }
    }

    void returnBook(string bookName){
        if (borrowedCount > 0) {
            List[totalBooks] = bookName;
            totalBooks++;
            borrowedCount--;
        }
    }

    void Display(){
        cout<<"Available Books Are :"<<endl;
        for(int i=0; i<totalBooks; i++) {
            cout<<List[i]<<endl;
        }   cout<<endl;
    }
};

int main(){
    Library hamza;
    hamza.Initialize();
    hamza.addBook("C++ OOP");
    hamza.addBook("Java");
    hamza.Display();
    
    hamza.Lend("C++ OOP");
    hamza.Display();
    hamza.returnBook("C++ OOP");
    hamza.Display();

}
