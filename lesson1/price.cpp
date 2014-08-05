#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

#include "movie.h"
#include "price.h"

double ChildrensPrice::getCharge(int daysrented)
{
	double result = 1.5;
	if (daysrented > 3)
		result += (daysrented-3)*1.5;

	return result;
}

double RegularPrice::getCharge(int daysrented)
{
	double result = 2;
	if (daysrented > 2)
		result += (daysrented-2)*1.5;

	return result;
}

double NewReleasePrice::getCharge(int daysrented)
{
	double result = 0;
	result += daysrented*3;
	return result;
}

int NewReleasePrice::getFrequentRenterPoints(int daysrented)
{
	return (daysrented>1)?2:1;
}
