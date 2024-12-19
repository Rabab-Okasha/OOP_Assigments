#include "Doctor.h"
#include <iostream>

//default constructor
Doctor::Doctor()
   :ID(""), name(""), duration(0), rate(0.0){}

//paramterized constructor
Doctor::Doctor(string &id, string &nm, int dur, float r)
    :ID(id), name(nm), duration(dur), rate(r){}

//function prettyprint
void Doctor::PrettyPrint(){
    cout << "Doctor ID is " << ID << ", and name is Dr. " << name << endl;
}

//function calculatetotlafee
double Doctor::calculateTotalFee(){
    return 0.0;
}
