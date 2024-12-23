#include "Specialist.h"
#include <iostream>
#include <iomanip>
#include <fstream>

//default constructor
Specialist::Specialist() //explicitly call default constructor of Doctor(Base class)
        : Doctor(), speciality("") {}

//parameterized constructor
Specialist::Specialist(string &id, string &Name, int Duration, float Rate, string &Speciality)
        //call Doctor(Base class) constructor to initialize doctor's attributes
        : Doctor(id, Name, Duration, Rate), speciality(Speciality) {}

//overriden form doctor(Base class) function that calculate specialist's total fee service
double Specialist::calculateTotalFee() {
    return (duration / 15) * rate;
}

//overriden prettyprint fucntion
void Specialist::PrettyPrint() {
    // print to the file
    //The compiler needs this notation to ensure geting the right file in the directory
    fstream outFile("../HospitalSystem/doctors.txt", ios::app); // create and open the output file in an append mode
    outFile << "Dr. " << name << " is a Specialist in " << speciality << " whose total fee is $" << setprecision(4)
            << calculateTotalFee() << endl;

    //print Specialist detials in terminal
    cout << "\nDr. " << name << " is a Specialist in " << speciality << " whose total fee is $" << calculateTotalFee()
         << setprecision(4) << endl;
}
