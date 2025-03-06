#include<iostream>
using namespace std;

class Level{
	public:
		int number;
		string name;

		Level(int num, string nm){
			number = num;
			name = nm;
		}

		void display(){
			cout<<"Level "<<number<<": "<<name<<endl;
		}
};

class VideoGame{
	public:
		string title;
		string genre;
		Level* levels[20];
		int count;

		VideoGame(string t, string g){
			title = t;
			genre = g;
			count = 0;
		}

		~VideoGame(){
			for(int i=0; i<count; i++){
				delete levels[i];
			}
		}

		void addLevel(int num, string nm) {
			if(count<20) {
				levels[count++] = new Level(num, nm);
			}
		}

		void display(){
			cout<<"Game: "<<title<<"\nGenre: "<<genre<<"\nLevels:"<<endl;
			   for(int i=0; i<count; i++){
				  levels[i]->display();
			}
		}
};

int main(){
	VideoGame g("PUBG", "Battle Royale");
	
	g.addLevel(1, "Erangel");
	g.addLevel(2, "Miramar");
	g.addLevel(3, "Sanhok");

	g.display();
}
