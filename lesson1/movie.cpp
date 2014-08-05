#include <iostream>
#include <string>
using namespace std;

#include "movie.h"

Movie::Movie(string& title, int pricecode)
	:mTitle(title),
     mPriceCode(pricecode)
{
	cout<<"["<<__FUNCTION__<<", "<<__LINE__<<"]"<<endl;
}

Movie::Movie(const Movie& other)
	:mTitle(other.mTitle),
	 mPriceCode(other.mPriceCode)
{
	cout<<"["<<__func__<<", "<<__LINE__<<"]"<<endl;
}

Movie::~Movie()
{
	cout<<"["<<__func__<<", "<<__LINE__<<"]"<<endl;
}

Movie& Movie::operator=(const Movie& other)
{
	mTitle = other.mTitle;
	mPriceCode = other.mPriceCode;
}
