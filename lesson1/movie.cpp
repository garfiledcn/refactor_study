#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

#include "movie.h"
#include "price.h"

Movie::Movie(string& title, int pricecode)
	:mTitle(title),
	 mPrice(NULL)
{
	cout<<"["<<__PRETTY_FUNCTION__<<", "<<__LINE__<<"]"<<endl;
	setPriceCode(pricecode);
}

Movie::Movie(const Movie& other)
	:mTitle(other.mTitle),
	 mPrice(NULL)
{
	cout<<"["<<__PRETTY_FUNCTION__<<", "<<__LINE__<<"]"<<endl;
	setPriceCode(other.getPriceCode());
}

Movie::~Movie()
{
	cout<<"["<<__PRETTY_FUNCTION__<<", "<<__LINE__<<"]"<<endl;
}

Movie& Movie::operator=(const Movie& other)
{
	mTitle = other.mTitle;
	setPriceCode(other.getPriceCode());
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

void Movie::setPriceCode(int pricecode)
{
	if (mPrice){
		delete mPrice;
		mPrice = NULL;
	}
	switch (pricecode) {
		case REGULAR:
			mPrice = new RegularPrice();
			break;
		case CHILDRENS:
			mPrice = new ChildrensPrice();
			break;
		case NEW_RELEASE:
			mPrice = new NewReleasePrice();
			break;
		default:
			assert(false);
	}
}

int Movie::getPriceCode() const 
{
    assert (mPrice);

    return mPrice->getPriceCode();
}
