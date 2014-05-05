#ifndef RATIONALNUMBERCOLLECTION_H
#define RATIONALNUMBERCOLLECTION_H

#include "rationalnumber.h"

/*
 * Tupel which contains a rational number and a int for counting
 * how often this rational number is contained in the
 * rational number collection
*/
struct RationalNumberWithCounter
{
    RationalNumber rn;
    int counter;
};

/*
 * collection which contains an array of raional numbers with counters,
 * the length of that array, the sum of all rational numbers in that array
 * and the number how many rational numbers are in the collection
 */
struct RationalNumberCollection
{
    RationalNumberWithCounter rnwc[1000];
    int length;
    RationalNumber totalSum;
    int totalCount;
};

// initialises a rational number collection
void rncInit(RationalNumberCollection* rnc);

// adds a rational number to the collection
void rncAdd(RationalNumberCollection* rnc, RationalNumber rn);

// removes a rational number one time from the collection
void rncRemove(RationalNumberCollection* rnc, RationalNumber rn);

// returns the index of a rational number in the collection ( -1 when not in the collection)
int rncContainsAt(RationalNumberCollection* rnc, RationalNumber rn);

// returns how often the given rational number is in the collection
int rncCount(RationalNumberCollection* rnc, RationalNumber rn);

// returns how many different rational numbers are in the collection
int rncTotalUniqueCount(RationalNumberCollection* rnc);

// returns how many rational numbers are in the collection
int rncTotalCount(RationalNumberCollection* rnc);

// returns the sum of all rational number in the collection
RationalNumber rncSum(RationalNumberCollection* rnc);

// returns the average of all rational numbers in the collection
RationalNumber rncAverage(RationalNumberCollection* rnc);


#endif // RATIONALNUMBERCOLLECTION_H
