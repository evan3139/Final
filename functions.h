/**
 * Started by Najib 3/21/18
 **/

#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include "bigint/bigint.h"

//Creating a frequency class
class frequency
{
private:
//Creates a vector to store the frequencies of the Word docs
   std::vector<int> frequencies;


public:
//Default constructor and the function that gets the frequency values of the files.
   frequency();
   frequency(const std::vector<int> &f);
   void printFreq();
   std::vector<int> freqValue(std::ifstream &infile);

};



#endif
