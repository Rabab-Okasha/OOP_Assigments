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
    cout << "\nPassengers' names: "<<endl;
    for (int i = 0; i < flight.booked_seats; i++) {
        if (!flight.passengers_names[i].empty()) {
            os << "Passanger " << i + 1 << ": " << flight.passengers_names[i] << endl;
        }
    }
    return os;
}

//parameterized constructor
Flight::Flight(string dest, int cap, int number)
{
    // initializing private variables
    seating_capacity = cap;
    no_of_flights = number;
    flight_dest = dest;
    departure_time = "00:00";
    time_zone = " ";
    rows = seating_capacity / columns;
    // rounding up rows in case (seating_capacity / columns) is float
    if (seating_capacity % columns != 0) {
        rows++;}
    // initializing rows in array of seats (seating_capacity)
    seating_plan = new int*[rows];
    // for each row initializing columns
    for (int i = 0; i < rows; i++) {
        seating_plan[i] = new int[columns];
        for (int j = 0; j < columns; j++) {
            // assigning each index to 0
            seating_plan[i][j] = 0;
        }}
    // initializing array of passengers
    passengers_names = new string[seating_capacity];
}

//overload the prefix operator ++
Flight& Flight::operator++()
{
    // increment rows by 1
    ++rows;
    // updating capacity
    seating_capacity = rows * columns;
    // initializing a temporary 2D dynamic array to copy the data of array of seats (seating_capacity)
    int** temp = new int*[rows];
    // copying data for each row
    for (int i = 0; i < rows - 1; i++) {
        temp[i] = seating_plan[i];
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

//operator +=
Flight& Flight::operator +=(Passenger & p)
{
  // calling add_passenger function to add the new passenger
  // as its only one passenger so the argument of the add_passenger function would be an integer 1 and passing the reference of the added passenger object
  add_passengers(1, &p, *this);
  // assigning the name of the new passenger to the array of passenger names
  passengers_names[booked_seats]=p.getname();
  return *this;
}



// remove passenger by name
Flight & Flight::remove_passenger(Passenger &p2)
{
    for(int i=0;i<booked_seats;i++) // i<booked_seats to ensure that loop stops last add passenger
    {
        // if the current index equals the name of the passenger
        if(passengers_names[i]==p2.getname())
        {
                //chainging each index to equal the index after (shifting)
                passengers_names[i]=passengers_names[i+1];
                for(int k=i ; k<booked_seats-1;k++)
                {
                    passengers_names[k+1]=passengers_names[k+2];
                }}}
            //updating the array of seats
            for(int i=rows;i>=0;i--)
            {
                for(int k=columns;k>=0;k--)
                {
                    if(seating_plan[i][k]==1)
                    {
                        seating_plan[i][k]=0;
                        break;
                    }}}
  // decrement the total number of passengers and booked seats
  Passenger::CountTotalPassengers --;
  booked_seats--;
  return *this;

}
// Search for a passenger by name in the flight's passenger list
bool Flight::search_name(string nm) {
    // Loop through all seats in the passenger names array
    for (int i = 0; i < seating_capacity; i++) {
        // Check if the passenger name at the current index matches the provided name
        if (passengers_names[i] == nm) {
            cout << "Passenger is on the flight" << endl;
            return true;  // Return true if the passenger is found
        }
    }
    // If no match is found after checking all names, output that the passenger is not on the flight
    cout << "Passenger is Not on the flight" << endl;
    return false;  // Return false if the passenger is not found
}

// Search for the status of a specific seat using row and column numbers
void Flight::search_seatNo(int r, int c) {
    // First, validate that the seat coordinates are within the bounds of the seating plan
    if (r >= 0 && r < rows && c >= 0 && c < columns) {
        // Check if the seat at row r and column c is unbooked (0 means unbooked)
        if (seating_plan[r][c] == 0)
            cout << "Seat is Not Booked" << endl;  // Output if seat is unbooked
        else
            cout << "Seat is Booked" << endl;  // Output if seat is booked (non-zero)
    } else {
        // If seat coordinates are out of bounds, print an error message
        cout << "Invalid seat number!" << endl;
    }
}
//add passenger
void Flight::add_passengers(int passengers_number, Passenger names_of_passenger[]){
    while (passengers_number > seating_capacity - booked_seats) {
        ++(*this);
        add_passengers(passengers_number, names_of_passenger);
    }
    for (int i = 0; i < rows && passengers_number > 0; i++) {
        for (int j = 0; j < columns && passengers_number > 0; j++) {
            if (seating_plan[i][j] == 0) {
                seating_plan[i][j] = 1;
                passengers_names[booked_seats] = names_of_passenger[booked_seats].getname();
                booked_seats++;
                passengers_number--;
                Passenger::CountTotalPassengers++;
            }
        }
    }
}

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

// Postfix operator--
Flight Flight::operator--(int) {
    // Create a temporary Flight object that is a copy of the current object (before decrement)
    Flight temp = *this;

    // Decrement the booked_seats counter
    temp.booked_seats--;

    // Decrement total number of passengers by 1
    Passenger::CountTotalPassengers--;

    // Calculate the row and column positions based on the updated number of booked seats
    int r = temp.booked_seats / columns;  // Row calculation (integer division)
    int c = temp.booked_seats % columns;  // Column calculation (remainder)

    // Set the seat at the calculated row and column to 0, indicating it's now vacant
    temp.seating_plan[r][c] = 0;

    return temp;
}

//Operator -=
Flight &Flight::operator-=(int num){
    for(int i = 0; i < num && booked_seats > 0; i++){
        booked_seats--;
        int r = booked_seats / columns;
        int c = booked_seats % columns;
        seating_plan[r][c] = 0;
        Passenger::CountTotalPassengers--;
    }
    return *this;
}
   //Copy constructor
Flight::Flight(const Flight &obj) {
    no_of_flights = obj.no_of_flights;
    seating_capacity = obj.seating_capacity;
    booked_seats = obj.booked_seats;
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
    for (int i = 0; i < booked_seats; i++)
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
