#include "SurgerySchedule.h"

//default constructor
SurgerySchedule::SurgerySchedule()
     :patientName(""), Date(""){}

//parametized constructor
SurgerySchedule::SurgerySchedule(string &PN, string &date)
    :patientName(PN), Date(date){
}

//seter for patient name
void SurgerySchedule::set_patientName(string &pn){
    patientName = pn;
}

//seter for date
void SurgerySchedule::set_date(string &date){
    Date = date;
}

//getter for patient name
string SurgerySchedule::get_patientName()const{
    return patientName;
}

//getter for date
string SurgerySchedule::get_date()const{
    return Date;
}
