#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream inputfile("vehicles.txt");
	if(!inputfile.is_open()) {
		cout<<"Error opening file"<<endl;
		return 1;
	}

	string line;
	while(getline(inputfile, line)) {
		if(line[0] == '#' || line.empty()) {
			continue;
		}

		string type, id, make, year, seats;
		int pos;

		pos = line.find(',');
		type = line.substr(0, pos);
		line = line.substr(pos + 1);

		pos = line.find(',');
		id = line.substr(0, pos);
		line = line.substr(pos + 1);

		pos = line.find(',');
		make = line.substr(0, pos);
		line = line.substr(pos + 1);

		pos = line.find(',');
		year = line.substr(0, pos);
		seats = line.substr(pos + 1);

		cout<<"Type: "<<type<<", ID: "<<id<<", Make: "<<make
		    <<", Year: "<<year<<", Seats: "<<seats<<endl;
	}

	inputfile.close();

}
