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
	assert (mPrice);
	return mPrice->getCharge(daysrented);
}

int Movie::getFrequentRenterPoints(int daysrented)
{
	assert (mPrice);
    return mPrice->getFrequentRenterPoints(daysrented);
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
