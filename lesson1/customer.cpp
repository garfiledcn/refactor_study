#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "movie.h"
#include "rental.h"
#include "customer.h"

Customer::Customer(string& name)
	: mName(name)
{
	cout<<"["<<__func__<<", "<<__LINE__<<"]"<<endl;
}

Customer::~Customer()
{
	cout<<"["<<__func__<<", "<<__LINE__<<"]"<<endl;
}

Customer::Customer(Customer& other)
	:mName(other.mName)
{
	cout<<"["<<__func__<<", "<<__LINE__<<"]"<<endl;
}

Customer& Customer::operator=(Customer& other)
{
	mName = other.mName;
}

string Customer::statement()
{
	return string("mytest");
}
