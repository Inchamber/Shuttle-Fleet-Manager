#include "shuttle.h"
#include "tools.h"

int main(int argc,char* argv[])
{
    if (argc != 3) {
	cout << "Usage: " << argv[0] << " <datafile>" << endl;
	return(0);
    }
	
	// Variables
    char* shuttles_file = argv[1];
	char* persons = argv[2];
	ifstream inFile;
	ifstream File2;
	Shuttle shuttles [SHUTTLE_ARR_SIZE];

	// Function calls and opening/closing files
	inFile.open(shuttles_file);
	loadShuttles(shuttles, inFile);
	File2.open(persons);
	loadPassengers(shuttles, File2);
	inFile.close();
	File2.close();
    return 0;
}
