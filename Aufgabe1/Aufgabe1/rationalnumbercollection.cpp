#include <stdio.h>
#include "rationalnumbercollection.h"

void rncInit(RationalNumberCollection* rnc)
{
    rnc->length = 0;
    rnc->totalSum = RationalNumber {0, 1};
    rnc->totalCount = 0;
}

int rncContainsAt(RationalNumberCollection* rnc, RationalNumber rn)
{
    int mid;
    int left = 0;
    int right = rnc->length - 1;

    while(left <= right)
    {
        mid = left + ((right - left) / 2);

        if(rnEqual(rnc->rnwc[mid].rn, rn))
            return mid;

        else
        {
            if(rnLessThan(rn, rnc->rnwc[mid].rn))
                right = mid - 1;

            else
                left = mid + 1;
        }
    }

    return -1;
}

void rncAdd(RationalNumberCollection* rnc, RationalNumber rn)
{
    if(!rnIsValid(rn))
    {
        printf("Cannot add %d/%d to collectione, because it's an invalid rational number. \n",
               rn.numerator, rn.denominator);
        return;
    }
    int index = rncContainsAt(rnc, rn);
    if(index >= 0)
    {
        rnc->rnwc[index].counter++;
    }
    else
    {
        index = 0;
        while(rnLessThan(rnc->rnwc[index].rn, rn))
        {
            if(index < rnc->length)
                index++;
        }
        for(int i = rnc->length - 1; i >= index; i--)
        {
            rnc->rnwc[i + 1] = rnc->rnwc[i];
        }
        rnc->rnwc[index] = RationalNumberWithCounter {rn, 1};
        rnc->length++;
    }
    rnc->totalCount++;
    rnc->totalSum = rnAdd(rnc->totalSum, rn);
}

void rncRemove(RationalNumberCollection* rnc, RationalNumber rn)
{
    int index = rncContainsAt(rnc, rn);
    if(index > 0)
    {
        if(--rnc->rnwc[index].counter == 0)
        {
            for(int i = index; i < rnc->length; i++)
            {
                rnc->rnwc[i] = rnc->rnwc[i + 1];
            }
            rnc->length--;
        }
        rnc->totalCount--;
        rnc->totalSum = rnSubtract(rnc->totalSum, rn);
    }
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


