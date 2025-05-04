#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

int main(){
	ifstream inputfile("vehicles.txt");
	if(!inputfile.is_open()){
		cout<<"Error in opening file"<<endl;
		return 1;
	}

	string line;
	while (getline(inputfile, line)){
		if (line[0] == '#' || line.empty()){
			continue;
		}

		stringstream ss(line);
		string type, id, make, yearStr, seats, extraData;

		getline(ss, type, ',');
		getline(ss, id, ',');
		getline(ss, make, ',');
		getline(ss, yearStr, ',');
		getline(ss, seats, ',');
		getline(ss, extraData); 
		int year = stoi(yearStr);

		cout<<"Type: "<<type<<", ID: "<<id<<", Make: "<<make
		    <<", Year: "<<year<<", Seats: "<<seats;

		if(type == "AutonomousCar"){
			int pos = extraData.find(':');
			string value = extraData.substr(pos + 1);
			float softwareVersion = stof(value);
			cout<<", Software Version: "<<softwareVersion;
		} 
		else if(type == "ElectricVehicle"){
			int pos = extraData.find(':');
			string value = extraData.substr(pos + 1);
			int batteryCapacity = stoi(value);
			cout<<", Battery Capacity: "<<batteryCapacity;
		}   cout << endl;
	}
	inputfile.close();

}
