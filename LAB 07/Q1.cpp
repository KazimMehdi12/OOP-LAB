#include<iostream>
using namespace std;

class Device {
	protected:
		int deviceID;
		string deviceName, status, location;

	public:
		void setData(int id, string name, string loc) {
			deviceID = id;
			deviceName = name;
			location = loc;
			status = "off";
		}

		void turnOn() {
			status = "on";
		}

		void turnOff() {
			status = "off";
		}

		void getStatus() {
			cout<<"Status: "<<status<<endl;
		}

		void displayInfo() {
			cout<<deviceID<<" "<<deviceName<<" ("<<location<<") "<<status<<endl;
		}
};

class Light : public Device {
		int brightnessLevel;
		string colorMode;

	public:
		void setLight(int id, string name, string loc, int bright, string color) {
			setData(id, name, loc);
			brightnessLevel = bright;
			colorMode = color;
		}

		void displayInfo() {
			Device::displayInfo();
			cout<<"Brightness: "<<brightnessLevel<<", Color: "<<colorMode<<endl;
		}
};

class Thermostat : public Device {
		int temperature, targetTemperature;
		string mode;

	public:
		void setThermostat(int id, string name, string loc, int temp, string m, int target) {
			setData(id, name, loc);
			temperature = temp;
			mode = m;
			targetTemperature = target;
		}

		void getStatus() {
			cout<<"Temp: "<<temperature<<", Mode: "<<mode<<", Target: "<<targetTemperature<<endl;
		}
};

class SecurityCamera : public Device {
		string resolution, recordingStatus, nightVisionEnabled;

	public:
		void setCamera(int id, string name, string loc, string res, string nightVision) {
			setData(id, name, loc);
			resolution = res;
			nightVisionEnabled = nightVision;
			recordingStatus = "off";
		}

		void turnOn() {
			status = "on";
			recordingStatus = "recording";
		}

		void displayInfo() {
			Device::displayInfo();
			cout<<"Resolution: "<<resolution<<",  Recording: "<<recordingStatus;
			cout<<", Night Vision: "<<nightVisionEnabled<<endl;
		}
};

class SmartPlug : public Device {
		int powerConsumption, timerSetting;

	public:
		void setPlug(int id, string name, string loc, int power, int timer) {
			setData(id, name, loc);
			powerConsumption = power;
			timerSetting = timer;
		}

		void turnOff() {
			status = "off";
			cout<<"Power usage: "<<powerConsumption<<"W"<<endl;
		}

		void displayInfo() {
			Device::displayInfo();
			cout<<"Power: "<<powerConsumption<<"w, Timer: "<<timerSetting<<" mins"<<endl;
		}
};

int main() {
	Light l;
	l.setLight(1, "Light", "Room", 60, "Warm");
	l.turnOn();
	l.displayInfo();

	Thermostat t;
	t.setThermostat(2, "Thermo", "Living", 25, "Cool", 21);
	t.turnOn();
	t.getStatus();

	SecurityCamera c;
	c.setCamera(3, "Cam", "Gate", "1080p", "Yes");
	c.turnOn();
	c.displayInfo();

	SmartPlug p;
	p.setPlug(4, "Plug", "Kitchen", 1400, 32);
	p.turnOn();
	p.turnOff();
	p.displayInfo();

}
