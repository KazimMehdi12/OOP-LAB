#include<iostream>
#include<fstream>

int main(){
    std::ofstream outFile("config.txt");
    outFile << "AAAAA" << "BBBBB" << "CCCCC";
    outFile.close();

    std::fstream file("config.txt", std::ios::in | std::ios::out);
    if(!file){
        std::cerr<<"Error in opening the file"<<std::endl;
        return 1;
    }

    file.seekp(5, std::ios::beg);
    file.write("XXXXX", 5);
    file.close();

    std::ifstream inFile("config.txt");
    if(!inFile){
        std::cerr<<"Error in opening the file"<<std::endl;
        return 1;
    }

    std::string content((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
    std::cout<<"Updated file content: "<<content<<std::endl;

    inFile.close();
    return 0;
}
