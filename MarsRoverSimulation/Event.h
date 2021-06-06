#pragma once
class Event {
private:
	char eventType;
	char missionType;
	int eventDate;
	int ID;
	int targetLoc;
	int misssionDur;
	int sig;
public:
	Event();
	Event(char ev, char typ, int ed, int id, int tloc, int mdur, int s); //If event is formulation
	Event(char ev, int ed, int id);
	//GETTERS
	char getET() { return eventType; }
	char getTYP() { return missionType; }
	int getED() { return eventDate; }
	int getID() { return ID; }
	int getTLOC() { return targetLoc; }
	int getMDUR() { return misssionDur; }
	int getSIG() { return sig; }

	~Event() {}
};
Event::Event() {
	eventType = 0;
	missionType = 0;
	eventDate = 0;
	ID = 0;
	targetLoc = 0;
	misssionDur = 0;
	sig = 0;
}

Event::Event(char ev, char typ, int ed, int id, int tloc, int mdur, int s) {
	eventType = ev;
	missionType = typ;
	eventDate = ed;
	ID = id;
	targetLoc = tloc;
	misssionDur = mdur;
	sig = s;
}

Event::Event(char ev, int ed, int id) {
	eventType = ev;
	eventDate = ed;
	ID = id;

	missionType = '.';
	targetLoc = -1;
	misssionDur = -1;
	sig = -1;
}

