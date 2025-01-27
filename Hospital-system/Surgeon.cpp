#include "Surgeon.h"
#include <iostream>
#include <iomanip> // for the built-in function setprecision
#include <fstream>

using namespace std;

//default constructor
Surgeon::Surgeon() //explicitly call default constructor of Doctor(Base class)
        : Doctor(), numSurgeriesScheduled(0) {}

//parameterized constructor
Surgeon::Surgeon(string &id, string &Name, int Duration, float Rate, int numOfSurgeries, SurgerySchedule *schedules)
//call Doctor(Base class) constructor to initialize doctor's attributes
        : Doctor(id, Name, Duration, Rate), numSurgeriesScheduled(numOfSurgeries) {
    this->schedules = schedules; // set the provided surgery schedule array to the member variable
}

//copy constructor
Surgeon::Surgeon(const Surgeon &obj)
//call Doctor constructor to copy its attributes
        : Doctor(obj), numSurgeriesScheduled(obj.numSurgeriesScheduled) {
    schedules = new SurgerySchedule[numSurgeriesScheduled]; //dynamically allocate new array
    for (int i = 0; i < numSurgeriesScheduled; i++)
        schedules[i] = obj.schedules[i]; //copy each value
}


//overriden form doctor(Base class) function that calculate surgeon's total fee service
double Surgeon::calculateTotalFee() {
    return (duration / 60) * rate;
}

//overriden prettyprint fucntion
void Surgeon::PrettyPrint() {
    // print to the file
    //The compiler needs this notation to ensure geting the right file in the directory
    fstream outFile("../HospitalSystem/doctors.txt", ios::app); // create and open the output file in an append mode
    //print surgeon's attributes to the output file
    outFile << "Dr. " << name << " is a surgeon whose total fee is $" << setprecision(4) <<
            calculateTotalFee() << " and has " << numSurgeriesScheduled << " surgeries scheduled." << endl;

    // print surgeon details to the terminal
    cout << "\nDr. " << name << " is a surgeon whose total fee is $" << setprecision(4) <<
         calculateTotalFee() << " and has " << numSurgeriesScheduled << " surgeries scheduled." << endl;

    // print the surgeon's scheduled surgeries
    printSurgeries();

    //print surgeon's surgeries in the output file
    printSurgeriesInFile();
    //close the output file to clear the buffer
    outFile.close();
}

//member function to print all the surgeon's scheduled surgeries
void Surgeon::printSurgeries() const {
    cout << "Surgeries schedule: ";
    for (int i = 0; i < numSurgeriesScheduled; i++) {
        cout << "\nDate: " << schedules[i].get_date() << ", Patient name: " << schedules[i].get_patientName();
    }
    cout << endl;
}

//function to print surgeries schedule in the output file
void Surgeon::printSurgeriesInFile() const {
    //The compiler needs this notation to ensure geting the right file in the directory
    fstream outFile("../HospitalSystem/doctors.txt", ios::app); //create and open the output file in an append mode
    outFile << "Surgeries schedule: ";
    for (int i = 0; i < numSurgeriesScheduled; i++) {
        outFile << "\nDate: " << schedules[i].get_date() << ", Patient name: " << schedules[i].get_patientName();
    }
    outFile << endl;
    //close the output file to clear the buffer
    outFile.close();
}

//destructor
Surgeon::~Surgeon() {
    delete[] schedules; // deallocate the dynamic array schedules memory
}
