#include<iostream>
#include<exception>
using namespace std;

class DatabaseException : public exception{
	public:
		const char* what() 
		const noexcept override {
			return "A database error occurred";
		}
};

class ConnectionFailedException : public DatabaseException {};  
    // Inherits what() from base
class QueryTimeoutException : public DatabaseException {};

template <typename T>
class DatabaseConnector{
	public:
		void connect(T dbName){
			if(dbName == "invalid_db"){
				throw ConnectionFailedException();
			} 
			else if(dbName == "slow_db"){
				throw QueryTimeoutException();
			} 
			else{
				cout<<"Connected to database: "<<dbName<<endl;
			}
		}
};

int main(){
	DatabaseConnector<string> db;

	try {
		cout<<"Trying to connect to invalid_db"<<endl;
		db.connect("invalid_db");
	} 
	catch (const ConnectionFailedException& e){
		cout<<"Connection failed: "<<e.what()<<endl;
	}

	try{
		cout<<"\nTrying to connect to slow_db"<<endl;
		db.connect("slow_db");
	} 
	catch (const DatabaseException& e){
		cout<<"Database error: "<<e.what()<<endl;
	}

	return 0;
}
