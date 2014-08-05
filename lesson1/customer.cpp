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
        frequentRenterPoints += it->getFrequentRenterPoints();

        result += "\t";
        result += it->getMovie().getTitle();
        result += "\t";
        result += do_fraction(it->getCharge());
        result += "\n";
        
        totalAmount += it->getCharge();
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
