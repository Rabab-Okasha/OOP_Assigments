#ifndef OOPPROJECTS_SURGERYSCHEDULE_H
#define OOPPROJECTS_SURGERYSCHEDULE_H
#include <string>
using namespace std;

class SurgerySchedule{
private:
    string patientName;
    string Date;
public:
    //default constructor
    SurgerySchedule();
    //parametized constructor
    SurgerySchedule(string &PN, string &date);
    //seter for patient name
    void set_patientName(string &pn);
    //seter for date
    void set_date(string &date);
    //getter for patient name
    string get_patientName()const;
    //getter for date
    string get_date()const;

};


#endif //OOPPROJECTS_SURGERYSCHEDULE_H
