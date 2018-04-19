#include "language.h"
#include "bigint/bigint.h"
#include <cmath>
#include <string>

double similarity::compare(frequency &train, frequency &test)
{
    bigint numerator;
	bigint freqA;
	bigint freqB;
	bigint result;
	std::string number;
	
    for(size_t i = 0; i < train.getSize() -1; i++)
    {
        numerator += train[i]*test[i];
    }

	for(size_t i = 0; i < train.getSize() - 1; i++)
	{
		freqA += pow(train[i], 2);
		freqB += pow(test[i], 2);
	}
	
	/*std::string num = numerator.to_string();
	std::string A = freqA.to_string();
	std::string B = freqB.to_string();*/
	
	/*double denomA = std::stod(A);
	double denomB = std::stod(B);
	double newNumerator = std::stod(num);*/
	
	//denomA = sqrt(denomA);
	//denomB = sqrt(denomB);
	
	/*double newDen = denomA * denomB;
	newNumerator *= 1000000;
	
	result = newNumerator / (newDen);*/
	
	//number = result.to_string();
	//double total = std::stod(number);
	numerator = numerator.fast_pow(2);
	numerator *= 1000000;
	
	result = numerator / (freqA * freqB);
	
	number = result.to_string();
	double newNum = std::stod(number);
	newNum /= (float) 1000000;
	newNum = sqrt(newNum);
	std::cout << newNum << std::endl;
	
	
	return newNum;	
}