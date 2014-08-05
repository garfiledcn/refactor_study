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
	return mMovie.getCharge(getDaysRented());
}

int Rental::getFrequentRenterPoints()
{
	return mMovie.getFrequentRenterPoints(getDaysRented());
}
