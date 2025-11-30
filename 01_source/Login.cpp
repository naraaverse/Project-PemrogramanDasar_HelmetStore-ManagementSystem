///////////////////////////////////////////////////////////
//  Login.cpp
//  Implementation of the Class Login
//  Created on:      30-Nov-2025 7:58:30 PM
//  Original author: nara
///////////////////////////////////////////////////////////

#include "Login.h"
#include <iostream>

Login::Login(){
	emailLogin = "";
	passLogin = "";
}

Login::~Login(){

}

bool Login::verifyLogin(){
	cout << "Enter your email: ";
	cin >> emailLogin;
	cout << "Enter your password: ";
	getline(cin, passLogin);
	return true;
}