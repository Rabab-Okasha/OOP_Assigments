#ifndef OOPPROJECTS_PASSENGER_H
#define OOPPROJECTS_PASSENGER_H
#include <string>
using namespace std;

class Passenger {
friend class Flight;
friend istream& operator>>(istream &is,  Passenger &p);
 private:
    string passenger_name;
    int passenger_id;
    static int CountTotalPassengers;
public:
     // default constructor 
     Passenger();
     // 2 args constructor
     Passenger(string name, int id);
    //static function for the current total number of passengers
    static int get_noPassengers();
    // get passenger name fn 
      string getname()const;
    //Destructor
    ~Passenger();
    //Display passenger info
    void Display() const;
  
};



#endif //OOPPROJECTS_PASSENGER_H
