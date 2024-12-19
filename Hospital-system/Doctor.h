#ifndef OOPPROJECTS_DOCTOR_H
#define OOPPROJECTS_DOCTOR_H
#include <string>
using namespace std;

class Doctor {
protected:
    string ID;
    string name;
    int duration;
    float rate;
public:
    //default constructor
    Doctor();
    //paramterized constructor
    Doctor(string &id, string &nm, int dur, float r);
    //function prettyprint
    virtual void PrettyPrint();
    //function calculatetotlafee
    virtual double calculateTotalFee();
};


#endif //OOPPROJECTS_DOCTOR_H
