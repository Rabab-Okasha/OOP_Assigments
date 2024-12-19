#include "Flight.h"
#include "Passenger.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

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
    cout << "\nPassengers' names: " << endl;
    for (int i = 0; i < flight.booked_seats; i++) {
        // if names of passengers is not empty
        if (!flight.passengers_names[i].empty()) {
            os << "Passanger " << i + 1 << ": " << flight.passengers_names[i] << endl;
        }
    }
    return os;
}

//3 args constructor
Flight::Flight(string dest, int cap, int number){
    seating_capacity = cap;
    no_of_flight = number;
    flight_dest = dest;
    departure_time = "00:00";
    time_zone = "KSA";
    rows = seating_capacity / columns;
    //if capacity is decimal, add a new row by rounding it up
    if (seating_capacity % columns != 0)
        rows++;
    // initializing rows in array of seats (seating_capacity)
    seating_plan = new int*[rows];
    // for each row initializing columns
    for (int i = 0; i < rows; i++) {
        seating_plan[i] = new int[columns];
        for (int j = 0; j < columns; j++)
            // assigning each index to 0
            seating_plan[i][j] = 0;
    }
    // initializing array of passengers
    passengers_names = new string[seating_capacity];
}

//Add passegners method
void Flight::add_passengers(int passengers_number, Passenger names_of_passenger[]){
    //to check that their is available (unbooked) seats
    while (passengers_number > seating_capacity - booked_seats){
        //if there is not enought unbooked seats, create a new row
        ++(*this);
        add_passengers(passengers_number, names_of_passenger);
    }
    for (int i = 0; i < rows && passengers_number > 0; i++) {
        for (int j = 0; j < columns && passengers_number > 0; j++){
            //make the seat booked
            if (seating_plan[i][j] == 0) {
                seating_plan[i][j] = 1;
                // add the new passenger name to the list of passengers' names
                passengers_names[booked_seats] = names_of_passenger[booked_seats].getname();
                //increment number of booked seats in the flight
                booked_seats++;
                //decrement number of the new passengers
                passengers_number--;
                //increment number of passengers in system
                Passenger::CountTotalPassengers++;
            }
        }
    }
}

//Remove passenger methode
Flight & Flight::remove_passenger(Passenger &p2){
    bool status = false;
    //get index of the passenger to be removed
    for(int i = 0; i < booked_seats; i++){
        if(passengers_names[i] == p2.passenger_name){
            status = true;
            //shift elements to the left
            for(int j = i; j < booked_seats - 1; j++)
                passengers_names[j] = passengers_names[j + 1];
            break;
        }
    }
    if(status){
        //update the seating plan after removing passenger
        int r = (booked_seats - 1) / columns;
        int c = (booked_seats - 1) % columns;
        seating_plan[r][c] = 0;
        //decrement total number of passengers and number of booked seats
        Passenger::CountTotalPassengers--;
        booked_seats--;
    }
    return *this;
}

//Search by passenger's name
bool Flight::search_name(string nm){
    for(int i = 0; i < seating_capacity; i++){
        //search for the passenger name in list of passengers names
        if(passengers_names[i] == nm) {
            cout << "Passanger " << nm << " is on the flight" << endl;
            return true;
        }
    }
    cout << "Passanger " << nm << " is Not on the flight" << endl;
    return false;
}

//Search by seat number
void Flight::search_seatNo(int r, int c){
    if(r >= 0 && r < rows && c >= 0 && c < columns){
        if(seating_plan[r][c] == 0)
            cout << "\nSeat " << r << c << " is Not Booked" << endl;
        else
            cout << "\nSeat " << r << c << " is Booked" << endl;
    }else
        //if seat number is not in the seating plan matrix
        cout << "\nSeat number " << r << c << " is invalid!!" << endl;
}

//Display method
void Flight::Display() const {
    //Displaying flight details
    cout << "\nFlight Details: " << endl;
    cout << "------------------------------";
    cout << "\nNumber of flight: " << setw(8) << no_of_flight;
    cout << "\nSeating capacity: " << setw(8) << seating_capacity;
    cout << "\nDeparture Time: " << setw(10) << departure_time << " " << time_zone;
    cout << "\nDestination: " << setw(13) << flight_dest << "\n------------------------------" << endl;
}

//overload the prefix operator ++
Flight& Flight::operator++(){
    ++rows;
    // updating capacity
    seating_capacity = rows * columns;
    // initializing a temporary 2D dynamic array to copy the data of array of seats (seating_capacity)
    int** temp = new int*[rows];
    // copying data for each row
    for (int i = 0; i < rows - 1; i++) {
        temp[i] = new int[columns];
        for (int j = 0; j < columns; j++)
            temp[i][j] = seating_plan[i][j];
    }
    // initialize columns for the new row
    temp[rows - 1] = new int[columns];
    // initializing the new row to 0
    for (int j = 0; j < columns; j++) {
        temp[rows - 1][j] = 0;
    }
    // frees the memory for each row
    for (int i = 0; i < rows - 1; i++) {
        delete[] seating_plan[i];
    }
    // frees the memory for the main array with its pointers
    delete[] seating_plan;
    // assigning the pointer temp to seating_plan
    seating_plan = temp;
    return *this;
}

// overload += operator
Flight& Flight::operator+=(Passenger & p){
    // Calculate the row and column positions based on the updated number of booked seats
    int r = booked_seats / columns;
    int c = booked_seats % columns;
    // make the seat booked
    seating_plan[r][c] = 1;
    passengers_names[booked_seats] = p.passenger_name;
    //increment booked seats and total count of passengers
    booked_seats += 1;
    Passenger::CountTotalPassengers++;
    return *this;
}

//operator postfix--
Flight Flight::operator--(int){
    // initializing a temporary Flight object that is a copy of the current object
    Flight temp = *this;
    booked_seats--;
    Passenger::CountTotalPassengers--;
    // Calculate the row and column positions based on the updated number of booked seats
    int r = booked_seats / columns;
    int c = booked_seats % columns;
    // Set the seat at the calculated row and column to 0
    seating_plan[r][c] = 0;
    return temp;
}

//Operator -=
Flight &Flight::operator-=(int num){
    for(int i = 0; i < num && booked_seats > 0; i++){
        booked_seats--;
        //calculate the row and column positions based on the updated number of booked seats
        int r = booked_seats / columns;
        int c = booked_seats % columns;
        //set seat at the calculated row and column to 0
        seating_plan[r][c] = 0;
        Passenger::CountTotalPassengers--;
    }
    return *this;
}

//Copy constructor
Flight::Flight(const Flight &obj){
    // initializing private variables
    no_of_flight = obj.no_of_flight;
    seating_capacity = obj.seating_capacity;
    booked_seats = obj.booked_seats;
    departure_time = obj.departure_time;
    time_zone = obj.time_zone;
    flight_dest = obj.flight_dest;
    rows = obj.rows;

    // rounding up rows in case (seating_capacity / columns) is float
    if (seating_capacity % columns != 0)
        rows++;
    // initializing rows in array of seats (seating_capacity)
    seating_plan = new int *[rows];
    for (int i = 0; i < rows; i++) {
        seating_plan[i] = new int[columns];
        for (int j = 0; j < columns; j++)
            seating_plan[i][j] = obj.seating_plan[i][j];
    }
    // initializing array of passengers
    passengers_names = new string[seating_capacity];
    for (int i = 0; i < booked_seats; i++)
        passengers_names[i] = obj.passengers_names[i];
}

//Destructor
Flight::~Flight(){
    //delete the memory for each row
    for(int i = 0; i < rows; i++)
        delete [] seating_plan[i];
    //delete memory
    delete [] seating_plan;
    delete [] passengers_names;
}
