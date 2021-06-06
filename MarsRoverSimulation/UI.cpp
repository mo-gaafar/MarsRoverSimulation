#include "UI.h"
void UI::read() {
	ifstream input;
	input.open("Inputfile.txt");
	if (input.fail()) {
		cerr << "error opening file" << endl;
		exit(1);
	}
	//LINE 1
	input >> PolarRoverCount >> EmRoverCount;
	//LINE 2
	input >> PolarSpeed >> EmSpeed;
	//LINE 3
	input >> CheckCount >> PolarCheck >> EmCheck;
	//line 4
	input >> NumberOFEvents;
	EventType = new char[NumberOFEvents];//dynamic array
	MissionType = new char[NumberOFEvents];//dynamic array
	EventDay = new int[NumberOFEvents];//dynamic array
	ID = new int[NumberOFEvents];//dynamic array
	location = new int[NumberOFEvents];//dynamic array
	Duration = new int[NumberOFEvents];//dynamic array
	Signifiance = new int[NumberOFEvents];//dynamic array
	for (int i = 0; i < NumberOFEvents; i++) {//dynamic array
		input >> EventType[i];
		if (EventType[i] == 'F') {
			input >> MissionType[i];
			input >> EventDay[i];
			input >> ID[i];
			input >> location[i];
			input >> Duration[i];
			input >> Signifiance[i];
		}
		else {
			MissionType[i] = 'x';
			EventDay[i] = -1;
			ID[i] = -1;
			location[i] = -1;
			Duration[i] = -1;
			Signifiance[i] = -1;
		}


	}
	input.close();

}