#include <iostream>
#include "Doctor.h"
#include "Surgeon.h"
#include "SurgerySchedule.h"
#include "Specialist.h"
#include <fstream>
using namespace std;

int main(){
    int num, choice;
    cout << "Enter number of doctors: " << endl;
    cin >> num;
    Doctor *arr[num];
    for(int i = 0; i < num; i++){
        cout << "Enter your choice: 1)surgeon 2)specialist ";
        cin >> choice;
        if(choice  == 1){
            arr[i] = new Surgeon;

        }
        else if(choice == 2){

        }
    }
    fstream outfile ("../doctors.txt", ios::out);
    for(int i = 0; i < num; i++){
        arr[i]->PrettyPrint();

    }
    return 0;
}
