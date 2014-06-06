/*
   Simple Unit Test for type RationalNumberCollection
*/

#include <stdio.h>
#include <assert.h>

#include "rationalnumber.h"
#include "rationalnumbercollection.h"


void fillArray(RationalNumberCollection* c,int maxValues){

    for(int i = 0; i< maxValues;i++){
        RationalNumber newrn = {i,1};
        rncAdd(c,newrn);
    }
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
    RationalNumberCollection* rnc = rncCreate(5);

    ( rncAdd(rnc, n1) );
    printf("rncSum %d / %d \n", rncSum(rnc).numerator, rncSum(rnc).denominator);
    ( rncAdd(rnc, n2) );
    printf("rncSum %d / %d \n", rncSum(rnc).numerator, rncSum(rnc).denominator);
    ( rncAdd(rnc, n3) );
    printf("rncSum %d / %d \n", rncSum(rnc).numerator, rncSum(rnc).denominator);
    ( rncAdd(rnc, n4) );
    printf("rncSum %d / %d \n", rncSum(rnc).numerator, rncSum(rnc).denominator);
    ( rncAdd(rnc, n5) );
    printf("rncSum %d / %d \n", rncSum(rnc).numerator, rncSum(rnc).denominator);
    ( rncAdd(rnc, n6) );
    printf("rncSum %d / %d \n", rncSum(rnc).numerator, rncSum(rnc).denominator);
    ( rncAdd(rnc, n1) );
    printf("rncSum %d / %d \n", rncSum(rnc).numerator, rncSum(rnc).denominator);
    ( rncAdd(rnc, n1) );
    printf("rncSum %d / %d \n", rncSum(rnc).numerator, rncSum(rnc).denominator);
    ( rncAdd(rnc, n5) );
    printf("rncSum %d / %d \n", rncSum(rnc).numerator, rncSum(rnc).denominator);

    printf("rncTotalCount %d \n", rncTotalCount(rnc));
    printf("rncAverage %d / %d \n", rncAverage(rnc).numerator, rncAverage(rnc).denominator);

    printf("---Filling Array--- \n");
    fillArray(rnc,995);
    printf("rncTotalCount %d \n", rncTotalCount(rnc));
    printf("rncAverage %d / %d \n", rncAverage(rnc).numerator, rncAverage(rnc).denominator);

    printf(" successful!\n");

    return 0;
}


