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
using namespace std;

Admin::Admin(){

}

Admin::~Admin(){

}

bool Admin::loginAdmin(string name, string pass){
    if (name == "Aurora" && pass == "caffeineaddict") {
        return true;
    }
    else if (name == "Nadya" && pass == "admin2") {
        return true;
    }
    else if (name == "Nada" && pass == "admin3") {
        return true;
    }
    return false;
}

void Admin::manageCatalog(Catalog  &updatecat){
    cout << "\nUpdate Helmet Catalog" << endl;
    updatecat.updateCatalog();
    cout << "Catalog updated successfully!" << endl;
}

void Admin::manageUsers(){
    cout << "\n=== MANAGE USER PROFILES ===" << endl;

    ifstream file("../02_data/data_user.csv");
    if (!file.is_open()) {
        cout << "[ERROR] Empty user database!" << endl;
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
        cout << "No registered users." << endl;
        return;
    }

    cout << "Registered User List:" << endl;
    for (size_t i = 0; i < usernames.size(); i++) {
        cout << i + 1 << ". " << usernames[i] << endl;
    }
    cout << "0. Cancel" << endl;

    int choice;
    cout << "\nSelect the user number you want to delete: ";
    cin >> choice;
    cin.ignore();

    if (choice == 0) return;
    if (choice < 1 || choice > (int)allLines.size()) {
        cout << "[ERROR] Invalid choice!" << endl;
        return;
    }

    cout << "Are you sure you want to delete account? '" << usernames[choice - 1] << "'? (y/n): ";
    string confirm;
    cin >> confirm;

    if (confirm == "y" || confirm == "Y") {
        
        ofstream file("../02_data/data_user.csv");
        
        for (size_t i = 0; i < allLines.size(); i++) {
            if (i != (choice - 1)) {
                file << allLines[i] << endl;
            }
        }
        file.close();
        cout << "[SUCCESS] User's profile successfully deleted!" << endl;
    } else {
        cout << "Deletion cancelled." << endl;
    }
}