#include <iostream>
#include "Doctor.h"
#include "Surgeon.h"
#include "SurgerySchedule.h"
#include "Specialist.h"

using namespace std;

int main() {
    int num, choice, duration, numOfSurgeries; // variables to store doctors attributes
    string ID, name, speciality, patient_name, date;
    float rate;

    cout << "Enter number of doctors: ";
    cin >> num;
    cin.ignore(); // clear the buffer

    Doctor *arr[num]; // Array to store doctor's objects

    for (int i = 0; i < num; i++) {
        cout << "\nEnter your choice: 1)surgeon\n2)specialist ";
        cin >> choice;
        cin.ignore(); // clear the buffer

        if (choice == 1) {
            cout << "\nEnter Surgeon's ID: ";
            getline(cin, ID);
            cout << "Enter Surgeon's name: ";
            getline(cin, name);
            cout << "Enter Surgeon's duration: ";
            cin >> duration;
            cout << "Enter Surgeon's rate: ";
            cin >> rate;
            cout << "Enter Surgeon's number of surgeries: ";
            cin >> numOfSurgeries;
            cin.ignore(); // clear the buffer

            SurgerySchedule *schedules; //create surgery schedule array
            schedules = new SurgerySchedule[numOfSurgeries];
            for (int i = 0; i < numOfSurgeries; i++) {
                SurgerySchedule schedule = SurgerySchedule();
                cout << "Enter the date: ";
                getline(cin, date);
                schedule.set_date(date);

                cout << "Enter patient name: ";
                getline(cin, patient_name);

                schedule.set_patientName(patient_name);
                schedules[i] = schedule; //store it in the array
            }
            //create surgeon object and store it in the array of doctor's objects
            arr[i] = new Surgeon(ID, name, duration, rate, numOfSurgeries, schedules);
        } else if (choice == 2) {
            cout << "\nEnter Specialist's ID: ";
            getline(cin, ID);
            cout << "Enter Specialist's name: ";
            getline(cin, name);
            cout << "Enter Specialist's duration: ";
            cin >> duration;
            cout << "Enter Specialist's rate: ";
            cin >> rate;
            cout << "Enter Specialist's field: ";
            cin >> speciality;
            cin.ignore(); //clear the buffer
            //create specialist object and store it in the array
            arr[i] = new Specialist(ID, name, duration, rate, speciality);
        } else
            // if the user enter an invalid choice (neither 1 nor 2)
            cout << "Invalid choice!" << endl;
    }

    //print all doctors' details
    for (int i = 0; i < num; i++)
        //call PrettyPrint function for each doctor which print it on the terminal and on doctors.txt file
        arr[i]->PrettyPrint();

    return 0;
}
