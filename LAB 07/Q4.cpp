#include<iostream>
using namespace std;
class Person{
	protected:
		string name;
		int age;
		string contactNumber;
		string address;

	public:
		void setDetails(string n, int a, string c, string addr){
			name = n;
			age = a;
			contactNumber = c;
			address = addr;
		}

		void displayInfo(){
			cout<<"Name: "<<name<<"\nAge: "<<age<<"\nContact: "<<contactNumber<<"\nAddress: "<<address<<endl;
		}
};

class Patient : public Person{
		int patientID;
		string medicalHistory;
		string doctorAssigned;

	public:
		void setPatientDetails(int id, string history, string doctor){
			patientID = id;
			medicalHistory = history;
			doctorAssigned = doctor;
		}
		void displayInfo(){
			Person::displayInfo();
			cout<<"Patient ID: "<<patientID<<"\nMedical History: "<<medicalHistory
			     <<"\nDoctor Assigned: "<<doctorAssigned<<endl;
		}
};

class Doctor : public Person{
		string specialization;
		double consultationFee;
		string patientsList;

	public:
		void setDoctorDetails(string spec, double fee, string patients){
			specialization = spec;
			consultationFee = fee;
			patientsList = patients;
		}
		void displayInfo(){
			Person::displayInfo();
			cout<<"Specialization: "<<specialization<<"\nConsultation Fee: "<<consultationFee;
			cout<<"\nPatients List: "<<patientsList<<endl;
		}
};

class Nurse : public Person{
		string assignedWard;
		string shiftTimings;

	public:
		void setNurseDetails(string ward, string shift){
			assignedWard = ward;
			shiftTimings = shift;
		}
		void displayInfo(){
			Person::displayInfo();
			cout<<"Assigned Ward: "<<assignedWard<<"\nShift Timings: "<<shiftTimings<<endl;
		}
};

class Administrator : public Person{
		string department;
		double salary;

	public:
		void setAdminDetails(string dept, double sal){
			department = dept;
			salary = sal;
		}
		void displayInfo(){
			Person::displayInfo();
			cout<<"Department: "<<department<<"\nSalary: "<<salary<<endl;
		}
};

int main(){
	Patient p;
	p.setDetails("Ahmed", 30, "03150", "Lahore");
	p.setPatientDetails(101, "Diabetes", "ABC");
	p.displayInfo();
	cout<<endl;

	Doctor d;
	d.setDetails("Muhammad", 32, "03151", "Karachi");
	d.setDoctorDetails("Palmo", 3000, "DEF");
	d.displayInfo();
	cout<<endl;

	Nurse n;
	n.setDetails("Ali", 28, "03152", "Islamabad");
	n.setNurseDetails("ICU", "Night Shift");
	n.displayInfo();
	cout<<endl;

	Administrator a;
	a.setDetails("Kazim", 40, "03154", "Sukkur");
	a.setAdminDetails("XY", 80000);
	a.displayInfo();

}
