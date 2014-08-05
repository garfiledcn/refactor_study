#include <iostream>
#include <string>
using namespace std;

#include "movie.h"
#include "rental.h"

Rental::Rental(Movie& movie, int daysrented)
	: mMovie(movie),
	  mDaysRented(daysrented)
{
	cout<<"["<<__PRETTY_FUNCTION__<<", "<<__LINE__<<"]"<<endl;
}

Rental::~Rental()
{
	cout<<"["<<__PRETTY_FUNCTION__<<", "<<__LINE__<<"]"<<endl;
}

Rental::Rental(const Rental&other)
	:mMovie(other.mMovie),
	 mDaysRented(other.mDaysRented)
{
	cout<<"["<<__PRETTY_FUNCTION__<<", "<<__LINE__<<"]"<<endl;
}

Rental& Rental::operator=(const Rental& other)
{
	cout<<"["<<__PRETTY_FUNCTION__<<", "<<__LINE__<<"]"<<endl;
	mMovie = other.mMovie;
	mDaysRented = other.mDaysRented;
}

Movie& Rental::getMovie()
{
	return mMovie;
}

double Rental::getCharge()
{
	double result = 0.0;
	switch(getMovie().getPriceCode()) {
		case Movie::REGULAR:
			result += 2;
			if (getDaysRented() > 2)
				result += (getDaysRented() - 2) * 1.5;
			break;
		case Movie::NEW_RELEASE:
			result += getDaysRented() * 3;
			break;
		case Movie::CHILDRENS:
			result += 1.5;
			if (getDaysRented() > 3)
				result += (getDaysRented() - 3) * 1.5;
			break;
		default:
			cout<<"should never reached"<<endl;
			break;
	}
	return result;
}

int Rental::getFrequentRenterPoints()
{
	if ((getMovie().getPriceCode() == Movie::NEW_RELEASE) && 
			getDaysRented() > 1)
		return 2;
	else
		return 1;
}
