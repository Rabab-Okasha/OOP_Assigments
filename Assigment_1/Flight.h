#ifndef OOPPROJECTS_FLIGHT_H
#define OOPPROJECTS_FLIGHT_H
#include <string>
using namespace std;

class Flight {
    friend class Passenger;
    friend ostream &operator<<(ostream &os, const Flight &flight);
private:
    int no_of_flights;
    int seating_capacity;
    int departure_time;
    string time_zone;
    string flight_dest;
    int **seating_plan;
    string *passengers_names;
    static int CurrentNoBookedOfSeats;
    const int no_of_rows = 4;
public:

};



#endif //OOPPROJECTS_FLIGHT_H
