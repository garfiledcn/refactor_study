#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "movie.h"
#include "rental.h"
#include "customer.h"

int main(int argc, char** argv)
{
	string title("gump");
	string cus("lufei");
	Movie mov1(title, 10);
	Rental rent1(mov1, 3);
	Customer lf(cus);

	lf.addRental(rent1);
	cout<<lf.statement()<<endl;
}
