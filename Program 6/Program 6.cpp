// Program 6.cpp

#include <iostream>
#include <queue>
#include <string>
#include "Functions.h"
using namespace std;

void AddPatient(queue<string>& department, string input);
void AddCritical(queue<string>& department, string input);
void Operation(queue<string>& department, queue<string>& departmentCrit);
void Cancel(queue<string>& department, string firstName, string lastName, string SSN);
void ListPatients(queue<string>& department, queue<string>& departmentCrit);

int main()
{
    int userIn;
    string patientInfo;
    bool flag = true, flag2 = true;
    queue<string> heart, lung, plastic, heartCrit, lungCrit, plasticCrit;


    while (flag == true) {
        flag2 = true;
        PrintMain();
        cin >> userIn;
        if (userIn == 1) {
            while (flag2 == true) {
                cout << "Welcome to department : Heart Clinic" << endl << endl;
                PrintSubMain();
                cin >> userIn;
                if (userIn == 1) {
                    AddPatient(heart, patientInfo);
                }
                else if (userIn == 2) {
                    AddCritical(heartCrit, patientInfo);
                    continue;
                }
                else if (userIn == 3) {
                    Operation(heart, heartCrit);
                    continue;
                }
                else if (userIn == 4) {
                    Cancel(heart, patientInfo, patientInfo, patientInfo);
                    continue;
                }
                else if (userIn == 5) {
                    ListPatients(heart, heartCrit);
                    continue;
                }
                else if (userIn == 6) {
                    flag2 = false;
                }
            }
        }
        if (userIn == 2) { 
            cout << "Welcome to department : Lung Clinic" << endl << endl;
            PrintSubMain();
            cin >> userIn;
            if (userIn == 1) {
                AddPatient(lung, patientInfo);
            }
            if (userIn == 2) {
                AddCritical(lungCrit, patientInfo);
            }
            if (userIn == 3) {
                Operation(lung, lungCrit);
            }
        }
        if (userIn == 3) {
            cout << "Welcome to department : Plastic Surgery" << endl << endl;
            PrintSubMain();
            cin >> userIn;
            if (userIn == 1) {
                AddPatient(plastic, patientInfo);
            }
            if (userIn == 2) {
                AddCritical(plasticCrit, patientInfo);
            }
            if (userIn == 3) {
                Operation(plastic, plasticCrit);
            }
        }
        if (userIn == 4) {
            return 0;
        }
    }
}


