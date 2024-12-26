#ifndef SHUTTLE_H
#define SHUTTLE_H

// Includes
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

// Constant varibales
const int STR_SIZE = 100;
const int SHUTTLE_ARR_SIZE = 7;
const int MAX_PERSONS = 35;

// Class definiton, private data types and public functions
class Shuttle {
	private:
		char name[STR_SIZE];
		int capacity;
		int count;
		char passengers[MAX_PERSONS][STR_SIZE];

	public:
		Shuttle();
		void setName(char nameArg []);
		void setCapacity(int seats);
		bool hasRoom();
		void addPassenger(const char * passengerName);
		void printPassengerList();
		void clearPassengerList();
};

#endif

