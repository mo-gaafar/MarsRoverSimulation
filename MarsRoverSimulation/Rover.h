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
	//Used in Initialiaztion 
	Rover(char t, int cd, int s, int cmn) {
		roverType = t;
		checkupDur = cd;
		speed = s;
		checkupMissionNo = cmn;
		inCheckDays = -1;
		missionNo = 0;
		inMaintenanceDay = 0;
	}
	//Copy constructor
	Rover(Rover const & r) {
		roverType = r.getTYP();
		checkupDur = r.getCDUR();
		checkupMissionNo = r.getCheckupMissionNo();
		speed = r.getSpeed();
		inCheckDays = r.getInCheckDays();
		missionNo = r.getMissionNO();
		inMaintenanceDay = r.getinMaintenanceDay();
	}
	//Default constructor
	Rover() {
		roverType = 0;
		checkupDur = 0;
		checkupMissionNo = 0;
		speed = 0;
		missionNo = 0;
		inCheckDays = -1;
		inMaintenanceDay = -1;
	}

	Rover & operator = (const Rover & r) {
		
		roverType = r.roverType;
		checkupDur = r.checkupDur;
		checkupMissionNo = r.checkupMissionNo;
		speed = r.speed;
		inCheckDays = r.inCheckDays;
		missionNo = r.missionNo;
		inMaintenanceDay = r.inMaintenanceDay;
		return *this;
	}

	//GETTERS
	char getTYP() const{ return roverType; }
	int getCDUR() const { return checkupDur; }
	int getSpeed() const{ return speed; }
	int getCheckupMissionNo() const { return checkupMissionNo; }
	int getInCheckDays() const{ return inCheckDays; }
	int getMissionNO() const{ return missionNo; }
	int getinMaintenanceDay() const { return inMaintenanceDay; }
	void setInCheckDays(int in) { inCheckDays = in; }
	void setinMaintenanceDay(int in) { inMaintenanceDay = in; }
	void incrementMissions() { missionNo++; }
	int getID() { return ID; }

	void setCheckupMissionNo(int in) { checkupMissionNo = in; }
	void setID(int id) { ID = id; }

	~Rover() {}
};
