#ifndef OOPPROJECTS_SURGEON_H
#define OOPPROJECTS_SURGEON_H
#include "Doctor.h"
#include "SurgerySchedule.h"

class Surgeon :public Doctor{
private:
    int numSurgeriesScheduled;
    SurgerySchedule *schedules;
public:
    //default constructor
    Surgeon();
    //parameterized constructor
    Surgeon(string &id, string &nm, int dur, float r, int nss);
    //copy constructor
    Surgeon(const Surgeon &obj);
    //destructor
    ~Surgeon();
    //overriden calculate fee function
    double calculateTotalFee() override;
    //overriden prettyprint fucntion
    void PrettyPrint() override;
    //member function to print all of the scheduled surgeries of the surgeon
    void printSurgeries()const;
};

#endif //OOPPROJECTS_SURGEON_H
