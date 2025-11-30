///////////////////////////////////////////////////////////
//  Registration.cpp
//  Implementation of the Class Registration
//  Created on:      30-Nov-2025 7:58:30 PM
//  Original author: nara
///////////////////////////////////////////////////////////

#include "Registration.h"
#include <iostream>

Registration::Registration(){
    emailUser = "";
    passUser = "";
}

Registration::~Registration(){

}

void Registration::verifyData(){
    cout << "Register your account" << endl;
    cout << "Enter your email: ";
    cin >> emailUser;
    cout << "Enter your password: ";
    cin >> passUser;
    cout << "Registration successful!" << endl;
}