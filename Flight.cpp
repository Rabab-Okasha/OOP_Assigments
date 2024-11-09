#include "Flight.h"
#include <string>
using namespace std;

//initialize the static variable
int Flight::CurrentNoBookedOfSeats = 0;





//Display flight details
void Flight::Display() const{
    //Displaying flight details
   cout << "Flight Details: " << endl;
   cout << "------------------------------";
   cout << "\nNumber of flights: " << setw(8) << no_of_flights
        << "\nSeating capacity: " << setw(8) << seating_capacity
        << "\nDeparture Time: " << setw(11) << departure_time << " " << time_zone
        << "\nDestination: " << setw(15) << flight_dest
        << "\nSeating plan: ";
   //Displaying the Seating plan
   for(int i = 0; i < rows; i++){
       for(int j = 0; j < columns; j++)
           cout << setw(5) << seating_plan[i][j] << " ";
       cout << endl;
   }
   cout << "\nPassengers' names: ";
   //displaying passengers' names
   for(int i = 0; i < seating_capacity; i++)
       cout << "\nPassanger " << i + 1 << ": " << passengers_names[i];
}


