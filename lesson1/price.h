class Movie;

class Price{
public:
    Price(){};
    virtual int getPriceCode() = 0;
    ~Price(){}
	virtual double getCharge(int) = 0;
    virtual int getFrequentRenterPoints(int daysrented) {return 1;}
private:
    Price(Price&);
    Price& operator=(const Price&);
};

class  ChildrensPrice : public Price
{
public:
    ChildrensPrice(){};
    virtual int getPriceCode(){
        return Movie::CHILDRENS;
    }
    ~ChildrensPrice(){}
	virtual double getCharge(int);
private:
    ChildrensPrice(ChildrensPrice&);
    ChildrensPrice& operator=(const ChildrensPrice&);
};

class NewReleasePrice: public Price
{
public:
    NewReleasePrice(){};
    virtual int getPriceCode(){
        return Movie::NEW_RELEASE;
    }
	virtual double getCharge(int);
    ~NewReleasePrice(){}
    virtual int getFrequentRenterPoints(int daysrented) ;
private:
    NewReleasePrice(NewReleasePrice&);
    NewReleasePrice& operator=(const NewReleasePrice&);
};

class RegularPrice: public Price
{
public:
    RegularPrice(){};
    virtual int getPriceCode() {
        return Movie::REGULAR;
    }
	virtual double getCharge(int);
    ~RegularPrice(){}
private:
    RegularPrice(RegularPrice&);
    RegularPrice& operator=(const RegularPrice&);
};
