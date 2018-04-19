#include "language.h"
#include "bigint/bigint.h"
#include <cmath>
#include <string>

double similarity::compare(frequency &train, frequency &test)
{
	bigint freqA, freqB, result, numerator;
	std::string number;
	double total;
	
	for(size_t i = 0; i < train.getSize() - 1; i++)
	{
		numerator += train[i]*test[i];
		freqA += pow(train[i], 2);
		freqB += pow(test[i], 2);
	}
	numerator = numerator.fast_pow(2);
	numerator *= 1000000;
	result = numerator / (freqA * freqB);
	number = result.to_string();
	total = std::stod(number);
	total /= (float) 1000000;
	total = sqrt(total);
	
	return total;	
}