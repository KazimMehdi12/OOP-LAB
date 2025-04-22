#include<iostream>
using namespace std;

class Shipment{
	protected:
		string trackingNumber;
		double weight;
	public:
		Shipment(string tNum, double w){
			trackingNumber = tNum;
			weight = w;
		}

		virtual void estimateDeliveryTime() = 0;
		virtual void showDetails() = 0;
};

class AirFreight : public Shipment{
	public:
		AirFreight(string tNum, double w) : Shipment(tNum, w){}

		void estimateDeliveryTime(){
			cout<<"Estimated Time - AIR : 1-2 days"<<endl;
		}

		void showDetails(){
			cout<<"Air Freight Shipment"<<endl;
			cout<<"Tracking Number: "<<trackingNumber<<endl;
			cout<<"Weight: "<<weight<<endl;
		}
};

class GroundShipment : public Shipment{
	public:
		GroundShipment(string tNum, double w) : Shipment(tNum, w){}

		void estimateDeliveryTime(){
			cout<<"Estimated Time - Ground : 4-6 days"<<endl;
		}

		void showDetails(){
			cout<<"Ground Shipment"<<endl;
			cout<<"Tracking Number: "<<trackingNumber<<endl;
			cout<<"Weight: "<< weight<<endl;
		}
};

int main(){
	Shipment* s1 = new AirFreight("AIR1", 15.0);
	Shipment* s2 = new GroundShipment("G2", 30.5);

	s1->showDetails();
	s1->estimateDeliveryTime();
	cout<<endl;
	s2->showDetails();
	s2->estimateDeliveryTime();

	delete s1;
	delete s2;
}
