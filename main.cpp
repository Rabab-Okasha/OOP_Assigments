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
    Passenger names [passnum];
    for(int i = 0; i < names; i++)
        cin >> names[i];// cteate object for each index
    
    //Testing function add_passenger
    f1.add_passengers(passengerNumbers, arr,  f1);
    f1.Display();
    cout << f1 << endl;
    
    //Testing operator +=
    Passenger p1;
    cout << "\nAdd passenger(using +=): ";
    cin >> p1;
    f1 += p1;
    //display flight details
    f1.Display();
    cout << f1 << endl;
    //display passengers details
    p1.Display();
    cout << f1 << endl;
    
    //Testing Prefix operator ++
    ++p1;
    cout << p1 << endl;

    //Testing copy constructor
    cout << "\nUsing copy consturctor" << endl;
    Flight f2 = fl;
    f2.Display();
    cout  << f2 << endl;
    Passenger p;
    cout << "Number of passengers in the system: ";
    cout <<  p.get_noPassengers() << endl;

    //Testing Postfix operator --
    cout << "\nUsing Postfix --: " << endl;
    cout << f1-- << endl;
    Passenger p;
    cout << "Number of passengers in the system(After removing 1): ";
    cout <<  p.get_noPassengers() << endl;

    //Testing operator -=
    int removed_num;
    cout << "\nEnter number of passengers to be removed: ";
    cin >> removed_num;
    f1 -= removed_num;
    cout << f1 << endl;
    cout << "\nNumber of passengers in the system" << "(After removing " << removed_num << " ):";
    cout <<  p.get_noPassengers() << endl;

    return 0;
}
