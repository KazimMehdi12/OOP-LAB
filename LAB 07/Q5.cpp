#include <iostream>
using namespace std;

class Character{
	protected:
		int characterID;
		string name;
		int level;
		int healthPoints;
		string weaponType;

	public:
		void setDetails(int id, string n, int l, int hp, string wt){
			characterID = id;
			name = n;
			level = l;
			healthPoints = hp;
			weaponType = wt;
		}

		virtual void displayStats(){
			cout<<"Character ID: "<<characterID<<"\nName: "<<name<<endl;
			cout<<"Level: "<<level<<"\nHealth Points: "<<healthPoints<<endl;
			cout<<"Weapon: "<<weaponType<<endl;
		}

		virtual void attack(){
			cout<<name<<" attacks with "<<weaponType<<endl;
		}

		virtual void defend(){
			cout<<name<<" defends"<<endl;
		}
};

class Warrior : public Character{
		int armorStrength;
		int meleeDamage;

	public:
		void setWarriorDetails(int as, int md){
			armorStrength = as;
			meleeDamage = md;
		}
		void attack() override{
			cout<<name<<" strikes with "<<weaponType<<endl;
		}
};

class Mage : public Character{
		int manaPoints;
		int spellPower;

	public:
		void setMageDetails(int mp, int pwr){
			manaPoints = mp;
			spellPower = pwr;
		}
		void defend() override{
			cout<<name<<" casts shield"<<endl;
		}
};

class Archer : public Character{
		int arrowCount;
		int rangedAccuracy;

	public:
		void setArcherDetails(int arr, int acc){
			arrowCount = arr;
			rangedAccuracy = acc;
		}
		void attack() override{
			cout<<name<< " shoots an arrow"<<endl;
		}
};

class Rogue : public Character{
		int stealthLevel;
		int agility;

	public:
		void setRogueDetails(int sL, int ag){
			stealthLevel = sL;
			agility = ag;
		}
		void displayStats() override{
			Character::displayStats();
			cout<<"Stealth Level: "<<stealthLevel<<"\nAgility: "<<agility<<endl;
		}
};

int main() {
	Warrior w;
	w.setDetails(1, "Muhammad", 10, 90, "Sword");
	w.setWarriorDetails(50, 20);
	w.displayStats();
	w.attack();
	cout<<endl;

	Mage m;
	m.setDetails(2, "Abdullah", 12, 75, "Hammer");
	m.setMageDetails(100, 30);
	m.displayStats();
	m.defend();
	cout<<endl;

	Archer a;
	a.setDetails(3, "Ahmed", 15, 85, "Axe");
	a.setArcherDetails(30, 85);
	a.displayStats();
	a.attack();
	cout<<endl;

	Rogue r;
	r.setDetails(4, "Ali", 18, 70, "XYZ");
	r.setRogueDetails(90, 95);
	r.displayStats();

}
