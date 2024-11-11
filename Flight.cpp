#include "Flight.h"
#include <string>
using namespace std;

//initialize the static variable
int Flight::CurrentNoBookedOfSeats = 0;

//3 args constructor
Flight::Flight(string dest , int cap , int number)
{
   seating_capacity = cap;
   no_of_flights = number;
   flight_dest = dest;
   seating_plan = new int*[rows];
   for(int i=0 ; i < rows ; i++)
   {
       seating_plan[i]= new int[columns];
       for(int j=0 ; j < columns;j++)
           seating_plan[i][j]=0;
   }
   passengers_names = new string [seating_capacity];
}


//overload the prefix operator ++ 
Flight& Flight::operator++()
{
    ++rows;
        int** temp = new int* [rows];
        for(int i=0 ; i<rows;i++)
        {
            temp = new int* [columns];
        }
    for(int i=0 ; i<rows;i++)
    { temp[rows] = new int[columns];
        for(int j=0 ; j<columns ; j++)
            temp[i][j]=seating_plan[i][j];
    }
    delete[]seating_plan;
    seating_plan = temp;
    return *this;
}

//Add passegners method
void Flight::add_passengers(int passengers_number, Passenger names_of_passenger[], Flight& f)
{
    while(booked_seats + passengers_number > rows*columns)
         {
            ++(*this);
    }

   seating_names_plan = new string*[seating_capacity/columns];
   for(int i=0 , l=0; i<seating_capacity/columns && l<passengers_number ; i++,l++)
   {
       seating_names_plan[i]= new string[columns];

       for(int j=0,k=0 ; j<columns&&l<passengers_number;j++,k++)
          {
           seating_names_plan[i][j]=names_of_passenger[l].getname();
           passengers_names[l]=names_of_passenger[l].getname();
          }
   }
   for(int i=0; i<rows ; i++)
   {
       for(int j=0 ; j<columns&&passengers_number>0;j++)
          {
           seating_plan[i][j]=1;
           passengers_number--;
           booked_seats++;
          }
   }
    for(int i=0 ;i<passengers_number;i++)
    {
        for(int l=0 ; l< columns;l++)
        {
            seating_plan[counter_rows][counter_columns]=1;
            counter_columns++;
        }
        counter_rows++;
    }}

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
void Flight::Display() const{
    //Displaying flight details
   cout << "Flight Details: " << endl;
   cout << "------------------------------";
   cout << "\nNumber of flight: " << setw(8) << no_of_flights;
   cout << "\nSeating capacity: " << setw(8) << seating_capacity;
   cout << "\nDeparture Time: " << setw(10) << departure_time << " " << time_zone;
   cout << "\nDestination: " << setw(13) << flight_dest;
   cout << "\nSeating plan: \n";
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


