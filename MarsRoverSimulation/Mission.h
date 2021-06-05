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
		missionType = '.';
		targetLoc = 0;
		missionDur = 0;
		sig = 0;
	}

	Mission operator = (Mission const& m) {
		Mission m2;
		m2.formulationDay = m.formulationDay;
		m2.missionType = m.missionType;
		m2.targetLoc = m.targetLoc;
		m2.missionDur = m.missionDur;
		m2.sig = m.sig;
		return m2;
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