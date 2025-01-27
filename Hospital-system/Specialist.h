#ifndef OOPPROJECTS_SPECIALIST_H
#define OOPPROJECTS_SPECIALIST_H

#include "Doctor.h"
#include "Surgeon.h"
#include <string>

class Specialist : public Doctor {
    string speciality;
public:
    //default constructor
    Specialist();

    //parameterized constructor
    Specialist(string &id, string &Name, int Duration, float Rate, string &Speciality);

    //overriden form doctor(Base class) function that calculate specialist's total fee service
    double calculateTotalFee() override;

    //overriden form doctor(Base class) function that print specialist detials on the terminal and on doctors.txt file
    void PrettyPrint() override;
};


#endif
