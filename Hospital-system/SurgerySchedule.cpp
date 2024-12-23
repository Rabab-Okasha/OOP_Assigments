#include "SurgerySchedule.h"

//default constructor
SurgerySchedule::SurgerySchedule()
     :patientName(""), Date(""){}

//parametized constructor for the patient name and date of surgery
SurgerySchedule::SurgerySchedule(string &patientName, string &date)
    :patientName(patientName), Date(date){
}

//seter for patient name
void SurgerySchedule::set_patientName(string &patientName){
    this-> patientName = patientName;
}

//seter for date of surgery
void SurgerySchedule::set_date(string &date){
    Date = date;
}

//getter for patient name
string SurgerySchedule::get_patientName()const{
    return patientName;
}

//getter for date of surgery
string SurgerySchedule::get_date()const{
    return Date;
}
