#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Vehicles{
		ifstream file;
		string line;
	public:
		void readFile(){
		   file.open("vehicles.txt");

		   if(!file.is_open()){
			 cout<<"Error: File not opened"<<endl;
			 return;
			}
		   while(getline(file, line)){
			  if(line[0] == '#' || line.empty()){
			  continue;
			}
			   cout<<"Line: "<<line<<endl;
			}

		    file.close();
		}
};

int main(){
	Vehicles v1;
	v1.readFile();
	return 0;
	
}
