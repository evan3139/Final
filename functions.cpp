/**
 * Authors: Evan Wildenhain & John Sullivan.
 **/
#include "functions.h"
#include "bigint/bigint.h"

frequency::frequency()
{ 
   frequencies.push_back(0);
}

frequency::frequency(const std::vector<int> &f)
{
    frequencies = f;
}

std::vector<int> frequency::freqValue(std::ifstream &infile)
{
    //A vector with the length of 26^3 is created.
    std::vector<int> freqs (17576);
    char ch, b[3];
    int n = 0, result = 0;
    while(infile.get(ch))
    {
        //Makes every char lowercase and makes sure they are a letter that falls between a and z
       ch = tolower(ch);
       if(((ch -'a') >= 0 && (ch-'a') <= 25))
       { 
           //If n is less than 3 put the first 3 letters into the array
            if (n <= 2) b[n] = ch;
            //Once it equals 3 for the first time it adds the frequency value of those 3 letters to the vector
            else if(n==3) result = (int)((b[0] - 'a') * 676) + (int)((b[1] - 'a') * 26) + (int)(b[2] - 'a');
            else
            {
                //Once n is greater than 2 it will shift each letter to the back of the array pushing the first letter out and putting
                //A new letter in the last index. and then adding the value to the vector
                freqs[result] += 1;
                result = (int)((b[0] - 'a') * 676) + (int)((b[1] - 'a') * 26) + (int)(b[2] - 'a');
                b[0] = b[1];
                b[1] = b[2];
                b[2] = ch;
            }
            n++;
       }
    }
    freqs[result] += 1; 
    return freqs;
}

void frequency::printFreq()
{
    std::cout<< frequencies[0];
    for(size_t i = 1; i < frequencies.size(); i++)
    {
        std::cout << " ";
        std::cout << frequencies[i];
    }
    std::cout << '\n';
}