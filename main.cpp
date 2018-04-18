/*
    Authors: Evan Wildenhain, John Sullivan
    Started on 4/7/18
*/

#include "functions.h"
#include "bigint/bigint.h"




int main(int argc, char *argv[])
{
    //Starts a vector that will hold frequencies in seperate indexes for each file
    std::vector<frequency> storage;
    if(argc > 0)
    {
        //This loop will run the frequency value function for every file that si input into the command line.
        for(int r = 1; r < argc; r++)
        {
			if(argv[r] == "test"){
				std::ifstream infile;
				infile.open(argv[r+1]);
				frequency i;
				i = i.freqValue(infile);
				storage.push_back(i);
				break;
			}
			std::ifstream infile;
			infile.open(argv[r]);
			frequency i;
			i = i.freqValue(infile);
			storage.push_back(i);
        }
		
		for(int r = 1; r < argc - 1; r++)
		{
			double result = 
			double largest = 
			
		
        return 0;
    }
	
}

