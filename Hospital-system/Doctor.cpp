#include "Doctor.h"
#include <iostream>

//default constructor
Doctor::Doctor()
        : ID(""), name(""), duration(0), rate(0.0) {}

//paramterized constructor that set doctor's Id, name, duration and rate
Doctor::Doctor(string &id, string &Name, int Duration, float Rate)
        : ID(id), name(Name), duration(Duration), rate(Rate) {}

//print doctor details (Id and name)
void Doctor::PrettyPrint() {
    cout << "Doctor ID is " << ID << ", and name is Dr. " << name << endl;
}
