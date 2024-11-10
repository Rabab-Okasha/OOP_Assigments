#ifndef OOPPROJECTS_PASSENGER_H
#define OOPPROJECTS_PASSENGER_H
#include <string>
using namespace std;

class Passenger {
 private:
        string passenger_name;
        int passenger_id;

    public:
        Passenger(string name , int id);
   friend istream& operator>>(istream &is ,  Passenger &p );

    friend class Flight;

};



#endif //OOPPROJECTS_PASSENGER_H
