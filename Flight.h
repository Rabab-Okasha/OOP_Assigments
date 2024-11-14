#ifndef OOPPROJECTS_FLIGHT_H
#define OOPPROJECTS_FLIGHT_H
#include <string>
#include "Passenger.h"
using namespace std;

class Flight {
friend ostream &operator<<(ostream &os, const Flight &flight);
 private:
    int no_of_flights;//number of the flight
    int seating_capacity;// capacity
    string departure_time;
    string time_zone;
    string flight_dest;
    int **seating_plan;// array of seats
    string *passengers_names;// array of passenger names
    const int columns = 4; // Assumption of number of seats Per row
    int rows = (seating_capacity / columns); //no of rows = capacity / no of columns
    int booked_seats = 0;


 public:
     //3 args consturctor
     Flight(string dest , int cap , int number);
     //Operator prefix++
     Flight &operator ++();
      //Operator +=
     Flight &operator +=(Passenger & p);
     //Operator postfix--
     Flight operator --(int);
     //Operator -=
     Flight &operator -=(int num);
     //Remove passenger methode
     Flight &remove_passenger(Passenger &p2);
     //Search by name
     bool search_name(string nm);
     //Search by seat number
     void search_seatNo(int r, int c);
     //Add passengers to a flight
     void add_passengers(int passengers_number, Passenger names_of_passenger[]);
     //Display flight details
     void Display() const;
     //Copy constructor
     Flight(const Flight &obj);
     //Destructor
     ~Flight();
};



#endif //OOPPROJECTS_FLIGHT_H
