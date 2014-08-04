#include <iostream>
#include <string>
using namespace std;

#include "movie.h"
#include "rental.h"

Rental::Rental(Movie& movie, int daysrented)
	: mMovie(movie),
	  mDaysRented(daysrented)
{
	cout<<"["<<__func__<<", "<<__LINE__<<"]"<<endl;
}

Rental::~Rental()
{
	cout<<"["<<__func__<<", "<<__LINE__<<"]"<<endl;
}

Rental::Rental(const Rental&other)
	:mMovie(other.mMovie),
	 mDaysRented(other.mDaysRented)
{
	cout<<"["<<__func__<<", "<<__LINE__<<"]"<<endl;
}

Rental& Rental::operator=(const Rental& other)
{
	cout<<"["<<__func__<<", "<<__LINE__<<"]"<<endl;
	mMovie = other.mMovie;
	mDaysRented = other.mDaysRented;
}

Movie& Rental::getMovie()
{
	return mMovie;
}
