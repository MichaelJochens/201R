#include <iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

void PrintMainMenu() {
    cout << "Options: " << endl;
    cout << "1|Print all electronic (E) inventory " << endl;
    cout << "2|Print all Office (O) inventory " << endl;
    cout << "3|Move all data to \"Summary.txt\" " << endl;
    cout << "4|Quit" << endl;
    cout << "Please enter your option: ";
}