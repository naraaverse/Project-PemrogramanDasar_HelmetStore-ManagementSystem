///////////////////////////////////////////////////////////
//  User.cpp
//  Implementation of the Class User
//  Created on:      30-Nov-2025 7:58:30 PM
//  Original author: nara
///////////////////////////////////////////////////////////

#include "User.h"
#include "Catalog.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip> 
#include <windows.h> //for Sleep

using namespace std;

User::User(){
}

User::~User(){
}

void User::registerAccount(){
    system("cls");
    cout << "\n";
    cout << "\t+---------------------------------------+" << endl;
    cout << "\t|           NEW USER REGISTER           |" << endl;
    cout << "\t+---------------------------------------+" << endl;
    cout << "\t Username       : "; getline(cin, userName);
    cout << "\t Password       : "; getline(cin, userPass);
    cout << "\t Full Name      : "; getline(cin, fullName);
    cout << "\t Address        : "; getline(cin, address);
    cout << "\t Phone Number   : "; getline(cin, phoneNumber);
    cout << "\t+---------------------------------------+" << endl;

    cout << "\n\t Creating Account";
    for(int i=0; i<3; i++) { cout << "."; Sleep(300); }

    ofstream file("../02_data/data_user.csv", ios::app);

    if (file.is_open()) {
        file << userName << "," 
             << userPass << "," 
             << fullName << "," 
             << address << "," 
             << phoneNumber << endl;
        file.close();
        
        cout << "\n\t [SUCCESS] Account created! Please Login." << endl;
        Sleep(1500);
    } else {
        cout << "\n\t [ERROR] Failed to save database!" << endl;
        Sleep(1500);
    }
}

bool User::loginAccount(){
    string inputUser, inputPass;
    
    system("cls");
    cout << "\n";
    cout << "\t+=======================================+" << endl;
    cout << "\t|              LOGIN PAGE               |" << endl;
    cout << "\t+=======================================+" << endl;
    cout << "\t|                                       |" << endl;
    cout << "\t|  Username : "; getline(cin, inputUser);
    cout << "\t|  Password : "; getline(cin, inputPass);
    cout << "\t|                                       |" << endl;
    cout << "\t+=======================================+" << endl;

    cout << "\n\t Authenticating";
    for(int i = 0; i < 4; i++) { cout << "."; Sleep(200); }

    ifstream file("../02_data/data_user.csv");
    string line;
    bool success = false;

    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            string csvUser, csvPass, csvName, csvAddr, csvPhone;

            getline(ss, csvUser, ',');
            getline(ss, csvPass, ',');
            getline(ss, csvName, ',');
            getline(ss, csvAddr, ',');
            getline(ss, csvPhone, ',');

            if (csvUser == inputUser && csvPass == inputPass) {
                success = true;
            
                userName = csvUser;
                userPass = csvPass;
                fullName = csvName;
                address  = csvAddr;
                phoneNumber = csvPhone;
                
                break;
            }
        }
        file.close();
    } else {
        cout << "\n\t [ERROR] Database Connection Failed!" << endl;
        return false;
    }

    if (success) {
        cout << "\n\t [SUCCESS] Welcome back, " << fullName << "!" << endl;
        Sleep(1000);
        return true;
    } else {
        cout << "\n\t [FAILED] Wrong Username or Password!" << endl;
        Sleep(1000);
        return false;
    }
}

void User::viewProfile(){
    system("cls");
    cout << "\n";
    cout << "\t+===========================================+" << endl;
    cout << "\t|              MY USER PROFILE              |" << endl;
    cout << "\t+===========================================+" << endl;
    cout << "\t|                                           |" << endl;
    cout << "\t|  Username  : " << left << setw(29) << userName << "|" << endl;
    cout << "\t|  Full Name : " << left << setw(29) << fullName << "|" << endl;
    cout << "\t|  Address   : " << left << setw(29) << address << "|" << endl;
    cout << "\t|  Phone     : " << left << setw(29) << phoneNumber << "|" << endl;
    cout << "\t|                                           |" << endl;
    cout << "\t+===========================================+" << endl;
    
    cout << "\n\t Press Enter to return...";
    string dummy; getline(cin, dummy);
}

void User::editProfile(){
    system("cls");
    cout << "\n=== EDIT PROFILE ===" << endl;
    cout << "---------------------------" << endl;
    
    cout << "CHANGE NAME" << endl;
    cout << "Current : " << fullName << endl;
    cout << "New Name: "; 
    getline(cin, fullName); 

    cout << "\nCHANGE ADDRESS" << endl;
    cout << "Current : " << address << endl;
    cout << "New Addr: "; 
    getline(cin, address);

    cout << "\nCHANGE PHONE" << endl;
    cout << "Current : " << phoneNumber << endl;
    cout << "New No  : "; 
    getline(cin, phoneNumber);

    cout << "\nSaving Changes";
    for(int i = 0; i < 3; i++) { cout << "."; Sleep(300); }
    
    cout << "\n[SUCCESS] Profile updated successfully!" << endl;
    Sleep(1000);
}

void User::viewCatalog(Catalog &viewcat){
    viewcat.displayCatalog();
}

string User::getName() {
    return fullName; 
}