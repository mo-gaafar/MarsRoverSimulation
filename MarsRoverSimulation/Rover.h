#pragma once
class Rover {
private:
	char roverType;
	int checkupDur;
	int speed;
public:
	Rover(char t, int cd, int s); //Initialiaztion

	//GETTERS
	char getTYP() { return roverType; }
	int getCDUR() { return checkupDur; }
	int getSpeed() { return speed; }

	~Rover() {}
};

Rover::Rover(char t, int cd, int s) {
	roverType = t;
	checkupDur = cd;
	speed = s;
}