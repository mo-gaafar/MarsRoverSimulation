#pragma once
class Rover {
private:
	char roverType;
	int checkupDur;
	int checkupMissionNo;
	int speed;
public:
	Rover(char t, int cd, int s, int cmn); //Initialiaztion

	//GETTERS
	char getTYP() { return roverType; }
	int getCDUR() { return checkupDur; }
	int getSpeed() { return speed; }
	int getCheckupMissionNo() { return checkupMissionNo; }

	~Rover() {}
};

Rover::Rover(char t, int cd, int s, int cmn) {
	roverType = t;
	checkupDur = cd;
	speed = s;
	checkupMissionNo = cmn;
}