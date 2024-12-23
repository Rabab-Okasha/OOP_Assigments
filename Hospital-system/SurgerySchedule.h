#ifndef OOPPROJECTS_SURGERYSCHEDULE_H
#define OOPPROJECTS_SURGERYSCHEDULE_H

#include <string>
using namespace std;

class SurgerySchedule {
private:
    string patientName;
    string Date;
public:
    //default constructor
    SurgerySchedule();

    //parametized constructor for the patient name and date of surgery
    SurgerySchedule(string &patientName, string &date);

    //seter for patient name
    void set_patientName(string &patientName);

    //seter for date of surgery
    void set_date(string &date);

    //getter for patient name
    string get_patientName() const;

    //getter for date of surgery
    string get_date() const;

};


#endif
