#include "Flight.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//initialize the static variable
int Flight::CurrentNoBookedOfSeats = 0;

//3 args constructor
Flight::Flight(string dest, int cap, int number){
    seating_capacity = cap;
    no_of_flights = number;
    flight_dest = dest;
    rows = seating_capacity / columns;
    if (seating_capacity % columns != 0) {
        rows++;}
    seating_plan = new int*[rows];
    for (int i = 0; i < rows; i++) {
        seating_plan[i] = new int[columns];
        for (int j = 0; j < columns; j++) {
            seating_plan[i][j] = 0;
        }
    }
    passengers_names = new string[seating_capacity];
}

//overload the prefix operator ++ 
Flight& Flight::operator++()
{
    ++rows;
    int** temp = new int*[rows];
     for (int i = 0; i < rows - 1; i++) {
         temp[i] = new int[columns];
     for (int j = 0; j < columns; j++)
        {
         temp[i][j] = seating_plan[i][j];
            }
     }
temp[rows - 1] = new int[columns];
for (int j = 0; j < columns; j++) {
    temp[rows - 1][j] = 0;
}
for (int i = 0; i < rows - 1; i++) {
    delete[] seating_plan[i];
}
delete[] seating_plan;
seating_plan = temp;
    return *this;
}

// overload += operator 
Flight& Flight::operator +=(Passenger & p){
 add_passengers(1, &p, *this);
  passengers_names[booked_seats]=p.getname();
    return *this;
}

//Add passegners method
void Flight::add_passengers(int passengers_number, Passenger names_of_passenger[], Flight& f)
{
    for (int i = 0; i < rows && passengers_number > 0; i++) {
        for (int j = 0; j < columns && passengers_number > 0; j++) {
            if (seating_plan[i][j] == 0) {
                seating_plan[i][j] = 1;
                passengers_names[booked_seats] = names_of_passenger[booked_seats].getname();
                booked_seats++;
                passengers_number--;
            }}}
if (passengers_number > seating_capacity) {
        ++(*this);
        add_passengers(passengers_number, names_of_passenger, f);
    }
}

//Search by passenger's name
bool Flight::search_name(string nm){
    for(int i = 0; i < seating_capacity; i++){
        if(passengers_names[i] == nm) {
            cout << "Passanger is on the flight" << endl;
            return true;
        }
    }
    cout << "Passanger is Not on the flight" << endl;
    return false;
}

//Search by seat number
void Flight::search_seatNo(int r, int c){
    if(r >= 0 && r < rows && c >= 0 && c < columns){
        if(seating_plan[r][c] == 0)
            cout << "Seat is Not Booked" << endl;
        else
            cout << "Seat is Booked" << endl;
    }else
        cout << "Invalid seat number!" << endl;
}

//Display method

void Flight::Display() const {
      //Displaying flight details
    cout << "Flight Details: " << endl;
    cout << "------------------------------";
    cout << "\nNumber of flight: " << setw(8) << no_of_flights;
    cout << "\nSeating capacity: " << setw(8) << seating_capacity;
    cout << "\nDeparture Time: " << setw(10) << departure_time << " " << time_zone;
    cout << "\nDestination: " << setw(13) << flight_dest;
    cout << "\nSeating plan: \n";
    //Displaying the Seating plan
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << setw(5) << seating_plan[i][j] << " ";
        }
        cout << endl;
    }
    
 //displaying passengers' names
    cout << "\nPassengers' names: "<<endl;
    for (int i = 0; i < seating_capacity; i++) {
        if (!passengers_names[i].empty()) {
            cout << "Passanger " << i + 1 << ": " << passengers_names[i]<<endl;
        }
    }
}

//Destructor
Flight::~Flight(){
    for(int i = 0; i < rows; i++)
        delete [] seating_plan[i];
    delete [] seating_plan;
    delete [] passengers_names;
}
