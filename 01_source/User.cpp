///////////////////////////////////////////////////////////
//  User.cpp
//  Implementation of the Class User
//  Created on:      30-Nov-2025 7:58:30 PM
//  Original author: nara
///////////////////////////////////////////////////////////

#include "User.h"
#include <iostream>

User::User(){
	userAddress = "";
	userBank = "";
	userName = "";
	userNumber = "";
}

User::~User(){

}

void User::editProfile(){
	cout << "Edit Profile" << endl;
	cout << "Enter Name: ";
	getline(cin, userName);
	cout << "Enter Address: ";
	getline(cin, userAddress);
	cout << "Enter Phone Number: ";
	cin >> userNumber;
	cout << "Enter Bank: ";
	getline(cin, userBank);
	cout << "Profile updated successfully!" << endl;
}

bool User::loginAccount(){
}

void User::registerAccount(){
}

void User::viewProfile(){
	cout << "My Profile" << endl;
	cout << "Name: " << userName << endl;
	cout << "Address: " << userAddress << endl;
	cout << "Phone Number: " << userNumber << endl;
	cout << "Bank: " << userBank << endl;
}