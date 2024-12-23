#ifndef OOPPROJECTS_DOCTOR_H
#define OOPPROJECTS_DOCTOR_H

#include <string>

using namespace std;

class Doctor {
protected:
    string ID;
    string name;
    int duration; //total number of minutes Dr spent with patients
    float rate;
public:
    //default constructor
    Doctor();

    //paramterized constructor that set doctor's Id, name, duration and rate
    Doctor(string &id, string &Name, int Duration, float Rate);

    //print doctor details (Id and name)
    virtual void PrettyPrint();

    //Pure virtual function that Calculate total fees of doctor's service (it's implemented in class Surgeon & Splecialist)
    virtual double calculateTotalFee() = 0;
};


#endif 
