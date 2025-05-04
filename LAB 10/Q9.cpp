#include<iostream>
#include<fstream>
#include<string>

int main(){
	std::ofstream outFile("large_log.txt");
	outFile<<"This is the first line of the log file "<<endl;
	outFile<<"This is the second line of the log file "<<endl;
	outFile<<"This is the third line of the log file "<<endl;
	outFile<<"This is the fourth line of the log file "<<endl;
	outFile.close();

	std::ifstream inFile("large_log.txt");
	
	if(!inFile){
		std::cerr<<"Error in opening the file"<<std::endl;
		return 1;
	}

	char buffer[11];
	inFile.read(buffer, 10);
	buffer[10] = '\0';
	std::cout<<"Read first 10 characters: "<<buffer<<std::endl;

	std::streampos position = inFile.tellg();
	std::cout<<"Current read position: "<<position<<std::endl;

	inFile.close();
	return 0;
}
