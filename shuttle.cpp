#include "shuttle.h"

// Constructor sets/initializes data types
Shuttle::Shuttle() {
	strcpy(name, "no name");
	capacity = 0;
	count = 0;
}

// Name: void Shuttle::setName(char nameArg [])
// Desc: This function copies the nameArg to name
// Input: None
// Output: None
// Return: None
void Shuttle::setName(char nameArg []) {
	strcpy(name, nameArg);
}

// Name: void Shuttle::setName(int seats)
// Desc: This function sets seats to capacity
// Input: None
// Output: None
// Return: None
void Shuttle::setCapacity(int seats) {
	capacity = seats;
}

// Name: bool Shuttle::setName()
// Desc: This function checks if count is less than capacity. If so 
// the function returns true, else it returns false
// Input: None
// Output: None
// Return: bool, true or false
bool Shuttle::hasRoom() {
	bool valid = false;
	if (count < capacity) {
		valid = true;
	}
	else {
		valid = false;
	}
	return valid;
}

// Name: void Shuttle::addPassenger(const char *passengerName)
// Desc: This function checks if count is less than capacity, if it is then 
// copies passengerName to the 2 dimensional passenger array at count position.
// Then count is incremented.
// Input: None
// Output: None
// Return: None
void Shuttle::addPassenger(const char * passengerName) {
	if (count < capacity) {
		strcpy(passengers[count], passengerName);
		//strncpy(passengers[count], passengerName, STR_SIZE - 1);
		//passengers[count][STR_SIZE - 1] = '\0';
		++count;
	}
}

// Name: void Shuttle::printPassengerList()
// Desc: This function prints the name of the shuttle and shows
// how full the shuttle is. It also outputs passengers at i position.
// It also adds a comma if less than 5 names have been printed on the line
// or if the name is not the last name on the line. It also outputs a newline
// when 5 names have been printed on the line or when the name is the last
// name on the line.
// Input: None
// Output: char name [STR_SIZE], int count, int capacity, char passengers[i]
// Return: None
void Shuttle::printPassengerList() {
	int nextLine = 0;
	int i = 0;
	cout << name  << " (" << count << "/" << capacity << ")" << endl;
	cout << "Passengers:" << endl;
	cout << "  ";
	while (i < count) {
		cout << passengers[i];
		++nextLine;
		if(nextLine == 5 || i == count - 1) {
			cout << "\n  ";
			nextLine = 0;
		}
		else {
			cout << ", ";
		}
		++i;
	}
	cout << endl;
}

// Name: void Shuttle::clearPassengerList()
// Desc: This function clears the passenger list be setting count to 0.
// Input: None
// Output: None
// Return: None
void Shuttle::clearPassengerList() {
	count = 0;
}

