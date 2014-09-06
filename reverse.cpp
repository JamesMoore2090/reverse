// James Moore
// reverse.cpp
// sept 5 2014
// davies
// this program is designed to read in a file then print out the reverse
// directions and calculate the estimated gas cost and and the mileage.


#include <iostream>
#include <fstream>
#include <cmath>
#include <stdlib.h>
#include <iomanip>
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
double mile=0.00;
double gasTotal=0.00;
double mileTotal=0.00;
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
	// thid takes the directions and flips them to be backwards.
	for(int j=0; j<=NumDirection;j++){
		if (direction[j] == "Right" || direction[j] == "R"){
			direction[j]= 'L';
		} // end if
		else direction[j] = 'R';
	}// end for	
	// this turns the ending direction to the opposite
	if (location == "Right" || location == "R"){
		location = 'L';
	} // end if
	else location = 'R';
	// below here prints out the directions	
	cout << "How much does your gas (in/per gallons)? " ;
	cin >> cost;
	cout << "What is your gas mileage (in mpg)? ";
	cin >> mpg;;
	cout << "Start location " << destination << endl;	
	//prints out the directions in reverse order
	for(int a = NumDirection-1; a >= 0 ; a--){	
		cout << direction[a] << " on " << streetName[a] << " ("<< mileage[a] << " miles)" << endl;	
	} //end for
	cout << UMW << " is on the " << location << endl;
	// this turns the mile string in to a double to do math with!
	for(int m =0; m<=NumDirection; m++){ 
		mile=atof(mileage[m].c_str());
		mileTotal= (mile+mileTotal);
	} // end for
	mileTotal= mileTotal*2; // this multiples the miles by 2 to make the round trip
	gasTotal = (mileTotal/mpg)*cost; // calcs the ~gas price

	cout << "Your " << mileTotal << "-mile round trip will cost you $";
	cout << setprecision(3) << gasTotal << endl;
}// end of main
