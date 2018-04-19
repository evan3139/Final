#ifndef __LANGUAGE_H__
#define __LANGUAGE_H__

#include "bigint/bigint.h"
#include"functions.h"

class similarity
{
private:
    bigint similarity;

public:
    double compare(frequency &train, frequency &test);

};










#endif