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
public:
        // 2 args constructor
        Passenger(string name, int id);
  
};



#endif //OOPPROJECTS_PASSENGER_H
