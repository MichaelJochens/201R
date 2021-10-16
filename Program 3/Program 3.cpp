// Program 3.cpp  Student: Michael Jochens Class: 11:30 - 12:45

#include <iostream>
#include<fstream>
#include<vector>
#include<string>
#include"Functions.h"
#include<iomanip>
#include<sstream>
using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    vector<string> fileText;
    string line, itemName;
    vector<char> vector;
    bool potato = true;
    int userInput;
    int quantity;
    char EO, dollar;
    double price, total, endingVal = 0;

    fin.open("Office.txt");
    fout.open("Summary.txt");

    fileText.push_back(line);
    vector.push_back(EO);
    if (!fin.is_open()) {
        cout << "Unable to open file" << endl;
        return 1;
    }
    else {
        cout << "File is open" << endl << endl;
        if (!fin.fail()) {
            while (potato) {

                PrintMainMenu();
                cin >> userInput;
                cout << endl;

                if (userInput == 1) {
                    for (int linenum = 0; getline(fin, line) && linenum != '-1'; linenum++) {
                        fin >> EO >> quantity >> itemName >> dollar >> price;
                        if (EO == 'E') {
                            cout << left << setw(15) << EO;
                            cout << left << "ITEM: " << setw(15) << itemName << " ";
                            cout << left << "QUANTITY: " << setw(15) << quantity << " ";
                            cout << "PRICE: " << dollar;
                            cout << left << setw(15) << price << " ";
                            total = price * quantity;
                            cout << "TOTAL: $" << total << endl;
                            endingVal += total;
                        }
                    }
                    PrintEndVal(endingVal);
                }
                else if (userInput == 2) {
                    for (int linenum = 0; getline(fin, line); linenum++) {
                        fin >> EO >> quantity >> itemName >> dollar >> price;
                        if (EO == 'O') {
                            cout << left << setw(15) << EO;
                            cout << left << "ITEM: " << setw(15) << itemName << " ";
                            cout << left << "QUANTITY: " << setw(15) << quantity << " ";
                            cout << "PRICE: " << dollar;
                            cout << left << setw(15) << price << " ";
                            total = price * quantity;
                            cout << "TOTAL: $" << total << endl;
                            endingVal += total;
                        }
                    }
                    PrintEndVal(endingVal);
                }
                else if (userInput == 3) {
                    for (int linenum = 0; getline(fin, line) && fileText.size(); linenum++) {
                        fin >> EO >> quantity >> itemName >> dollar >> price;
                            fout << left << setw(15) << EO;
                            fout << left << "ITEM: " << setw(15) << itemName << " ";
                            fout << left << "QUANTITY: " << setw(15) << quantity << " ";
                            fout << "PRICE: " << dollar;
                            fout << left << setw(15) << price << " ";
                            total = price * quantity;
                            fout << "TOTAL: $" << total << endl;
                            endingVal += total;
                    }
                    fout << "--------------------------------------------" << endl;
                    fout << "The total value of these supplies is $" << endingVal << endl;
                    fout << "--------------------------------------------" << endl;  
                    cout << "File has been transferred." << endl;
                }
                else if (userInput == 4) {
                    potato = false;
                }
                else {
                    cout << "Please enter one of the options listed. ";
                    potato = true;
                }
            }
        }
    }
        fin.close();
        fout.close();

        return 0;
}
    
//line = fin.get();
//fout << line;



