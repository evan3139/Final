#include "language.h"
#include "bigint/bigint.h"
#include <cmath>

double similarity::compare(frequency &train, frequency &test)
{
	//Initializing the denominators and the numerator and result
	bigint freqA, freqB, result, numerator;
	std::string number;
	double total;
	
	//For loop sets the numerator and the denominators
	for(size_t i = 0; i < train.getSize() - 1; i++)
	{
		numerator += train[i]*test[i];
		freqA += pow(train[i], 2);
		freqB += pow(test[i], 2);
	}

	//Square the numerator and perform scaled division allowing it to be divided by the denominator due to bigint being an int not double;
	numerator = numerator.fast_pow(2);
	numerator *= 1000000;
	result = numerator / (freqA * freqB);
	//Turn the result into a string so it can then be turned into a decimal by doing std::stod since bigint
	//Cant be converted into a double without making a string first due to no double converter being made in the bigint class
	number = result.to_string();
	total = std::stod(number);
	//Divide by the number you multiplied by in order to undo the scaled division returning the real number then square root it and return.
	total /= (float) 1000000;
	total = sqrt(total);

	return total;	
}