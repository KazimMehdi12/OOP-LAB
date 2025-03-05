#include<iostream>
using namespace std;

class Apartment{
  private:
    int id;
    string address;
    string* owner;

  public:
    Apartment(int i, const string& adr, const string& ow){
        id = i;
        address = adr;
        owner = new string(ow);
    }

    Apartment(const Apartment& other){
        id = other.id;
        address = other.address;
        owner = other.owner;
    }

    void display(){
        cout<<"ID: "<<id<<"\nAddress: "<<address<<"\nOwner: "<<(*owner)<<"\n";
    }

    ~Apartment(){
        delete owner;
    }
};

int main(){
    Apartment a1(83, "DHA Phase 2", "ALI");
    Apartment a2 = a1;
    
    cout<<"Original Apartment:"<<endl;
    a1.display();
    cout<<"\nCopied Apartment:"<<endl;
    a2.display();
    
}
