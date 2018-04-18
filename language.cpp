#include "language.h"
#include "bigint/bigint.h"

bigint similiarity::compare(frequency &train, frequency &test)
{
    bigint numerator;
    for(size_t i = 0; i < train.getSize() -1; i++)
    {
        numerator += train[i] + test[i];
    }


}