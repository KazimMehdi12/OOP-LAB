#include<iostream>
#include<string>
using namespace std;

const int cities = 4;
const int days = 7;
int AQI[cities][days];

void InputAQI(){
	cout<<"Enter AQI Values :"<<endl;
	for(int i=0 ; i<cities ; i++){
	  for(int j=0 ; j<days ; j++){
		 cout<<"City:"<<(i+1)<<"  Day:"<<(j+1)<<": ";
		 cin>>(AQI[i][j]);
	}   
	     cout<<endl;
    } 
}

void Average_WorstDay(){
  float Average;
  float worstCity = 0;
  float maxAvg = 0;
    cout<<"Weekly Average is :"<<endl;
	for(int i=0 ; i<cities ; i++){
		float sum = 0;
	    for(int j=0 ; j<days ; j++){
	  	sum += AQI[i][j];
    } 
        Average = sum / days ;
        cout<<"Average of Week "<<i+1<<": "<<Average<<endl;
        
        if (Average > maxAvg) { 
            maxAvg = Average;
            worstCity = i; 
        }
    }    cout<<endl;
    cout<<"\nWorst City: "<<worstCity+1<<" And Its Average: "<<maxAvg<<endl<<endl;
}

void PollutionDays(){
    cout<<"Critical Pollution Days: "<<endl;
    for(int i = 0; i < cities; i++) {
        for (int j = 0; j < days; j++) {
            if (AQI[i][j] > 150) {
                cout<<"City "<< i+1<<" Day "<<j+1<<" AQI: "<<AQI[i][j]<<endl;
            }
        }
    } 
}

void visualization(){
    cout<<"\nAQI Visualization "<<endl;
    for (int i=0; i<cities; i++) {
        cout<<"City "<<i+1<<": ";
        for (int j=0; j<days; j++) {
            for (int k=0; k<AQI[i][j] / 50; k++) {
                cout<<"*";
            }
            cout<<" ";  
        } 
        cout<<endl;
    }   cout<<endl;
}

void MontlyAverage(){
	int month=28;
	float average;
	cout<<"Montly Average is:"<<endl;
	for(int i=0 ; i<cities ; i++){
		float sum = 0;
	    for(int j=0 ; j<days ; j++){
	  	sum += AQI[i][j];
    } 
        average = sum / month;
        cout<<"Average is: "<<average<<endl;
    }
}

void AQIComparison() {
    int highestAQI = AQI[0][0], lowestAQI = AQI[0][0];

    for(int i=0; i<cities; i++) {
        for(int j=0; j<28; j++) {
            if(AQI[i][j] > highestAQI) {
                highestAQI = AQI[i][j];
           }
            if(AQI[i][j] < lowestAQI && AQI[i][j] > 0) { 
                lowestAQI = AQI[i][j];
            }
        }
    }
    cout<<"Highest AQI: "<<highestAQI<<endl;
    cout<<"Lowest AQI: "<<lowestAQI<<endl<<endl;
}

void mostImprovedCity() {
    int impr, maxImpr = 0, imprCity = 0;

    for(int i=0; i<cities; i++) {
        int firstWeek = 0, lastWeek = 0;

        for(int j = 0; j < 7; j++) firstWeek += AQI[i][j];    
        for(int j =21; j<28; j++) lastWeek += AQI[i][j]; 

        int improvement = (firstWeek / 7) - (lastWeek / 7);
        if(impr > maxImpr) {
            maxImpr = impr;
            imprCity = i;
        }
    }
   cout<<"City "<<imprCity+1<<" With drop of "<<maxImpr<<endl;
}


void GenerateReport(){
	Average_WorstDay();
	PollutionDays();
	AQIComparison();
}

int main(){
	InputAQI(); 
  GenerateReport();
	visualization();
	MontlyAverage();
  mostImprovedCity();
}
