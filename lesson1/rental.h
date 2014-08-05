class Movie;

class Rental{
private:
    Movie mMovie;
    int mDaysRented;

public:
    Rental(Movie& movie, int daysrented);
    Rental(const Rental&);
    ~Rental();
    Rental& operator=(const Rental& other);

    int getDaysRented() const {return mDaysRented;}
    Movie& getMovie() ;

    double getCharge();
};
