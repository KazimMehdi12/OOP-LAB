#include<iostream>
using namespace std;

class Student{
    int id;
    string name;
    int* scores;
    int n;

public:
    Student(int i, const string& nm, int* sc, int count){
        id = i;
        name = nm;
        n = count;
        scores = new int[n];
          for(int j=0; j<n; j++){
            scores[j] = sc[j];
        }
    }

    Student(const Student& other){
        id = other.id;
        name = other.name;
        n = other.n;
        scores = new int[n];
          for(int j=0; j<n; j++){
            scores[j] = other.scores[j];
        }
    }

    void display(){
        cout<<"ID: "<<id<<"\nName: "<<name<<"\nScores: ";
          for(int j=0; j<n; j++){
            cout<<scores[j]<<" ";
        }
        cout<<endl;
    }

    ~Student(){
        delete[] scores;
    }
};

int main(){
    int scores[] = {45, 62, 50};
    Student s1(1222, "ALI", scores, 2);
  
    Student s2 = s1;
    
    cout<<"Original Student:"<<endl;
    s1.display();
    cout<<"\nCopied Student:"<<endl;
    s2.display();
    
}
