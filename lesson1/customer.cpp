#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
using namespace std;

#include "movie.h"
#include "rental.h"
#include "customer.h"

Customer::Customer(string& name)
	: mName(name)
{
	cout<<"["<<__PRETTY_FUNCTION__<<", "<<__LINE__<<"]"<<endl;
}

Customer::~Customer()
{
	cout<<"["<<__PRETTY_FUNCTION__<<", "<<__LINE__<<"]"<<endl;
}

Customer::Customer(Customer& other)
	:mName(other.mName)
{
	cout<<"["<<__PRETTY_FUNCTION__<<", "<<__LINE__<<"]"<<endl;
}

Customer& Customer::operator=(Customer& other)
{
	mName = other.mName;
}

char DECIMAL_POINT='.';
string do_fraction(double value, int decplaces=3)
{
    ostringstream out;
    int prec=numeric_limits<int>::digits10;

    out.precision(prec);
    out<<value;
    string str= out.str();
    size_t n=str.find(DECIMAL_POINT);
    if ((n!=string::npos) && (str.size()> n+decplaces)) {
        str[n+decplaces]='\0';
    }

    //str.swap(string(str.c_str()));

    return str;
}

double Customer::amountFor(Rental& each)
{
	double thisAmount = 0.0;
	switch(each.getMovie().getPriceCode()) {
		case Movie::REGULAR:
			thisAmount += 2;
			if (each.getDaysRented() > 2)
				thisAmount += (each.getDaysRented() - 2) * 1.5;
			break;
		case Movie::NEW_RELEASE:
			thisAmount += each.getDaysRented() * 3;
			break;
		case Movie::CHILDRENS:
			thisAmount += 1.5;
			if (each.getDaysRented() > 3)
				thisAmount += (each.getDaysRented() - 3) * 1.5;
			break;
		default:
			cout<<"should never reached"<<endl;
			break;
	}
	return thisAmount;
}

string Customer::statement()
{
    double totalAmount = 0;
    int frequentRenterPoints = 0;
    string result("Rental Record for ");

    result += getName();
    result += "\n";

    vector<Rental>::iterator it = mRentals.begin();
    vector<Rental>::iterator end = mRentals.end();

    while(it != end){
        double thisAmount = 0;
        thisAmount = amountFor(*it);
		
        frequentRenterPoints ++;
        if (it->getMovie().getPriceCode() == Movie::NEW_RELEASE && 
                it->getDaysRented() > 1)
            frequentRenterPoints ++;

        result += "\t";
        result += it->getMovie().getTitle();
        result += "\t";
        result += do_fraction(thisAmount);
        result += "\n";
        
        totalAmount += thisAmount;
        ++it;
    }
    
    result += "Amount owed is:";
    result += do_fraction(totalAmount);
    result += "\n";

    result += "You earned:";
    result += do_fraction(static_cast<double>(frequentRenterPoints));
    result += " frequent renter points";
    return result;
}
