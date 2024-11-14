#ifndef OOPPROJECTS_PASSENGER_H
#define OOPPROJECTS_PASSENGER_H
#include <string>
using namespace std;

class Passenger {
// add class Flight as a friend class to access member functions in Flight class
    friend class Flight;
    // overloading operator >>
    friend istream& operator>>(istream &is ,  Passenger &p );
    private:
        string passenger_name;
        int passenger_id;
    public:
        static int CountTotalPassengers;
        // default constructor
        Passenger();
        // 2 args constructor
        Passenger(string name , int id);
        // get passenger name fn
        string getname()const;
        //static function for the current total number of passengers
        static int get_noPassenger();
        //Display passenger info
        void Display()const;
        //Destructor
        ~Passenger();

  
};



#endif //OOPPROJECTS_PASSENGER_H
