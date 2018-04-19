/*
    Authors: Evan Wildenhain, John Sullivan
    Started on 4/7/18
*/

#include "functions.h"
#include "bigint/bigint.h"
#include "language.h"
#include <string>




int main(int argc, char *argv[])
{
    //Starts a vector that will hold frequencies in seperate indexes for each file
    std::vector<frequency> storage;
	std::string test = "test";
	double largest = 0;
	int ctr = 0;
    if(argc > 0)
    {
        //This loop will run the frequency value function for every file that si input into the command line.
        for(int r = 1; r < argc; r++)
        {
			if(argv[r] == test){
				//do nothing
			}
			else
			{
				std::ifstream infile;
				infile.open(argv[r]);
				frequency i;
				i = i.freqValue(infile);
				storage.push_back(i);
			}
        }
		
		for(size_t r = 0; r < storage.size() - 1; r++)
		{
	
			similarity cosSimilarity;
			double result = cosSimilarity.compare(storage[r], storage[storage.size() - 1]);
			
			if (result > largest){
				largest = result;
				ctr = r;
			}
		}
		std::cout << "Lol the language is probz like:\t" << argv[ctr + 1] << std::endl;
        return 0;
    }
	
}

