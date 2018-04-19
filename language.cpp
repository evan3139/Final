#include "language.h"
#include "bigint/bigint.h"
#include <cmath>
#include <string>

double similiarity::compare(frequency &train, frequency &test)
{
    bigint numerator;
	bigint freqA;
	bigint freqB;
	bigint result;
	std::string number;
	
    for(size_t i = 0; i < train.getSize() -1; i++)
    {
        numerator += train[i] + test[i];
    }

	for(size_t i = 0; i < train.getSize() - 1; i++)
	{
		freqA += pow(train[i], 2);
		freqB += pow(test[i], 2);
	}
	
	numerator *= 1000000;
	result = numerator / (freqA * freqB);
	result /= 1000000;
	number = result.to_string();
	double total = std::stod (number);
	total = sqrt(total);
	return total;	
}