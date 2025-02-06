#include<iostream>
#include<string>
using namespace std;

struct Employee {
    char name[50];
    int hoursWorked;
    float hourlyRate;
};

void Input(Employee* empl, int count) {
    for(int i=0; i<count; i++) {
        cout<<"\nDetails For Employee: "<<i+1<<endl;
        cout<<"Enter Name: ";
        cin>>empl[i].name;
        cout<<"Enter Hours Worked: ";
        cin>>empl[i].hoursWorked;
        cout<<"Enter Hourly Rate: ";
        cin>>empl[i].hourlyRate;
    }
}

void display(Employee* empl, int count) {
    cout<<"\nEmployee Salary Details: \n";
    for(int i=0; i<count; i++) {
        float totalSalary = empl[i].hoursWorked * empl[i].hourlyRate;
        cout<<"Employee "<<i+1<<" "<<empl[i].name 
            <<": Total Salary : "<<totalSalary<<endl;
    }
}

int main() {
    int n;
    cout<<"Enter The Number Of Employees: ";
    cin >> n;

    Employee* employees = new Employee[n];
    Input(employees, n);
    display(employees, n);

    delete[] employees;

    return 0;
}
