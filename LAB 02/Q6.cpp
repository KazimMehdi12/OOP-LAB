#include<iostream>
using namespace std;

struct Student{
    string name;
    int rollNumber;
    float marks[3];
    float average;
};

void INPUT(Student* students, int n){
    for (int i=0; i<n; i++) {
        cout<<"Details For Student "<<i+1<<endl;
        cout<<"Enter Name: ";
        cin>>students[i].name;
        cout<<"Enter Roll Number: ";
        cin>>students[i].rollNumber;
        float sum = 0;
        for(int j=0; j<3; j++){
            cout<<"Marks in subject "<<j+1<<": ";
            cin>>students[i].marks[j];
            sum += students[i].marks[j];
        }
        students[i].average = sum / 3.0;
    }
}

void DISPLAY(Student* students, int n) {
    cout<<"\nStudent Results:"<<endl<<endl;
    for(int i=0; i<n; i++) {
        cout<<"Name: "<<students[i].name<<endl;
        cout<<"Roll Number: "<<students[i].rollNumber<<endl;
        cout<<"Marks: ";
        for(int j=0; j<3; j++) {
            cout<<students[i].marks[j]<<" ";
        }   
        cout<<"\nAverage Marks: "<<students[i].average<<endl<<endl;
    }
}

int main(){
    int n;
    cout<<"Enter The Number Of Students: ";
    cin>>n;
    
    Student* students = new Student[n];
    
    INPUT(students, n);
    DISPLAY(students, n);
    
    delete[] students;

}
