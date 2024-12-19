#ifndef OOPPROJECTS_SPECIALIST_H
#define OOPPROJECTS_SPECIALIST_H
#include "Doctor.h"
#include "Surgeon.h"
#include <string>

class Specialist: public Doctor{
    string speciality;
public:
    //default constructor
    Specialist();
    //parameterized constructor
    Specialist(string &id, string &nm, int dur, float r,string &sp);
    //overriden calculatetotalfee function
    double calculateTotalFee() override;
    //overriden prettyprint fucntion
    void PrettyPrint() override;
};


#endif //OOPPROJECTS_SPECIALIST_H
