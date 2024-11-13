#include "Passenger.h"
#include <string>

//initialize the static variable
int Passenger::CountTotalPassengers = 0;
// default constructor 
Passenger::Passenger(){}

//2 args Constructor
Passenger::Passenger(string name , int id )
{
    passenger_name = name;
    passenger_id = id;
    CountTotalPassengers++;
}

//static function for the current total number of passengers
int Passenger::get_noPassenger(){
    return CountTotalPassengers;
}

//get passenger name
string Passenger::getname ()const
{
    return passenger_name;
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
Passenger::~Passenger(){
    CountTotalPassengers--;
    cout << "Destructor of Passenger class has been called" << endl;
}

//Display passenger's info
void Passenger::Display() const{
    cout << "\nPassenger's name: " << passenger_name << "\nPassenger's ID: " << passenger_id << endl;
}


