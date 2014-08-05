#include <iostream>
#include <string>
using namespace std;

#include "movie.h"

Movie::Movie(string& title, int pricecode)
	:mTitle(title),
     mPriceCode(pricecode)
{
	cout<<"["<<__PRETTY_FUNCTION__<<", "<<__LINE__<<"]"<<endl;
}

Movie::Movie(const Movie& other)
	:mTitle(other.mTitle),
	 mPriceCode(other.mPriceCode)
{
	cout<<"["<<__PRETTY_FUNCTION__<<", "<<__LINE__<<"]"<<endl;
}

Movie::~Movie()
{
	cout<<"["<<__PRETTY_FUNCTION__<<", "<<__LINE__<<"]"<<endl;
}

Movie& Movie::operator=(const Movie& other)
{
	mTitle = other.mTitle;
	mPriceCode = other.mPriceCode;
}

double Movie::getCharge(int daysrented)
{
	double result = 0.0;
	switch(getPriceCode()) {
		case REGULAR:
			result += 2;
			if (daysrented > 2)
				result += (daysrented - 2) * 1.5;
			break;
		case NEW_RELEASE:
			result += daysrented * 3;
			break;
		case CHILDRENS:
			result += 1.5;
			if (daysrented > 3)
				result += (daysrented - 3) * 1.5;
			break;
		default:
			cout<<"should never reached"<<endl;
			break;
	}
	return result;
	
}

int Movie::getFrequentRenterPoints(int daysrented)
{
	if ((getPriceCode() == Movie::NEW_RELEASE) && 
			daysrented > 1)
		return 2;
	else
		return 1;
	
}
