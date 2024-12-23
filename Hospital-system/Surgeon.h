#ifndef OOPPROJECTS_SURGEON_H
#define OOPPROJECTS_SURGEON_H

#include "Doctor.h"
#include "SurgerySchedule.h"

class Surgeon : public Doctor {
private:
    int numSurgeriesScheduled;
    SurgerySchedule *schedules; // dynamic array to carry surgeon's surgery schedule
public:
    //default constructor
    Surgeon();

    //parameterized constructor
    Surgeon(string &id, string &Name, int Duration, float Rate, int numOfSurgeries, SurgerySchedule *schedules);

    //copy constructor
    Surgeon(const Surgeon &obj);

    //overriden form doctor(Base class) function that calculate surgeon's total fee service
    double calculateTotalFee() override;

    //overriden form doctor(Base class) function that print surgeon detials on the terminal and on the output file
    void PrettyPrint() override;

    //member function to print all of scheduled surgeries of the surgeon
    void printSurgeries() const;

    //member function to print surgeries schedule in the output file
    void printSurgeriesInFile()const;

    //destructor to deallocate the dynamic array (schedules) memory
    ~Surgeon();
};

#endif
