#ifndef OOPPROJECTS_PASSENGER_H
#define OOPPROJECTS_PASSENGER_H
#include <string>
using namespace std;

class Passenger {
    //make class Flight friend to class Passenger to access private data of class passenger
    friend class Flight;
    // overloading operator >>
    friend istream& operator>>(istream &is,  Passenger &p);
private:
    string passenger_name;
    int passenger_id;
    static int CountTotalPassengers; // number of all passengers in system
public:
    // default constructor
    Passenger();
    // 2 args constructor
    Passenger(string name, int id);
    //static function for the current total number of passengers
    static int get_No_Passengers();
    // get passenger name fn
    string getname()const;
    //Destructor
    ~Passenger();
    //Display passenger info
    void Display() const;
};



#endif //OOPPROJECTS_PASSENGER_H
