class Movie{
public:
    static const int CHILDRENS = 2;
    static const int REGULAR = 0;
    static const int NEW_RELEASE = 1;

private:
    string mTitle;
    int mPriceCode;

public:
    Movie(string& title, int pricecode);
    Movie(const Movie& other);
    ~Movie();
    Movie& operator=(const Movie& other);

    int getPriceCode()const{return mPriceCode;}
    string getTitle()const{return mTitle;}
    void setPriceCode(int pricecode){mPriceCode = pricecode;}
};
