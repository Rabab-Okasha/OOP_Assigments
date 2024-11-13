#include <iostream>
#include <string>
#include "Flight.h"
#include "Passenger.h"

using namespace std;

int main(){

    string des , n;
   int capacity ,  num, passnum , id;
    cout<<"Enter your destination : ";
    cin>>des;
    cout<<"Enter number of the flight : ";
    cin>>num;
    cout<<"Enter the capacity : ";
    cin>>capacity;
    Flight fl(des,capacity,num);

    cout<<"add num of passengers : ";
    cin>>passnum;
        Passenger arr[passnum];
    for(int i=0;i<passnum;i++)
    {
        cin>>arr[i];// cteate object for each index
    }

    fl.add_passengers(passnum, arr,  fl);
    fl.Display();
    Passenger p1;
    cout<<"add passenger += \n";
    cin>>p1;
    fl+=p1;

    fl.Display();in>>p1;
    
    p1.Display_passenger();
    return 0;
}
