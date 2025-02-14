#include<iostream>
using namespace std;

class FitnessTracker{
  private:
     string userName;
     int dailyStepGoal;
     int stepsTaken;
     int caloriesBurned;

  public:
    void setter(string n, int g){
        userName = n;
        dailyStepGoal = g;
        stepsTaken = 0;
        caloriesBurned = 0;
    }

    void logSteps(int steps){
        stepsTaken += steps;
        caloriesBurned += steps/20;
    }

    void Display(){
        cout<<"User Name: "<<userName<<endl;
        cout<<"Goal Of Daily Step: "<<dailyStepGoal<<endl;
        cout<<"Taken Steps: "<<stepsTaken<<endl;
        cout<<"Burned Calories: "<<caloriesBurned<<endl;
        if(stepsTaken >= dailyStepGoal){
            cout<<"Goal Achieved "<<endl;
        } 
		else {
            cout<<"You need "<<(dailyStepGoal - stepsTaken)<<" more steps"<<endl<<endl;
        }
    }
};

int main(){
    FitnessTracker laiba;
    laiba.setter("Laiba", 3000);
    laiba.logSteps(1000);
    laiba.Display();
    
    laiba.logSteps(1500);
    laiba.Display();
    
    return 0;
}
