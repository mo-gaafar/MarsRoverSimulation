#pragma once
class Rover {
private:
	char roverType;
	int checkupDur;
	int checkupMissionNo;
	int speed;
	int inCheckDays;
	int inMaintenanceDay;
	int missionNo;
	int ID;
public:
	Rover(char t, int cd, int s, int cmn); //Initialiaztion
	Rover(Rover& r) {
		roverType = r.getTYP();
		checkupDur = r.getCDUR();
		checkupMissionNo = r.getCheckupMissionNo();
		speed = r.getSpeed();
		inCheckDays = r.getInCheckDays();
		missionNo = r.getMissionNO();
		inMaintenanceDay = r.getinMaintenanceDay();
	}
	
	Rover() {
		roverType = '.';
		checkupDur = 0;
		checkupMissionNo = 0;
		speed = 0;
		missionNo = 0;
		inCheckDays = -1;
		inMaintenanceDay = -1;
	}

	Rover operator = (Rover const& r) {
		Rover r2;
		r2.roverType = r.roverType;
		r2.checkupDur = r.checkupDur;
		r2.checkupMissionNo = r.checkupMissionNo;
		r2.speed = r.speed;
		r2.inCheckDays = r.inCheckDays;
		r2.missionNo = r.missionNo;
		r2.inMaintenanceDay = r.inMaintenanceDay;
		return r2;
	}

	//GETTERS
	char getTYP() { return roverType; }
	int getCDUR() { return checkupDur; }
	int getSpeed() { return speed; }
	int getCheckupMissionNo() { return checkupMissionNo; }
	int getInCheckDays() { return inCheckDays; }
	int getMissionNO() { return missionNo; }
	int getinMaintenanceDay() { return inMaintenanceDay; }
	void setInCheckDays(int in) { inCheckDays = in; }
	void setinMaintenanceDay(int in) { inMaintenanceDay = in; }
	void incrementMissions() { missionNo++; }
	int getID() { return ID; }

	void setCheckupMissionNo(int in) { checkupMissionNo = in; }
	void setID(int id) { ID = id; }

	~Rover() {}
};

Rover::Rover(char t, int cd, int s, int cmn) {
	roverType = t;
	checkupDur = cd;
	speed = s;
	checkupMissionNo = cmn;
	inCheckDays = -1;
	missionNo = 0;
	inMaintenanceDay = 0;
}