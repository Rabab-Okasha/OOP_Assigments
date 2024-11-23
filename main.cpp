#include <iostream>
#include <string>
#include "Flight.h"
#include "Passenger.h"
using namespace std;

int main(){

    int passengerNumbers;
    Flight f1("London", 20, 123);
    cout << "\nEnter number of passengers to be add: ";
    cin >> passengerNumbers;
    Passenger names [passengerNumbers];
    for(int i = 0; i < passengerNumbers; i++)
        cin >> names[i];// cteate object for each index

    //Testing function add_passenger
    f1.add_passengers(passengerNumbers, names);
    f1.Display();
    cout << f1 << endl;

    cout << "==================================" << endl;

    //Testing function search by name
    f1.search_name("Rabab");
    f1.search_name("XYZ");
    //Testing function search by seat number
    f1.search_seatNo(0,2);
    f1.search_seatNo(4, 6);

    cout << "==================================" << endl;

    //Testing operator +=
    Passenger p1;
    cin >> p1;
    cout << "\nAdd a new passenger " << p1.getname() << " (by using +=): ";
    f1 += p1;
    //display flight details
    f1.Display();
    cout << f1 << endl;
    cout << "==================================" << endl;
    cout << "Number of passengers in the system (After adding 1 passenger): " << p1.get_No_Passengers();
    //display passenger details
     p1.Display();
    cout << "==================================" << endl;

    //Testing Prefix operator ++
    ++f1;
    cout << "\nAdding a new row: " << endl;
    cout << f1 << endl;
    cout << "==================================" << endl;

   //Testing copy constructor
    cout << "\nUsing copy consturctor" << endl;
    Flight f2 = f1;
    f2.Display();
    cout  << f2 << endl;
    cout << "==================================" << endl;

    //Testing Postfix operator --
    cout << "\nUsing operator postfix-- :" << endl;
    cout << f1-- << endl;
    Passenger p;
    cout << "==================================" << endl;
    cout << "Showing the decrement again (updated): " << endl;
    cout << f1 << endl;
    cout << "Number of passengers in the system (after using postfix-- UPDATED): " << p.get_No_Passengers() << endl;
    cout << "==================================" << endl;

    //Testing operator -=
    int removed_num;
    cout << "\nEnter number of passengers to be removed: ";
    cin >> removed_num;
    f1 -= removed_num;
    cout << f1 << endl;
    cout << "==================================" << endl;
    cout << "\nNumber of passengers in the system" << "(After removing " << removed_num << "): ";
    cout <<  p.get_No_Passengers() << endl;
    cout << "==================================" << endl;

    //Test Remove method
    Passenger p2 ("Aang", 100);
    f1 += p2;
    cout << "Number of passengers in the system after ( adding " << p2.getname() << " ): " << p2.get_No_Passengers() << endl;
    cout << f1 << endl;
    cout << "==================================" << endl;
    f1.remove_passenger(p2);
    cout << "Number of passengers in the system after ( removing " << p2.getname() << " ): " << p.get_No_Passengers() << endl;
    cout << f1 << endl;
    cout << "==================================" << endl;

    return 0;
}
