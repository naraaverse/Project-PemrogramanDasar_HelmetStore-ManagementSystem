///////////////////////////////////////////////////////////
//  Payment.cpp
//  Implementation of the Class Payment
//  Created on:      30-Nov-2025 7:58:32 PM
//  Original author: nara
///////////////////////////////////////////////////////////

#include "Payment.h"
#include <windows.h>
#include <iostream>
#include <iomanip> 
#include <cstdlib>
#include <ctime>  

using namespace std;

Payment::Payment(){
    srand(time(0)); // Reset random seed
}

Payment::~Payment(){
}

bool Payment::verifyPayment() {
    cout << "\n\t[SYSTEM] Contacting Payment Gateway";
    
    for(int i = 0; i < 6; i++){
        cout << ".";
        Sleep(400);
    }
    
    cout << "\n\t[SYSTEM] Transaction Verified Successfully!" << endl;
    Sleep(1000);
    return true; 
}

bool Payment::processPayment(double totalCost, string &method) {
    int choice;
    
    system("cls");
    cout << "\n";
    cout << "\t+=======================================+" << endl;
    cout << "\t|            PAYMENT GATEWAY            |" << endl;
    cout << "\t+=======================================+" << endl;
    cout << "\t|                                       |" << endl;
    cout << "\t|  TOTAL BILL : Rp " << left << setw(20) << (long long)totalCost << "|" << endl;
    cout << "\t|                                       |" << endl;
    cout << "\t|  [1] QRIS (Scan Barcode)              |" << endl;
    cout << "\t|  [2] Bank Transfer (Virtual Account)  |" << endl;
    cout << "\t|  [3] Cash (Tunai)                     |" << endl;
    cout << "\t|  [0] CANCEL TRANSACTION               |" << endl;
    cout << "\t|                                       |" << endl;
    cout << "\t+=======================================+" << endl;
    cout << "\t Select Method > ";
    cin >> choice;
    cin.ignore();

    if (choice == 0) {
        cout << "\n\t [!] Transaction Cancelled by User." << endl;
        return false;
    }

    if (choice == 1) {
        method = "QRIS";
        // Simulasi Tampilan QRIS
        cout << "\n\t Generating QR Code..." << endl;
        Sleep(800);
        cout << "\n";
        cout << "\t   +--------------+" << endl;
        cout << "\t   |  [][][][][]  |" << endl;
        cout << "\t   |  []  QR  []  |  <-- SCAN HERE" << endl;
        cout << "\t   |  [][][][][]  |" << endl;
        cout << "\t   +--------------+" << endl;
        cout << "\t   (Waiting for scan...)" << endl;
        Sleep(2000);
    }
    else if (choice == 2) {
        method = "Bank Transfer";
        // Generate Random VA Number
        string vaNumber = "8800" + to_string(rand() % 90000 + 10000); 
        cout << "\n\t Generating Virtual Account..." << endl;
        Sleep(800);
        cout << "\n\t+---------------------------------+" << endl;
        cout << "\t|  BANK MANDIRI VIRTUAL ACCOUNT   |" << endl;
        cout << "\t|  NO: " << vaNumber << "            |" << endl;
        cout << "\t+---------------------------------+" << endl;
        cout << "\t (Simulating transfer from M-Banking...)" << endl;
        Sleep(2000); 
    }
    else if (choice == 3) {
        method = "Cash";
        cout << "\n\t Please pay at the cashier counter." << endl;
        Sleep(1000);
    }
    else {
        cout << "\n\t [ERROR] Invalid Payment Method!" << endl;
        Sleep(1000);
        return false; 
    }

    cout << "\n\t Processing " << method << " Payment..." << endl;

    if (verifyPayment()) {
        return true;
    }
    return false;
}