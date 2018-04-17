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
            std::ifstream infile;
            infile.open(argv[r]);
            frequency i;
            i = i.freqValue(infile);
            i.printFreq();
            storage.push_back(i);
        }
        return 0;
    }
}

