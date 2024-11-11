#include "Passenger.h"
#include <string>

//initialize the static variable
int Passenger::CountTotalPassengers = 0;
//2 args Constructor
Passenger::Passenger(string name, int id)
{
    passenger_name = name;
    passenger_id = id;
    CountTotalPassengers++;
}

// insertion operator friend funcion >>
istream &operator>>(istream &is ,  Passenger &p )
{
   cout << "\nEnter your name : ";
   is >> p.passenger_name;
   cout << "\nEnter your ID : ";
   is >> p.passenger_id;
}

//Destructor

//static function for the current total number of passengers

//Display passenger's info
void Passenger::Display() const{
    cout << "\nPassenger's name: " << passenger_name << "\nPassenger's ID: " << passenger_id << endl;
}


