#include<iostream>
using namespace std;

class Patient{
protected:
    string name;
    string id;

public:
    Patient(string n, string i){
        name = n;
        id = i;
    }

    virtual void displayTreatment() = 0;
    virtual void calculateCost() = 0;
};

class InPatient : public Patient{
public:
    InPatient(string n, string i) : Patient(n, i){}

    void displayTreatment(){
        cout<<"InPatient: "<<name<<endl;
    }

    void calculateCost(){
        cout << "Cost: 4000" << endl;
    }
};

class OutPatient : public Patient {
public:
    OutPatient(string n, string i) : Patient(n, i){}

    void displayTreatment(){
        cout << "OutPatient: " << name << endl;
    }

    void calculateCost(){
        cout << "Cost: 5000" << endl;
    }
};

int main() {
    Patient* p1 = new InPatient("Kazim", "A1");
    Patient* p2 = new OutPatient("Ali", "A2");

    p1->displayTreatment();
    p1->calculateCost();

    p2->displayTreatment();
    p2->calculateCost();
}
