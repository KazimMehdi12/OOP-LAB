#include<iostream>
#include<fstream>
using namespace std;

int main(){
	ofstream outFile("sensor_log.txt");

	if(!outFile){
		cout << "Error in opening file"<<endl;
		return 1;
	}

	outFile<<"Temperature: 24.5 C\n";
	streampos pos1 = outFile.tellp();
	cout<<"Write position after first line: "<<pos1<<endl;

	outFile<<"Humidity: 60% \n";
	streampos pos2 = outFile.tellp();
	cout<<"Write position after 2nd line: "<<pos2<<endl;

	outFile<<"Pressure: 101.3 kpa\n";
	streampos pos3 = outFile.tellp();
	cout<<"Write position after 3rd line: "<<pos3<<endl;

	outFile.close();

}
