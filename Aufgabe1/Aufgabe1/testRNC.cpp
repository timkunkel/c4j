/*
   Simple Unit Test for type RationalNumberCollection
*/

#include <stdio.h>
#include <assert.h>

#include "rationalnumber.h"
#include "rationalnumbercollection.h"

void printCollection(RationalNumberCollection* rnc)
{
    printf("Collection: ");
    for(int i = 0; i < rnc->length; i++)
    {
        printf("\t%d/%d", rnc->rnwc[i].rn.numerator,  rnc->rnwc[i].rn.denominator);
    }
    printf("\nCounter:    ");
    for(int i = 0; i < rnc->length; i++)
    {
        printf("\t %d", rnc->rnwc[i].counter);
    }
    printf("\n");
}

void printRemoveFromCollection(RationalNumberCollection* rnc, RationalNumber rn)
{
    rncRemove(rnc, rn);
    printf("remove %d/%d \n", rn.numerator, rn.denominator);
    printCollection(rnc);
    printf("rncTotalCount %d \n", rncTotalCount(rnc));
    printf("rncSum %d/%d \n", rncSum(rnc).numerator, rncSum(rnc).denominator);
    printf("\n");
}

void printAddToCollection(RationalNumberCollection* rnc, RationalNumber rn)
{
    printf("add %d/%d to collection \n", rn.numerator, rn.denominator);
    rncAdd(rnc, rn);
    printCollection(rnc);
    printf("rncTotalCount %d \n", rncTotalCount(rnc));
    printf("rncSum: %d/%d \n", rncSum(rnc).numerator, rncSum(rnc).denominator);
    printf("\n");
}

int main()
{

    printf("Performing unit tests for RationalNumberCollection...\n");

    /* Part 1 - RationalNumber data type */
    RationalNumber  n1 = { 3, 4 },
                    n2 = { 6, 4 },
                    n3 = { 3, 2 },
                    n4 = { -9, -6 },
                    n5 = { 9, -6 },
                    n6 = { 9, 4 },
                    n0 = { 0, 4 },
                    nn = { 4, 0 };

    assert( rnIsValid(n0) );
    assert( !rnIsValid(nn) );

    assert( rnEqual( n2, n3) );

    assert( rnEqual( rnAdd(n1,n1), n2) );
    assert( rnEqual( n2,n4) );
    assert( !rnEqual( n4,n5) );
    assert( rnLessThan( n5,n3) );

    RationalNumber t1 = rnAdd(n1,n2);
    RationalNumber t2 = rnDivide(n3,n3);
    RationalNumber t3 = rnDivide(n2,n2);
    RationalNumber t4 = rnDivide(n6,n0);

    assert( rnEqual(t1, n6) );
    assert( rnEqual(t2, t3) );
    assert( !rnIsValid(t4) );


    /* Part 2 - RationalNumberColletion data type */
    RationalNumberCollection rnc;
    rncInit(&rnc);

    printAddToCollection(&rnc, n1);
    printAddToCollection(&rnc, n2);
    printAddToCollection(&rnc, n3);
    printAddToCollection(&rnc, n4);
    printAddToCollection(&rnc, n5);
    printAddToCollection(&rnc, n6);
    printAddToCollection(&rnc, n1);
    printAddToCollection(&rnc, n1);
    printAddToCollection(&rnc, n5);

    printf("total uniques: %d \n", rncTotalUniqueCount(&rnc));
    printf("rncAverage %d/%d \n", rncAverage(&rnc).numerator, rncAverage(&rnc).denominator);
    printf("\n");

    printRemoveFromCollection(&rnc, n2);
    printRemoveFromCollection(&rnc, n2);
    printRemoveFromCollection(&rnc, n2);

    printAddToCollection(&rnc, nn);

    printf(" successful!\n");

    return 0;
}


