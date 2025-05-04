#include<iostream>
#include<fstream>
#include<string>

int main(){
    std::ofstream outFile("data_records.txt");
    outFile<<"Record 1"<<endl;
    outFile<<"Record 2"<<endl;
    outFile<<"Record 3"<<endl;
    outFile<<"Record 4"<<endl;
    outFile.close();

    std::ifstream inFile("data_records.txt");
    if(!inFile){
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    inFile.seekg(13, std::ios::beg); 

    std::string record;
    std::getline(inFile, record);
    std::cout << "Third record: " << record << std::endl;

    inFile.close();
    
}
