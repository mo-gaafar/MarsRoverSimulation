#include"UI.h"
void UI::read() {
	ifstream input;
	input.open("ay 7aga.txt");
	if (input.fail()) {
		cerr << "error opening file" << endl;
		exit(1);
	}
	input >>  polrrovercount>> emerrovercount;
	marsstaion->setemercount(emerrovercount);
	marsstaion->setpolrcount(polrrovercount);
	input >> polrspeed;
	input >> emerspeed;	
	input >> checkcount >> polrcheck >> emercheck;
	createRovers();
	input >> noevents;
	marsstaion->seteventcount(noevents);
	for (int i = 0; i < noevents; i++) {
		input >> eventtype;
		if (eventtype == 'F') {
			input >> missiontype >> eventDay >> ID >> location >> duration >> signifiance;
			marsstaion->createvent(missiontype, eventDay, ID,  location,  duration,  signifiance)
		}
		else if (eventtype == 'x') {
			input>>  eventDay >> ID;
			 marsstaion->createCancelEvent(eventDay, ID);
		}
		
	}
	input.close();
}