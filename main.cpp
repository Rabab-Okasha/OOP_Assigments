#include <iostream>
#include <string>
#include "Flight.h"
#include "Passenger.h"
using namespace std;

int main(){
 int passengerNumbers;
    Flight f1("London", 16, 123);
    cout << "\nEnter number of passengers to be add: ";
    cin >> passengerNumbers;
    Passenger names [passengerNumbers];
    for(int i = 0; i < passengerNumbers; i++)
        cin >> names[i];// cteate object for each index

    //Testing function add_passenger
    f1.add_passengers(passengerNumbers, names);
    f1.Display();
    cout << f1 << endl;

    //Testing function search by name
    f1.search_name("Rabab");
    //Testing function search by seat number
    f1.search_seatNo(0,2);

    //Testing operator +=
    Passenger p1 ("Anag", 12);
    cout << "\nAdd a new passenger(by using +=): ";
    f1 += p1;
    //display flight details
    f1.Display();
    cout << f1 << endl;
    cout << "\nNumber of passengers in the system (After adding 1 passenger): " << p1.get_noPassengers();
    //display passenger details
     p1.Display();

    //Testing Prefix operator ++
    ++f1;
    cout << "\nAdding a new row: " << endl;
    cout << f1 << endl;

   //Testing copy constructor
    cout << "\nUsing copy consturctor" << endl;
    Flight f2 = f1;
    f2.Display();
    cout  << f2 << endl;

    //Testing Postfix operator --
    cout << "\nUsing Postfix --: " << endl;
    cout << f1-- << endl;
    cout << f1;
    Passenger p;
    cout << "Number of passengers in the system(After removing 1): ";
    cout <<  p.get_noPassengers() << endl;

    //Testing operator -=
    int removed_num;
    cout << "\nEnter number of passengers to be removed: ";
    cin >> removed_num;
    f1 -= removed_num;
    cout << f1 << endl;
    cout << "\nNumber of passengers in the system" << "(After removing " << removed_num << "): ";
    cout <<  p.get_noPassengers() << endl;

    //Test Remove method
    Passenger p2 ("Aang", 100);
    cout << "Number of passengers in the system after adding Aang: " << p2.get_noPassengers() << endl;
    f1 += p2;
    cout << f1 << endl;
    f1.remove_passenger(p2);
    cout << "Number of passengers in the system after removing Aang: " << p.get_noPassengers() << endl;
    cout << f1 << endl;

    return 0;
}
