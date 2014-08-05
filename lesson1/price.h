class Movie;

class Price{
public:
    Price(){};
    virtual int getPriceCode() = 0;
    ~Price(){}
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
    ~NewReleasePrice(){}
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
    ~RegularPrice(){}
private:
    RegularPrice(RegularPrice&);
    RegularPrice& operator=(const RegularPrice&);
};
