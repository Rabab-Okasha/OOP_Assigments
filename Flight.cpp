#include "Flight.h"
#include "Passenger.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#include "Passenger.h"


// overload operator <<
ostream &operator<<(ostream &os, const Flight &flight){
    //Displaying the Seating plan
    cout << "\nSeating plan: " << endl;
    for (int i = 0; i < flight.rows; i++) {
        for (int j = 0; j < flight.columns; j++) {
            os << setw(5) << flight.seating_plan[i][j] << " ";
        }
        cout << endl;
    }
    //displaying passengers' names
    cout << "\nPassengers' names: "<<endl;
    for (int i = 0; i < flight.seating_capacity; i++) {
        if (!flight.passengers_names[i].empty()) {
            os << "Passanger " << i + 1 << ": " << flight.passengers_names[i] << endl;
        }
    }
    return os;
}

//parameterized constructor
Flight::Flight(string dest, int cap, int number)
{
    seating_capacity = cap;
    no_of_flights = number;
    flight_dest = dest;
    departure_time = "00:00";
    time_zone = " ";
    rows = seating_capacity / columns;
    if (seating_capacity % columns != 0) {
        rows++;}
    seating_plan = new int*[rows];
    for (int i = 0; i < rows; i++) {
        seating_plan[i] = new int[columns];
        for (int j = 0; j < columns; j++) {
            seating_plan[i][j] = 0;
        }}
    passengers_names = new string[seating_capacity];
}

//overload the prefix operator ++
Flight& Flight::operator++()
{
    ++rows;
    seating_capacity = rows * columns;
    int** temp = new int*[rows];
    for (int i = 0; i < rows - 1; i++) {
        temp[i] = seating_plan[i];
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

//operator +=
Flight& Flight::operator +=(Passenger & p)
{
 add_passengers(1, &p, *this);
  passengers_names[booked_seats]=p.getname();

    return *this;
}

// remove passenger by name
Flight & Flight::remove_passenger(Passenger &p2)
{
    for(int i=0;i<booked_seats ;i++)
    {
        if(passengers_names[i]==p2.getname())
        {
            for(int k=0;k<booked_seats-1;k++)
            {
                passengers_names[i]=passengers_names[i+1];
            }}

            }
  Passenger::CountTotalPassengers --;
  booked_seats--;
  return *this;

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

//add passenger
void Flight::add_passengers(int passengers_number, Passenger names_of_passenger[], Flight& f)
{
while (passengers_number > seating_capacity-booked_seats) {
        ++(*this);
        add_passengers(passengers_number, names_of_passenger, f);
    }

    for (int i = 0; i < rows && passengers_number > 0; i++) {
        for (int j = 0; j < columns && passengers_number > 0; j++) {
            if (seating_plan[i][j] == 0) {
                seating_plan[i][j] = 1;
                passengers_names[booked_seats] = names_of_passenger[booked_seats].getname();
                booked_seats++;
                Passenger::CountTotalPassengers ++;
                passengers_number--;
            }}}}

//display flight details
void Flight::Display() const {
      //Displaying flight details
    cout << "\nFlight Details: " << endl;
    cout << "------------------------------";
    cout << "\nNumber of flight: " << setw(8) << no_of_flights;
    cout << "\nSeating capacity: " << setw(8) << seating_capacity;
    cout << "\nDeparture Time: " << setw(10) << departure_time << " " << time_zone;
    cout << "\nDestination: " << setw(13) << flight_dest << "\n------------------------------" << endl;
}

//operator postfix--
Flight Flight::operator--(int){
    Flight temp = *this;
    temp.booked_seats--;
    Passenger::CountTotalPassengers--;
    int r = temp.booked_seats / columns;
    int c = temp.booked_seats % columns;
    temp.seating_plan[r][c] = 0;
    return temp;
}

//Operator -=
Flight &Flight::operator-=(int num){
    for(int i = 0; i < num && (Passenger::CountTotalPassengers > 0); i++){
        booked_seats--;
        Passenger::CountTotalPassengers--;
        int r = booked_seats / columns;
        int c = booked_seats % columns;
        seating_plan[r][c] = 0;
    }
    return *this;
}
   //Copy constructor
Flight::Flight(const Flight &obj) {
    no_of_flights = obj.no_of_flights;
    seating_capacity = obj.seating_capacity;
    departure_time = obj.departure_time;
    time_zone = obj.time_zone;
    flight_dest = obj.flight_dest;
    rows = obj.rows;
    if (seating_capacity % columns != 0)
        rows++;
    seating_plan = new int *[rows];
    for (int i = 0; i < rows; i++) {
        seating_plan[i] = new int[columns];
        for (int j = 0; j < columns; j++)
            seating_plan[i][j] = obj.seating_plan[i][j];
    }
    passengers_names = new string[seating_capacity];
    for (int i = 0; i < seating_capacity; i++)
        passengers_names[i] = obj.passengers_names[i];
    // increase numnber of passengers in the system by double number of passengers in the 1st object
    Passenger::CountTotalPassengers *= 2;
}

//Destructor
Flight::~Flight()
{
    for(int i = 0; i < rows; i++)
        delete [] seating_plan[i];
    delete [] seating_plan;
    delete [] passengers_names;
}
