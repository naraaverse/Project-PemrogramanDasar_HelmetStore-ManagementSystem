///////////////////////////////////////////////////////////
//  Payment.cpp
//  Implementation of the Class Payment
//  Created on:      30-Nov-2025 7:58:32 PM
//  Original author: nara
///////////////////////////////////////////////////////////

#include "Payment.h"
#include <windows.h>
#include <iostream>
using namespace std;

Payment::Payment(){
}

Payment::~Payment(){

}

bool Payment::verifyPayment() {
    cout << "\n[SYSTEM] Connecting to Payment Gateway";
    
    for(int i=0; i<5; i++){
        cout << ".";
        Sleep(500);
    }
    
    cout << "\n[SYSTEM] Payment Verified Successfully!" << endl;
    return true; 
}

bool Payment::processPayment(double totalCost, string &method) {
    int choice;
    
    cout << "\n=== PAYMENT GATEWAY ===" << endl;
    cout << "Total Bill to Pay : Rp " << (long long)totalCost << endl; 
    cout << "Select Method:" << endl;
    cout << "1. QRIS (Scan Barcode)" << endl;
    cout << "2. Bank Transfer (Virtual Account)" << endl;
    cout << "3. Cash" << endl;
    cout << "Choice: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) method = "QRIS";
    else if (choice == 2) method = "Bank Transfer";
    else if (choice == 3) method = "Cash";
    else {
        cout << "[ERROR] Invalid Payment Method!" << endl;
        return false; 
    }

    cout << "\nProcessing " << method << "..." << endl;

    if (verifyPayment()) {
        return true;
    }
    return false;
}