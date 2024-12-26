#ifndef TOOLS_H
#define TOOLS_H
#include "shuttle.h"
#include <fstream>
// Helper functions
void loadShuttles(Shuttle shuttles[], ifstream &inFile);
void loadPassengers(Shuttle shuttles[], ifstream &File2);
void printWave(Shuttle shuttles[], int waveCount);
void reset(Shuttle shuttles []);
bool stillRoom(Shuttle shuttles[]);
#endif
