#include <iostream>
#include <queue>
#include <string>
#include "Functions.h"
using namespace std;


void PrintMain() {
	cout << "Welcome to 201 Hospital Main Menu." << endl << endl;
	cout << "Please enter one of the departments below: " << endl;
	cout << "1: Heart Clinic" << endl;
	cout << "2: Lung Clinic" << endl;
	cout << "3: Plastic Surgery" << endl;
	cout << "4: Exit" << endl;
}

void PrintSubMain() {
	cout << "Please enter your choice: " << endl;
	cout << "1: Add patient" << endl;
	cout << "2: Add critically ill patient" << endl;
	cout << "3: Take out patient for operation" << endl;
	cout << "4: Cancel Patient" << endl;
	cout << "5: List of queue of the patients" << endl;
	cout << "6: Choose a new department or exit" << endl;
}

void AddPatient(queue<string>& department, string input) {
	cout << "Enter patient's first name: ";
	cin >> input;
	department.push(input);
	cout << "Enter patient's last name: ";
	cin >> input;
	department.push(input);
	cout << "Enter patient's Social Security Number: ";
	cin >> input;
	department.push(input);
	cout << department.size() << endl;
}

void AddCritical(queue<string>& department, string input) {
	cout << "Enter patient's first name: ";
	cin >> input;
	department.push(input);
	cout << "Enter patient's last name: ";
	cin >> input;
	department.push(input);
	cout << "Enter patient's Social Security Number: ";
	cin >> input;
	department.push(input);
	cout << department.size() << endl;
}

void Operation(queue<string>& department, queue<string>& departmentCrit) {
	if (departmentCrit.empty() == false) {
		for (int i = 0; i < 3; i++) {
			cout << departmentCrit.front() << " ";
			departmentCrit.pop();
		}
		cout << endl;
	}
	else if(departmentCrit.empty() == true && department.empty() == false) {
		for (int i = 0; i < 3; i++) {
			cout << department.front() << " ";
			department.pop();
		}
		cout << endl;
	}
	else if (departmentCrit.empty() == true && department.empty() == true) {
		cout << "No patients." << endl;
	}
}

void Cancel(queue<string>& department,  string firstName, 
	string lastName, string SSN) {
	queue<string> temp;
	int i = department.size();
	int cnt = 0;
	cout << "Please enter Patient info " << endl;
	cout << "First Name: ";
	cin >> firstName;
	cout << "Last Name: ";
	cin >> lastName;
	cout << "SSN: ";
	cin >> SSN;
	while (department.empty() == false) {
		if (firstName == department.front() && department.empty() == false) {
			department.pop();
		}
		else if (lastName == department.front() && department.empty() == false) {
			department.pop();
		}
		else if (SSN == department.front() && department.empty() == false) {
			department.pop();
		}
		else {
			temp.push(department.front());
			department.pop();
		}
	}
	while (temp.empty() == false) {
		department.push(temp.front());
		temp.pop();
	}
}

void ListPatients(queue<string>& department, queue<string>& departmentCrit) {
	queue<string> temp, tempCrit;
	if (departmentCrit.empty() == false) {
		cout << "Critical patients: " << endl;
		while (departmentCrit.empty() == false) {
			tempCrit.push(departmentCrit.front());
			cout << departmentCrit.front() << " ";
			departmentCrit.pop();
			tempCrit.push(departmentCrit.front());
			cout << departmentCrit.front() << " ";
			departmentCrit.pop();
			tempCrit.push(departmentCrit.front());
			cout << departmentCrit.front() << " ";
			departmentCrit.pop();
			cout << endl << endl;
		}
		while (tempCrit.empty() == false) {
			departmentCrit.push(tempCrit.front());
			tempCrit.pop();
		}
	}
	else {
		cout << "No critical patients." << endl;
	}
	if (department.empty() == false) {
		cout << "Non-critical patients: " << endl;
		while (department.empty() == false) {
			temp.push(department.front());
			cout << department.front() << " ";
			department.pop();
			temp.push(department.front());
			cout << department.front() << " ";
			department.pop();
			temp.push(department.front());
			cout << department.front() << " ";
			department.pop();
			cout << endl;
		}
		while (temp.empty() == false) {
			department.push(temp.front());
			temp.pop();
		}
	}
	else {
		cout << "No Patients." << endl;
	}
}