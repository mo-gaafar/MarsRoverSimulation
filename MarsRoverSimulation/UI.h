#pragma once
//#include"MarsStation.h"
#include<iostream>
#include<fstream>
using namespace std;
class UI {
	//MarsStation* marsstaion;
	int EmRoverCount, PolarRoverCount;
	int EmSpeed, PolarSpeed;
	int EmCheck, PolarCheck, CheckCount;
	int NumberOFEvents;
	char* EventType, * MissionType;
	int* EventDay, * ID, * location, * Duration, * Signifiance;


	void createRovers();

public:
	void read();
	int getEmRoverCount() {
		return EmRoverCount;
	}
	int getPolarRoverCount() {
		return PolarRoverCount;
	}
	int getEmSpeed() {
		return EmSpeed;
	}
	int getPolarSpeed() {
		return PolarSpeed;
	}
	int getEmCheck() {
		return EmCheck;
	}
	int getPolarCheck() {
		return PolarCheck;
	}
	int getCheckCount()
	{
		return CheckCount;
	}
	int getNumberOFEvents() {
		return NumberOFEvents;
	}
	int* getID() {
		return ID;
	}
	char* getMissionType() {
		return MissionType;
	}
	char* getEventType() {
		return EventType;
	}
	int* getEventDay() {
		return EventDay;
	}
	int* getlocation() {
		return location;
	}
	int* getDuration() {
		return Duration;
	}
	int* getSignifiance() {
		return Signifiance;
	}
};