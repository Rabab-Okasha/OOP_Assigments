#include "Surgeon.h"
#include <iostream>
using namespace std;

//default constructor
Surgeon::Surgeon()
    :Doctor(), numSurgeriesScheduled(0){}

//parameterized constructor
Surgeon::Surgeon(string &id, string &nm, int dur, float r, int nss)
    :Doctor(id, nm, dur, r),numSurgeriesScheduled(nss){
    schedules = new SurgerySchedule[numSurgeriesScheduled]; // not sure!
}

//copy constructor
Surgeon::Surgeon(const Surgeon &obj)
    :Doctor(obj), numSurgeriesScheduled(obj.numSurgeriesScheduled){
    schedules = new SurgerySchedule[numSurgeriesScheduled];
    for (int i = 0; i < numSurgeriesScheduled; i++)
        schedules[i] = obj.schedules[i];
}


//destructor
Surgeon::~Surgeon(){
    delete[] schedules;
}

//overriden calculate fee function
double Surgeon::calculateTotalFee() {
    return(duration/60.0) * rate;
}

//overriden prettyprint fucntion
void Surgeon::PrettyPrint() {
    cout << "Dr. " << name << " is a surgeon whose total fee is " <<
    calculateTotalFee() << " and has " << numSurgeriesScheduled << " surgeries scheduled." << endl;
}

//member function to print all of the scheduled surgeries of the surgeon
void Surgeon::printSurgeries()const{
    cout << "[ ";
    for(int i = 0; i < numSurgeriesScheduled; i++){
        cout << schedules[i] << " ";
    }
    cout << "]" << endl;
}
