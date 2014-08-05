class Price;

class Movie{
public:
    static const int CHILDRENS = 2;
    static const int REGULAR = 0;
    static const int NEW_RELEASE = 1;

private:
    string mTitle;
    Price* mPrice;
public:
    Movie(string& title, int pricecode);
    Movie(const Movie& other);
    ~Movie();
    Movie& operator=(const Movie& other);

    int getPriceCode()const;
    string getTitle()const{return mTitle;}
    void setPriceCode(int pricecode);
    double getCharge(int daysrented);
    int getFrequentRenterPoints(int daysrented);
};
