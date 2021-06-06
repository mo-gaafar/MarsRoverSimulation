#pragma once
class Mission {
private:
	int formulationDay;
	char missionType;
	int targetLoc;
	int missionDur;
	int sig;
	int ID;
public:
	Mission(int f, char mt, int tl, int md, int s); //Initialization
	Mission(Mission const &m) {  //Copy constructor
		formulationDay = m.getFD();
		missionType = m.getTYP();
		targetLoc = m.getTLOC();
		missionDur = m.getMDUR();
		sig = m.getSIG();
	}
	 Mission() {
		formulationDay = 0;
		missionType = 0;
		targetLoc = 0;
		missionDur = 0;
		sig = 0;
		ID = 0;
	}

	Mission& operator = (const Mission & m) {
		
		formulationDay = m.formulationDay;
		missionType = m.missionType;
		targetLoc = m.targetLoc;
		missionDur = m.missionDur;
		sig = m.sig;
		return *this;
	}

	//GETTERS
	int getFD()const { return formulationDay; }
	char getTYP() const { return missionType; }
	int getTLOC() const{ return targetLoc; }
	int getMDUR() const{ return missionDur; }
	int getSIG() const{ return sig; }
	int getID() const { return ID; }

	void setTYP(char in) { missionType = in; } //In case of promotion
	void setID(int id) { ID = id; }

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

Mission::Mission(int f, char mt, int tl, int md, int s) {
	formulationDay = f;
	missionType = mt;
	targetLoc = tl;
	missionDur = md;
	sig = s;
}