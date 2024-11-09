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
    const int columns = 4; // Assumption of number of seats Per row
    int rows = (seating_capacity / columns); //no of rows = capicity / no of columns

public:
    //3 args consturctor

    //Copy constructor

    //Add passengers to a flight

    //Search by name

    //Search by seat number

    //Operator prefix++

    //Operator postfix--

    //Operator +=

    //Operator -=

    //Remove passenger methode

    //Destructor

    //Display flight details
    void Display() const;

};



#endif //OOPPROJECTS_FLIGHT_H
