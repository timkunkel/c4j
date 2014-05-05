#include "stdlib.h"
#include "rationalnumbercollection.h"

struct RationalNumberCollection
{
    RationalNumberWithCounter* rnwc;
    int length;
    RationalNumber totalSum;
    int totalCount;
    int maxArrayLength;
};

void rncInit(RationalNumberCollection* rnc)
{
    rnc->length = 0;
    rnc->totalSum = RationalNumber {0, 1};
    rnc->totalCount = 0;
}

RationalNumberCollection* rncCreate(int arraySize)
{
    RationalNumberCollection* rnc = (RationalNumberCollection*) malloc(sizeof(RationalNumberCollection));
    rnc->rnwc = (RationalNumberWithCounter*) malloc(arraySize * sizeof(RationalNumberWithCounter));
    rnc->maxArrayLength = arraySize;
    rncInit(rnc);
    return rnc;
}

void rncDelete(RationalNumberCollection* rnc)
{
    free(rnc->rnwc);
    free(rnc);
}

int rncContainsAt(RationalNumberCollection* rnc, RationalNumber rn)
{
    for(int i = 0; i < rnc->length; i++)
    {
        if(rnEqual(rnc->rnwc[i].rn, rn))
            return i;
    }
    return -1;
}

void rncAdd(RationalNumberCollection* rnc, RationalNumber rn)
{
    int index = rncContainsAt(rnc, rn);
    if(index >= 0)
    {
        rnc->rnwc[index].counter++;
    }
    else
    {
        if(rnc->length >= rnc->maxArrayLength)
        {
            RationalNumberWithCounter* newArray =
                    (RationalNumberWithCounter*) malloc(2 * rnc->maxArrayLength * sizeof(RationalNumberWithCounter));
            for(int i = 0; i < rnc->length; i++)
            {
                newArray[i] = rnc->rnwc[i];
            }
            free(rnc->rnwc);
            rnc->rnwc = newArray;
            rnc->maxArrayLength *= 2;
        }
        rnc->rnwc[rnc->length++] = RationalNumberWithCounter {rn, 1};
    }
    rnc->totalCount++;
    rnc->totalSum = rnAdd(rnc->totalSum, rn);
}

int rncCount(RationalNumberCollection* rnc, RationalNumber rn)
{
    int index = rncContainsAt(rnc, rn);
    if(index >= 0)
        return rnc->rnwc[index].counter;

    else
        return 0;
}

int rncTotalUniqueCount(RationalNumberCollection *rnc)
{
    return rnc->length;
}

int rncTotalCount(RationalNumberCollection* rnc)
{
    return rnc->totalCount;
}

RationalNumber rncSum(RationalNumberCollection* rnc)
{

    return rnc->totalSum;
}

RationalNumber rncAverage(RationalNumberCollection* rnc)
{
    return rnMultiply(rncSum(rnc), RationalNumber {1, rncTotalCount(rnc)});
}


