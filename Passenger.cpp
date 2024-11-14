#include "Passenger.h"
#include <string>


// Initialize the static variable
int Passenger::CountTotalPassengers = 0;

// Default constructor
Passenger::Passenger() {}

// Constructor with two arguments
Passenger::Passenger(string name, int id){
     // initializing private variables
     passenger_name = name;
     passenger_id = id;
}

// Static function to get current total number of passengers
int Passenger::get_noPassenger() {
    return CountTotalPassengers;
}

// Get passenger name
string Passenger::getname() const {
    return passenger_name;
}

// Insertion operator overload
istream &operator>>(istream &is, Passenger &p) {
    // taking passenger name and initializing it to private variable
    cout << "Enter Passenger name : ";
    is >> p.passenger_name;
    // taking passenger ID and initializing it to private variable
    cout << "Enter Passenger ID : ";
    is >> p.passenger_id;
    return is;
}

// Destructor
Passenger::~Passenger() {
    //for each destroyed passenger object decrement the total number of passengers
    CountTotalPassengers--;
    //massage that indicates the object has been destroyed
    cout << "Destructor of Passenger class has been called" << endl;
}

// Display passenger's info
void Passenger::Display() const {
    cout << "\nPassenger's name: " << passenger_name
         << "\nPassenger's ID: " << passenger_id << endl;
}

