#include<iostream>
using namespace std;

class Ticket{
	protected:
		int ticketID;
		string passengerName;
		double price;
		string date;
		string destination;

	public:
		void setDetails(int id, string name, double p, string d, string dest){
			ticketID = id;
			passengerName = name;
			price = p;
			date = d;
			destination = dest;
		}

		void displayTicketInfo(){
			cout<<"Ticket ID: "<<ticketID<<"\nPassenger: "<<passengerName<<endl;
			cout<<"Price: "<<price<<"\nDate: "<<date<<"\nDestination: "<<destination<<endl;
		}
};

class FlightTicket : public Ticket{
	string airlineName;
	string flightNumber;
	string seatClass;

	public:
		void setFlightDetails(string airline, string flight, string seat){
			airlineName = airline;
			flightNumber = flight;
			seatClass = seat;
		}
		void displayTicketInfo(){
			Ticket::displayTicketInfo();
			cout<<"Airline: "<<airlineName<<"\nFlight Number: "<<flightNumber<<"\nSeat Class: "<<seatClass<<endl;
		}
};

class TrainTicket : public Ticket{
	int trainNumber;
	string coachType;
	string departureTime;

	public:
		void setTrainDetails(int train, string coach, string time){
			trainNumber = train;
			coachType = coach;
			departureTime = time;
		}
		void displayTicketInfo(){
			Ticket::displayTicketInfo();
			cout<<"Train Number: "<<trainNumber<<"\nCoach Type: "<<coachType;
			cout<<"\nDeparture Time: "<<departureTime<<endl;
		}
};

class BusTicket : public Ticket{
	string busCompany;
	string seatNumber;

	public:
		void setBusDetails(string company, string seat){
			busCompany = company;
			seatNumber = seat;
		}
		void displayTicketInfo(){
			Ticket::displayTicketInfo();
			cout<<"Bus Company: "<<busCompany<<"\nSeat Number: "<<seatNumber<<endl;
		}
};

class ConcertTicket : public Ticket{
	string artistName;
	string venue;
	string seatType;

	public:
		void setConcertDetails(string artist, string v, string seat){
			artistName = artist;
			venue = v;
			seatType = seat;
		}
		void displayTicketInfo(){
			Ticket::displayTicketInfo();
			cout<<"Artist: "<<artistName<<"\nVenue: "<<venue<<"\nSeat Type: "<<seatType<<endl;
		}
};

int main(){
	FlightTicket f;
	f.setDetails(101, "Ali", 4500, "20/03/2025", "Islamabad");
	f.setFlightDetails("PIA", "XY2", "Economy");
	f.displayTicketInfo();
	cout<<endl;

	TrainTicket t;
	t.setDetails(202, "Kazim", 3500, "25/03/2025", "Lahore");
	t.setTrainDetails(567, "Sleeper", "08:00 AM");
	t.displayTicketInfo();
	cout<<endl;

	BusTicket b;
	b.setDetails(303, "Ahmed", 3000, "30/03/2025", "Multan");
    b.setBusDetails("Faisal Movers", "C10");
	b.displayTicketInfo();
	cout<<endl;

	ConcertTicket c;
	c.setDetails(404, "Abdullah", 2000, "15/04/2025", "Alhamra Hall Lahore");
    c.setConcertDetails("Atif Aslam", "Expo Center Karachi", "VIP");
	c.displayTicketInfo();

}
