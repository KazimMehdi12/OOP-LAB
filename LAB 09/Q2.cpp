#include<iostream>
using namespace std;

class MenuItem{
    protected:
       string dishName;
	   double price;
	   
	public:
	   MenuItem(string DN , double pr){
	   	dishName = DN;
	   	price = pr;
	   }
	  
	   virtual void showDetails() = 0;
	   virtual void prepare() = 0;	
};

class Appetizer : public MenuItem{
    public:
	     Appetizer(string DN , double pr) :  MenuItem(DN , pr) {}
	     
	     void showDetails(){
	     	cout<<"Appertizer: "<<dishName<<endl;
	     	cout<<"Prize: "<<price<<endl;
		 } 
		 void prepare(){
		 	cout<<"Preparing Appertizer"<<endl;
		 	cout<<"steps....."<<endl;
		 }
};

class MainCourse : public MenuItem{
	public:
		MainCourse(string DN , double pr) :  MenuItem(DN , pr) {}
        
         void showDetails(){
	     	cout<<"Main Course: "<<dishName<<endl;
	     	cout<<"Prize: "<<price<<endl;
		 } 
		 void prepare(){
		 	cout<<"Preparing main course: "<<dishName<<endl;
		 	cout<<"steps.....";
		 }

}; 

int main(){
	MenuItem* d1 = new Appetizer("Roll", 350);
    MenuItem* d2 = new MainCourse("Chicken", 1150);

    d1->showDetails();
    d1->prepare();
    cout << endl;
    d2->showDetails();
    d2->prepare();

    delete d1;
    delete d2;

}
