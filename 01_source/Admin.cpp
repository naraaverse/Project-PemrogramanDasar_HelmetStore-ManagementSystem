///////////////////////////////////////////////////////////
//  Admin.cpp
//  Implementation of the Class Admin
//  Created on:      30-Nov-2025 7:58:31 PM
//  Original author: nara
///////////////////////////////////////////////////////////

#include "Admin.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <windows.h>

using namespace std;

Admin::Admin(){
}

Admin::~Admin(){
}

bool Admin::loginAdmin(string name, string pass){
    if (name == "Aurora" && pass == "caffeineaddict") return true;
    else if (name == "Nadya" && pass == "admin2") return true;
    else if (name == "Nada" && pass == "admin3") return true;
    return false;
}

void Admin::manageCatalog(Catalog  &updatecat){
    system("cls");
    cout << "\n==========================================" << endl;
    cout << "          CATALOG MANAGEMENT PANEL        " << endl;
    cout << "==========================================" << endl;
    cout << "Redirecting to Catalog Editor..." << endl;
    Sleep(800);
    
    updatecat.updateCatalog();
    
    cout << "\n[INFO] Catalog session finished." << endl;
    system("pause");
}

void Admin::manageUsers(){
    while(true) {
        system("cls");
        cout << "+------------------------------------------+" << endl;
        cout << "|        MANAGE USER PROFILES (ADMIN)      |" << endl;
        cout << "+------------------------------------------+" << endl;

        ifstream file("../02_data/data_user.csv");
        if (!file.is_open()) {
            cout << "\n[!] DATABASE ERROR: File not found!" << endl;
            system("pause");
            return;
        }

        vector<string> allLines; 
        vector<string> usernames; 
        string line, segment;

        while (getline(file, line)) {
            allLines.push_back(line); 
            stringstream ss(line);
            getline(ss, segment, ','); 
            usernames.push_back(segment);
        }
        file.close();

        if (allLines.empty()) {
            cout << "\n[INFO] No registered users yet." << endl;
            cout << "+------------------------------------------+" << endl;
            system("pause");
            return;
        }

        cout << "\nList of Registered Users:" << endl;
        cout << "+-----+------------------------------------+" << endl;
        cout << "| NO  | USERNAME                           |" << endl;
        cout << "+-----+------------------------------------+" << endl;
        
        for (size_t i = 0; i < usernames.size(); i++) {
            cout << "| " << left << setw(3) << (i + 1) 
                 << " | " << left << setw(34) << usernames[i] << " |" << endl;
        }
        cout << "+-----+------------------------------------+" << endl;
        cout << "|  0  | << CANCEL / BACK                   |" << endl;
        cout << "+-----+------------------------------------+" << endl;

        int choice;
        cout << "\n[DELETE ACCOUNT]" << endl;
        cout << "Select No: ";
        cin >> choice;
        cin.ignore();

        if (choice == 0) return;

        if (choice < 1 || choice > (int)allLines.size()) {
            cout << "\nInvalid choice! Please try again." << endl;
            Sleep(1000);
            continue; // Ulangi loop
        }

        cout << "\n[WARNING] Deleting user '" << usernames[choice - 1] << "'." << endl;
        cout << "Are you sure? (y/n): ";
        string confirm;
        cin >> confirm;

        if (confirm == "y" || confirm == "Y") {
            cout << "Deleting";
            for(int i = 0; i < 3; i++) { cout << "."; Sleep(300); }
            
            ofstream fileOut("../02_data/data_user.csv");
            
            for (size_t i = 0; i < allLines.size(); i++) {
                if (i != (choice - 1)) {
                    fileOut << allLines[i] << endl;
                }
            }
            fileOut.close();
            
            cout << "\n\n+------------------------------------------+" << endl;
            cout << "| [SUCCESS] User profile has been deleted! |" << endl;
            cout << "+------------------------------------------+" << endl;
            system("pause");

        } else {
            cout << "\n[INFO] Deletion cancelled." << endl;
            Sleep(800);
        }
    }
}