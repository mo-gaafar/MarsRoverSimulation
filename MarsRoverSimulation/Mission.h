#pragma once
#include"Rover.h"

class Mission {
private:
	int formulationDay;
	char missionType;
	int targetLoc;
	int missionDur;
	int sig;
	int ID;

	//not yet implemented in simulation'
	int completionDay; //to be able to calculate waiting time
	//int missionED; //execution day
	Rover* RoverPtr; //to get speed and rover ID


public:
	Mission(int f, char mt, int id, int tl, int md, int s); //Initialization
	Mission(Mission const &m) {  //Copy constructor
		formulationDay = m.getFD();
		missionType = m.getTYP();
		targetLoc = m.getTLOC();
		missionDur = m.getMDUR();
		sig = m.getSIG();
		ID = m.getID();
		completionDay = m.getCompletionDay();
	}
	 Mission() {
		formulationDay = 0;
		missionType = 0;
		targetLoc = 0;
		missionDur = 0;
		sig = 0;
		ID = 0;
		completionDay = -1;
	}

	Mission& operator = (const Mission & m) {
		
		formulationDay = m.getFD();
		missionType = m.missionType;
		targetLoc = m.targetLoc;
		missionDur = m.missionDur;
		sig = m.sig;
		ID = m.ID;
		completionDay = m.completionDay;
		RoverPtr = m.RoverPtr;
		return *this;
	}

	//GETTERS
	int getFD() const { return formulationDay; }
	char getTYP() const { return missionType; }
	int getTLOC() const { return targetLoc; }
	int getMDUR() const { return missionDur; }
	int getSIG() const { return sig; }
	int getID() const { return ID; }
	int getCompletionDay() const { return completionDay; }
	Rover* getRoverPtr() const { return RoverPtr; }
	int getRoverSpeed() const { return RoverPtr->getSpeed(); }
	int getRoverID() const { return RoverPtr->getID(); }

	//SETTERS
	void setTYP(char in) { missionType = in; } //In case of promotion
	void setID(int id) { ID = id; } 
	void setCompletionDay(int in) { completionDay = in; } //dont forget to set in sim
	void setRoverPtr(Rover* in) { RoverPtr = in; }
	
	//overloading comparative operator
	bool operator <= (Mission const& obj)
	{
		return sig >= obj.sig;
	}
	bool operator >= (Mission const& obj)
	{
		return sig <= obj.sig;
	}

	~Mission() {}
};

Mission::Mission(int f, char mt, int id, int tl, int md, int s) {
	formulationDay = f;
	missionType = mt;
	targetLoc = tl;
	missionDur = md;
	sig = s;
	ID = id;
}