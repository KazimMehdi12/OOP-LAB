#include<iostream>
#include<string>
using namespace std;

int main(){
    string extraData;
    cout<<"Enter ExtraData string: ";
    cin>>extraData;

    int cargo = 0;
	  int battery = 0;

    if(extraData.find("Cargo:") != string::npos && extraData.find("Battery:") != string::npos){
        size_t colonPos = extraData.find(":");
        size_t pipePos = extraData.find("|");
        size_t secondColonPos = extraData.rfind(":");

        string cargoStr = extraData.substr(colonPos + 1, pipePos - colonPos - 1);
        cargo = stoi(cargoStr);
        string batteryStr = extraData.substr(secondColonPos + 1);
        battery = stoi(batteryStr);

        cout<<"HybridTruck Detected"<<endl;
        cout<<"Cargo: "<<cargo<<endl;
        cout<<"Battery: "<<battery<<endl;
    } 
	else {
        cout<<"Unknown vehicle type"<<endl;
    }

    return 0;
}
