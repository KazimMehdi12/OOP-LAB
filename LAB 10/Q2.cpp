#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
	ifstream inputfile("vehicles.txt");
	if(!inputfile.is_open()) {
		cout<<"Error in opening file"<<endl;
		return 1;
	}

	string line;
	while(getline(inputfile, line)) {
		if (line[0] == '#' || line.empty()) {
			continue;
		}

		string type = "", id = "", make = "", year = "", seats = "";
		int field = 0;
		string temp = "";

		for(int i = 0; i <= line.length(); i++) {
			if(line[i] == ',' || i == line.length()) {
				if (field == 0) {
					type = temp;
				} 
				else if(field == 1) {
					id = temp;
				} 
				else if (field == 2) {
					make = temp;
				} 
				else if (field == 3) {
					year = temp;
				} 
				else if (field == 4) {
					seats = temp;
				}
				temp = "";
				field++;
			} 
			else {
				temp += line[i];
			}
		}

		cout<<"Type: "<<type<<", ID: "<<id<<", Make: "<<make
		     <<", Year: "<<year<<", Seats: "<<seats<<endl;
	}

	inputfile.close();
	return 0;
}
