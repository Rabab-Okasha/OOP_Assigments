#ifndef OOPPROJECTS_FLIGHT_H
#define OOPPROJECTS_FLIGHT_H
#include <string>
using namespace std;

class Flight {
    friend class Passenger;
    friend ostream &operator<<(ostream &os, const Flight &flight);
private:
    vate:
    int no_of_flight;
    int seating_capacity;
    int departure_time;
    string time_zone;
    string flight_dest;
    int **seating_plan;
    // make a 2d dynamic array to assign passengers names as will be assigned in seating plan
    string** seating_names_plan;
    string *passengers_names;
    static int CurrentNoBookedOfSeats;
    const int columns = 4; // Assumption of number of seats Per row
    int rows = (seating_capacity / columns); //no of rows = capicity / no of columns
    int booked_seats = 0;
    int counter_rows=0, counter_columns=0; //to know the index of the last added passenger


 public:
     //3 args consturctor
     Flight(string dest , int cap , int number);
     //Operator prefix++
     Flight &operator ++();
     //Operator +=
     Flight operator +=(Passenger & p);
     //Operator postfix--
     Flight operator --();
     //Operator -=
     Flight operator -=(int num);
     //Search by name
     void search_passenger(string name);
     //Display flight details
     void Display() const;
     //Add passengers to a flight
     void add_passengers(int passengers_number, Passenger names_of_passenger[], Flight& f);

    //Copy constructor
 

    //Search by seat number

    //Remove passenger methode

    //Destructor

};



#endif //OOPPROJECTS_FLIGHT_H
