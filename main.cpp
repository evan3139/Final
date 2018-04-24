/*
    Authors: Evan Wildenhain, John Sullivan
    Started on 4/7/18
*/

#include "functions.h"
#include "bigint/bigint.h"
#include "language.h"

int main(int argc, char *argv[])
{
    //Starts a vector that will hold frequencies in seperate indexes for each file
	double largest = 0;
	int counter = 0;
	//This will get the frequency for the test file before anything else
	std::ifstream infile;
	infile.open(argv[argc-1]);
	frequency testFile;
	testFile = testFile.freqValue(infile);

	//This for loop will grab the frequency of each file compare it then delete it and repeate with every file
	//Making note of which file has the largest COSSimilarity everytime it runs and storing it.
	for(int r = 1; r < argc - 1; r++)
	{
		std::ifstream infile;
		infile.open(argv[r]);
		frequency i;
		i = i.freqValue(infile);
		similarity cosSimilarity;
		double result = cosSimilarity.compare(i, testFile);			
		if (result > largest)
		{
			largest = result;
			counter = r - 1;
		}
	}
	//print name of the most likely matched language to console window.
	std::cout << argv[counter + 1] << std::endl;
	return 0;
}