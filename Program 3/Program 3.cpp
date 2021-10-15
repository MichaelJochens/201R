// Program 3.cpp  Student: Michael Jochens Class: 11:30

#include <iostream>
#include<fstream>
#include<vector>
#include<string>
#include"Functions.h"

using namespace std;

int main()
{
    vector<char> EO;
   char fileText;
   string line;
   int i = 1, userInput;
    ifstream fin;
    ofstream fout;
    fin.open("Office.txt");
    fout.open("Summary.txt");
    EO.push_back(fileText);
    if (!fin.is_open()) {
        cout << "Unable to open file" << endl;
        return 1;
    }
    else {
        cout << "File is open" << endl;
        if (!fin.fail()) {

            PrintMainMenu();
            cin >> userInput;

            if (userInput == 1) {
                for (int linenum = 0; getline(fin, line) && linenum < linenum != '-1'; linenum++) {
                    if (linenum == 0 || linenum == 4 || linenum == 5 || linenum == 7) {
                        cout << line << endl;
                    }
                }
            }
            else if (userInput == 2) {
                for (int linenum = 0; getline(fin, line) && linenum != '-1'; linenum++) {
                    if (linenum == 1 || linenum == 2 || linenum == 3 || linenum == 6) {
                        cout << line << endl;
                    }
                }
            }
            else if (userInput == 3) {
                while (!fin.eof()) {
                    fileText = fin.get();
                    fout << fileText;  
                }
                cout << "File has been transferred." << endl;
            } 
            else if (userInput == 4) {
                return 0;
            }
        }
        fin.close();
        fout.close();
    }
   

    return 0;
}



