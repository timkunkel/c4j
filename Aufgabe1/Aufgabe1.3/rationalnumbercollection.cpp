#include "stdlib.h"
#include "stdio.h"
#include "rationalnumbercollection.h"

struct RationalNumberCollection
{
    struct RationalNumberWithCounter{
        RationalNumber rn;
        int counter;
    };

    RationalNumberWithCounter* rnwc;
    int length;
    RationalNumber totalSum;
    int totalCount;
    int maxArrayLength;
};

void rncInit(RationalNumberCollection* rnc)
{
    RationalNumber newRn = {0, 1};

    rnc->length = 0;
    rnc->totalSum = newRn;
    rnc->totalCount = 0;
}

RationalNumberCollection* rncCreate(int arraySize)
{
    RationalNumberCollection* rnc = (RationalNumberCollection*) malloc(sizeof(RationalNumberCollection));
    rnc->rnwc = (RationalNumberCollection::RationalNumberWithCounter*) malloc(arraySize * sizeof(RationalNumberCollection::RationalNumberWithCounter));
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

void rncIncreaseCapacity(RationalNumberCollection *rnc,int amount){

        RationalNumberCollection::RationalNumberWithCounter* elements = (RationalNumberCollection::RationalNumberWithCounter*)
                     malloc(sizeof(RationalNumberCollection::RationalNumberWithCounter) * (rnc->maxArrayLength + amount));
             // update capacity attribute
             rnc->maxArrayLength += amount;
             for(int i = 0; i < rnc->maxArrayLength; i++)
             {
                 RationalNumber rn;
                 rn.numerator = 0;
                 rn.denominator = 0;
                 elements[i].rn =rn;
                 elements[i].counter = 0;
             }
             // copy elements
             for(int i = 0; i < rnc->length; i++){
                 elements[i] = rnc->rnwc[i];

             }
             // free old array
             free(rnc->rnwc);
             // set new pointer
             rnc->rnwc = elements;
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

        if(rnc->length >= rnc->maxArrayLength-1)
        {
               printf("increase collection capacity");
            rncIncreaseCapacity(rnc,rnc->maxArrayLength * 0.3);
         }
/**

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
        */
        RationalNumberCollection::RationalNumberWithCounter newRnWc = {rn, 1};
        rnc->rnwc[rnc->length++] = newRnWc;
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

    RationalNumber newRN = {1, rncTotalCount(rnc)};
    return rnMultiply(rncSum(rnc), newRN);
}


