#include "Passenger.h"
#include <string>

//initialize the static variable

//2 args Constructor

Passenger::Passenger(string name , int id )
{
    passenger_name = name;
    passenger_id = id;
}
istream &operator>>(istream &is ,  Passenger &p )
{
   cout<<"Enter your name : ";
   is>>p.passenger_name;
   cout<<"Enter your id : ";
   is>>p.passenger_id;
}

//Destructor

//static function for the current total number of passengers

//Display passenger's info
void Passenger::Display() const{
    cout << "Passenger's name: " << name << "\nPassenger's ID: " << ID << endl;
}

// insertion operator friend funcion >>
