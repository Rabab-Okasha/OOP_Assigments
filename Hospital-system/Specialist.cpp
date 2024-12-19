#include "Specialist.h"
#include <iostream>

//default constructor
Specialist::Specialist()
    :Doctor(), speciality("") {}

//parameterized constructor
Specialist::Specialist(string &id, string &nm, int dur, float r,string &sp)
    :Doctor(id, nm, dur, r), speciality(sp){}

//overriden calculatetotalfee function
double Specialist::calculateTotalFee(){
    return (duration/15.0) * rate;
}
//overriden prettyprint fucntion
void Specialist::PrettyPrint(){
    cout << "Dr. " << name << " is a Specialist with whose total  fee is " << calculateTotalFee() << endl;
}
