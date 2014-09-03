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
	getline(file,UMW);
	getline(file,numDir);	
	int NumDirection =atoi(numDir.c_str());
	for (int i=0;i < NumDirection;i++){
		getline(file,direction[i]);
		getline(file,streetName[i]);
		getline(file,mileage[i]);		
		mile=atof(mileage[i].c_str());
		int a=0;
		mile=a+mile;
	} // for loop	
	getline(file,destination);
	getline(file,location);
	
	cout << mile << " this is the total mileage!" << endl
	cout <<"How much does gas cost (in/gallons)? ";
	cin >> cost;
	cout << endl;
	cout << "What is your gas mileage (in mpg)? ";
	cin >> mpg;
	cout <<  endl;	
	cout << "This is the location of your starting location " << UMW << "." << endl;
	cout << "this is how many directions are in the file" << NumDirection  << endl;
		
	//prints out the list
	for(int a = 0; a < NumDirection ; a++){
		cout << direction[a] << endl;
		cout<< mileage[a] << endl;
		cout << streetName[a] << endl;
		
	} //end for
	cout << destination << " This is the final destination." << endl;
	cout << location << " This is the where the final location is" << endl;

	
}// end of main


