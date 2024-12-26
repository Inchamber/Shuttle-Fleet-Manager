#include "tools.h"

// Name: void loadShuttles(Shuttle shuttles[], ifstream &inFile)
// Desc: This function loads the shuttles with their names and capacity.
// Input: char shuttleName[STR_SIZE], int cap
// Output: None
// Return: None
void loadShuttles(Shuttle shuttles[], ifstream &inFile) {
	char shuttleName [STR_SIZE];
	int cap;
	for (int i = 0; i < SHUTTLE_ARR_SIZE; i++) {
		inFile.getline(shuttleName, STR_SIZE, ' ');
		shuttles[i].setName(shuttleName);
		inFile >> cap;
		shuttles[i].setCapacity(cap);
		inFile.ignore(100, '\n');
	}	
}


// Name: void loadPassengers(Shuttle shuttles[], ifstream& File2)
// Desc: This function loads the shuttles with people in round robin fashion.
// It also checks when a shuttle is full and when all shuttles are full.
// Therafter it calls another function to print the wave.
// Input: char personName [STR_SIZE]
// Output: None
// Return: None
void loadPassengers(Shuttle shuttles[], ifstream& File2) {
    int activeShuttle = 0;  // Index of the current shuttle being considered
    int waveCount = 1;
    char personName[STR_SIZE];

    File2.getline(personName, STR_SIZE, '\n');
    while (!File2.eof()) {
        bool personPlaced = false;
        while (personPlaced == false && stillRoom(shuttles)) {
            if (shuttles[activeShuttle].hasRoom()) {
                shuttles[activeShuttle].addPassenger(personName);
                personPlaced = true;
            }

            // Move to the next shuttle (round-robin)
            activeShuttle = (activeShuttle + 1) % SHUTTLE_ARR_SIZE;

            // Check if all shuttles are full
            bool allFull = true;
            for (int i = 0; i < SHUTTLE_ARR_SIZE; i++) {
                if (shuttles[i].hasRoom()) {
                    allFull = false;
                }
            }

            if (allFull) {
            	printWave(shuttles, waveCount);
                reset(shuttles);
                ++waveCount;
				activeShuttle = 0;
            }
        }
        File2.getline(personName, STR_SIZE, '\n');
	}
    printWave(shuttles, waveCount);
}

// Name: void printWave(Shuttle shuttles[], int waveCount)
// Desc: This function outputs the wave banner and calls the
// printPassengerList function.
// Input: None
// Output: int waveCount
// Return: None
void printWave(Shuttle shuttles[], int waveCount) {
	cout << "=================================================================" <<
	"=====" << endl;
  	cout << "============================== Wave  " << waveCount << " =====" <<
	"==========================" << endl;
  	cout << "===============================================================" << 
	"=======" << endl;
	for(int i = 0; i < SHUTTLE_ARR_SIZE; i++) {
		shuttles[i].printPassengerList();
	}
}

// Name: void reset(Shuttle shuttles[])
// Desc: This function resets each shuttles.
// Input: None
// Output: None
// Return: None
void reset(Shuttle shuttles[]) {
	for (int i = 0; i < SHUTTLE_ARR_SIZE; i++) {
		shuttles[i].clearPassengerList();
	}
}

// Name: bool stillRoom(Shuttle shuttles[])
// Desc: This function checks if the shuttles still have room.
// Input: None
// Output: None
// Return: None
bool stillRoom(Shuttle shuttles[]) {
	bool check = false;
	int counter = 0;
	while(counter < SHUTTLE_ARR_SIZE && check == false) {
		if(shuttles[counter].hasRoom() == true) {
			check = true;
		}
		++counter;
	}
	return check;
}
