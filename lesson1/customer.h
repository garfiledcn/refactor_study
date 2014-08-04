class Rental;
class Movie;

class Customer{
private:
    string mName;
    vector<Rental> mRentals;
    Customer();
public:
    Customer(string& name);
    ~Customer();
    Customer(Customer& other);
    Customer& operator=(Customer& other);

    string getName(){return mName;}
    void addRental(Rental& arg) { mRentals.push_back(arg); }

    string statement();
};
