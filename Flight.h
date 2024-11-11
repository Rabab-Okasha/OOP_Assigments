#ifndef OOPPROJECTS_FLIGHT_H
#define OOPPROJECTS_FLIGHT_H
#include <string>
using namespace std;

class Flight {
    friend class Passenger;
    friend ostream &operator<<(ostream &os, const Flight &flight);
private:
    vate:
    int no_of_flights;
    int seating_capacity;
    int departure_time;
    string time_zone;
    string flight_dest;
    int **seating_plan;
    string** seating_names_plan;
    // make a 2d dynamic array to assign passengers names as will be assigned in seating plan
    string *passengers_names;
    static int CurrentNoBookedOfSeats;
    const int columns = 4; // Assumption of number of seats Per row
    int rows = (seating_capacity / columns); //no of rows = capicity / no of columns
    int booked_seats = 0;
    int counter_rows=0, counter_columns=0; //to know the index of the last added passenger


 public:

     Flight(string dest , int cap , int number);
     Flight &operator ++();
     Flight operator +=(Passenger & p);
     Flight operator --();
     Flight operator -=(int num);
     void search_passenger(string name);
     void Display() const;
     void add_passengers(int passengers_number, Passenger names_of_passenger[], Flight& f);
     friend ostream &operator<<(ostream &os, const Flight &flight);

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
    

};



#endif //OOPPROJECTS_FLIGHT_H
