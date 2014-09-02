// James Moore
// reverse.cpp
// aug 30
// davies
// this program is designed to read in a file then print out the reverse
// directions and calculate the estimated gas cost and and the mileage.


#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

const int MAX_NUM_WORDS = 10000;

int main(int argc, char *argv[]){
double cost =0;
double mpg=0;

string direction [MAX_NUM_WORDS];
string streetName [MAX_NUM_WORDS];
string mileage [MAX_NUM_WORDS];

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
	int wordNum=0;

	while(file){
	wordNum++;	
		getline(file,direction[wordNum]);
		getline(file,streetName[wordNum]);
		getline(file,mileage[wordNum]);		
	} // while loop	
	cout << wordNum << endl;

	cout <<"How much does gas cost (in/gallons)? ";
	cin >> cost;
	cout << endl <<  "What is your gas mileage (in mpg)? ";
	cin >> mpg;
	cout <<  endl << endl << endl;
	
	
	//prints out the list
	for(int i=wordNum-1; i>=0; i--){
		cout<< direction[i] << endl;
		cout << streetName[i] << endl;
		cout << mileage[i] << endl;
	} //end for
	
}// end of main


