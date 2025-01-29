#include<iostream>
#include<string>
using namespace std;

const int max_part = 5;
const int donation = 10;
int countOfEvent1=0;
int countOfEvent2=0;
string event1[max_part];
string event2[max_part];

void Registration(){
	cout<<"Regester For Event 1 : "<<endl;
	for(int i=0 ; i<max_part ; i++){
		cout<<"Enter Name "<<(i+1)<<": ";
		cin>>event1[i];
		countOfEvent1 ++ ;
	}   cout<<endl;
	
	cout<<"Regester For Event 2 :"<<endl;
	for(int i=0 ; i<max_part ; i++){
		cout<<"Enter Name "<<(i+1)<<": ";
		cin>>event2[i];
		countOfEvent2 ++ ;
	}  
}

void AttendenceChecker(){
	string check;
	cout<<"Enter Name To Check Registration: ";
	cin>>check;
	
	for(int i=0 ; i<countOfEvent1 ; i++){
		if(event1[i] == check){
			cout<<"Registered in 1st Event"<<endl<<endl;
			return;
		}
	}
	for(int i=0 ; i<countOfEvent2 ; i++){
		if(event2[i]==check){
			cout<<"Registered in 2nd Event"<<endl<<endl;
			return;
		}
	}
	    cout<<"Not Registered "<<endl<<endl;
	
}

void TotalDonation(){
	int total = (countOfEvent1 + countOfEvent1)*donation;
	cout<<"The Total Donation is :"<<total<<endl<<endl;
} 

void Reverse(){
	cout<<"Registered Names of Event 1 In Reverse :"<<endl;
	for(int i= (countOfEvent1 - 1) ; i>=0 ; i--){
		cout<<event1[i]<<endl;
	}   
	cout<<"Registered Names of Event 2 In Reverse :"<<endl;
	for(int i= (countOfEvent2 - 1) ; i>=0 ; i--){
		cout<<event2[i]<<endl;
	}   cout<<endl;
}

void BarChart(){
	cout<<"Popularity Bar Chart For Event 1:"<<endl;
	for(int i=0 ; i<countOfEvent1 ; i++){
		cout<<"*"<<endl; 
	}
	cout<<"Popularity Bar Chart For Event 2:"<<endl;
	for(int i=0 ; i<countOfEvent2 ; i++){
		cout<<"*"<<endl; 
	}
}

int main(){
	Registration();
	AttendenceChecker();
	TotalDonation();
	Reverse();
	BarChart();
}
