#pragma once
class Mission {
private:
	int formulationDay;
	char missionType;
	int targetLoc;
	int missionDur;
	int sig;
public:
	Mission(int f, char mt, int tl, int md, int s); //Initialization

	//GETTERS
	int getFD() { return formulationDay; }
	char getTYP() { return missionType; }
	int getTLOC() { return targetLoc; }
	int getMDUR() { return missionDur; }
	int getSIG() { return sig; }

	void setTYP(char in) { missionType = in; } //In case of promotion

	~Mission() {}
};

Mission::Mission(int f, char mt, int tl, int md, int s) {
	formulationDay = f;
	missionType = mt;
	targetLoc = tl;
	missionDur = md;
	sig = s;
}