#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "movie.h"
#include "rental.h"
#include "customer.h"

typedef struct movie_info {
    char* name;
    int   type;
} MovieInfo;

MovieInfo movies[] = {
    {"gump", 0},
    {"iron_man", 2},
    {"super_man", 1},
    {"transformer1", 1},
    {"Thunder", 0},
    {"Harry_Potter", 0},
    {NULL, -1}
};


int main(int argc, char** argv)
{
	string cus("lufei");
	Customer lf(cus);

    MovieInfo* info = movies;
    while(info && info->name) {
        string moviename(info->name);
        Movie* movie= new Movie(moviename, info->type);
        Rental* ret = new Rental(*movie, 5);
	    lf.addRental(*ret);
        ++info;
    }
	cout<<lf.statement()<<endl;
}
