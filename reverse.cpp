// James Moore
// reverse.cpp
// aug 30
// davies
// this program is designed to read in a file then print out the reverse
// directions and calculate the estimated gas cost and and the mileage.


#include <iostream>
#include <fstream>
#include <cmath>
#include <stdlib.h>

using namespace std;

const int MAX_NUM_WORDS = 10000;


int main(int argc, char *argv[]){
double cost =0;
double mpg=0;

string direction [MAX_NUM_WORDS];
string streetName [MAX_NUM_WORDS];
string mileage [MAX_NUM_WORDS];
string UMW;
string numDir;
string destination;
string location;
double mile;
double gasTotal;

	//check to see if the command arg. are valid
	if(argc != 2){
		cout << "Usage: reverse [reverseTemplateFile]." << endl;
	return 1;
	}// end if
	
	// open the file
	ifstream file(argv[1]);
        if(!file){
		cout << "Could not open template file " << argv[1] << "!" << endl;
		 return 2;
        } //end if

	//Now read the file!
	getline(file,UMW);// gets the starting location
	getline(file,numDir); // gets the number of directions
	int NumDirection =atoi(numDir.c_str()); //turns the string into an int
	for (int i=0;i < NumDirection;i++){
		getline(file,direction[i]);
		getline(file,streetName[i]);
		getline(file,mileage[i]);		
	} // for loop	
	getline(file,destination);// get the final destination
	getline(file,location);// which side is the final destination on
		
	
	
// below here prints out the directions	
	cout << "How much does your gas (in/per gallons)? " << cost<< endl;
	cout << "What is your gas mileage (in mpg)? " << mpg << endl;
	cout << "Start location " << destination << endl;	
	for(int a = 0; a < NumDirection ; a++){	
		cout << direction[a] << " on " << streetName[a] << " ("<< mileage[a] << " miles)" << endl;	
	} //end for
	cout << destination << "is on the " << location << endl;
	cout << "Your " << mile << "-mile round trip will cost you " << gasTotal << endl;
}// end of main
