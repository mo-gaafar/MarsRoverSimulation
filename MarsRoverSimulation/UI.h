#pragma once
#include"MarsStation.h"
#include<fstream>
class UI {
	MarsStation* marsstaion;
	int emerrovercount, polrrovercount;
	int emerspeed, polrspeed;
	int emercheck, polrcheck, checkcount;
	int noevents;
	char eventtype, missiontype;
	int eventDay, ID, location, duration, signifiance;

	void read();
	void createRovers();




};