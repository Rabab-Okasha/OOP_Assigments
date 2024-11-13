#ifndef OOPPROJECTS_FLIGHT_H
#define OOPPROJECTS_FLIGHT_H
#include <string>
#include "Passenger.h"
using namespace std;

class Flight {
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
     //Add passengers to a flight
     void add_passengers(int passengers_number, Passenger names_of_passenger[], Flight& f);
     //Search by name
     bool search_name(string nm);
     //Search by seat number
     void search_seatNo(int r, int c);
     //Display flight details
     void Display() const;
     //Destructor
     ~Flight();
    //Copy constructor


    //Remove passenger methode
};



#endif //OOPPROJECTS_FLIGHT_H
