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
using namespace std;

User::User(){
}

User::~User(){

}

void User::editProfile(){
	cout << "Current Name: " << fullName << endl;
    cout << "Enter New Name: "; 
    getline(cin, fullName); 

    cout << "Current Address: " << address << endl;
    cout << "Enter New Address: "; 
    getline(cin, address);

    cout << "Current Phone: " << phoneNumber << endl;
    cout << "Enter New Phone: "; 
    getline(cin, phoneNumber);

	cout << "Profile updated successfully!" << endl;
}

bool User::loginAccount(){
	string inputUser, inputPass;
	cout << "\n=== User Login ===" << endl;
	cout << "Enter Username: "; getline(cin, inputUser);
	cout << "Enter Password: "; getline(cin, inputPass);

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
    cout << "[ERROR] Unable to open user data file!" << endl;
    return false;
}

    if (success) {
        cout << "[SUCCESS] Login Successful! Welcome, " << fullName << endl;
        return true;
    } else {
        cout << "[FAILED] Username or Password is false!" << endl;
        return false;
    }
}

void User::registerAccount(){
	cout << "\n=== New User Registration ===" << endl;
    cout << "Enter Username    : "; getline(cin, userName);
    cout << "Enter Password    : "; getline(cin, userPass);
    cout << "Nama Lengkap      : "; getline(cin, fullName);
    cout << "Alamat            : "; getline(cin, address);
    cout << "No HP             : "; getline(cin, phoneNumber);

    ofstream file("../02_data/data_user.csv", ios::app);

    if (file.is_open()) {
        file << userName << "," 
             << userPass << "," 
             << fullName << "," 
             << address << "," 
             << phoneNumber << endl;
        file.close();
        cout << "[SUCCESS] Account created successfully! Please login." << endl;
    } else {
        cout << "[ERROR] Failed to save user data!" << endl;
    }
}

void User::viewProfile(){
	cout << "My Profile" << endl;
	cout << "Username      : " << userName << endl;
	cout << "Full Name     : " << fullName << endl;
	cout << "Address       : " << address << endl;
	cout << "Phone Number  : " << phoneNumber << endl;
}

void User::viewCatalog(Catalog &viewcat){
	viewcat.displayCatalog();
}

string User::getName() {
    return fullName; 
}