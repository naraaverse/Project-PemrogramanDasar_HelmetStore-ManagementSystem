///////////////////////////////////////////////////////////
//  Order.cpp
//  Implementation of the Class Order
//  Created on:      30-Nov-2025 7:58:31 PM
//  Original author: nara
///////////////////////////////////////////////////////////

#include "Order.h"
#include "User.h"
#include "Catalog.h"
#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

Order::Order() {
}

Order::~Order() {
}

void Order::helmetOrder(User &user, Catalog &catalog) {
    system("cls");
    catalog.showListCat(); 

    int helmetChoice;
    cout << "\n[INPUT ORDER]" << endl;
    cout << "Select Helmet Number (0 Cancel): ";
    cin >> helmetChoice;
    cin.ignore();

    if (helmetChoice == 0) return;

    HelmetItem selectedHelmet = catalog.getHelmet(helmetChoice - 1);

    if (selectedHelmet.helmetPrice <= 0) {
        cout << "\n[ERROR] Invalid helmet selection!" << endl;
        Sleep(1000);
        return;
    }

    int quantity;
    cout << "Purchase Amount: ";
    cin >> quantity;
    cin.ignore();

    if (quantity > selectedHelmet.availability) {
        cout << "\n[OUT OF STOCK] Available only " << selectedHelmet.availability << " units." << endl;
        Sleep(1500);
        return;
    }

    customerName = user.getName();           
    helmetBrand  = selectedHelmet.helmetBrand;
    helmetColor  = selectedHelmet.helmetColor;
    helmetType   = selectedHelmet.helmetType;  
    double price = selectedHelmet.helmetPrice * quantity;

    system("cls");
    cout << "\n";
    cout << "\t+---------------------------------------+" << endl;
    cout << "\t|           ORDER CONFIRMATION          |" << endl;
    cout << "\t+---------------------------------------+" << endl;
    cout << "\t| Customer : " << left << setw(26) << customerName.substr(0, 26) << " |" << endl;
    cout << "\t| Item     : " << left << setw(26) << helmetBrand << " |" << endl;
    cout << "\t| Type     : " << left << setw(26) << helmetType << " |" << endl;
    cout << "\t| Color    : " << left << setw(26) << helmetColor << " |" << endl;
    cout << "\t| Quantity : " << left << setw(26) << quantity << " |" << endl;
    cout << "\t| ------------------------------------- |" << endl;
    cout << "\t| BILL     : Rp " << left << setw(23) << (long long)price << " |" << endl;
    cout << "\t+---------------------------------------+" << endl;
    
    cout << "\n\t Proceed to Payment? (y/n): ";
    string confirm;
    getline(cin, confirm);

    if (confirm != "y" && confirm != "Y") {
        cout << "\n\t [!] Order Cancelled." << endl;
        Sleep(1000);
        return;
    }

    if (myPayment.processPayment(price, paymentMethod)) {
        
        selectedHelmet.availability -= quantity; 

        cout << "\n\n[SYSTEM] Printing Receipt";
        for(int i = 0; i < 4; i++) { cout << "."; Sleep(300); }
        
        system("cls");
        cout << "\n";
        cout << "\t/===============================\\" << endl;
        cout << "\t|       OFFICIAL RECEIPT        |" << endl;
        cout << "\t|      HELMET STORE SYSTEM      |" << endl;
        cout << "\t|-------------------------------|" << endl;
        cout << "\t| DATE: " << __DATE__ << "              |" << endl;
        cout << "\t| TIME: " << __TIME__ << "              |" << endl;
        cout << "\t|-------------------------------|" << endl;
        cout << "\t| CUST : " << left << setw(22) << customerName.substr(0, 22) << " |" << endl;
        cout << "\t| ITEM : " << left << setw(22) << helmetBrand << " |" << endl;
        cout << "\t| VAR  : " << left << setw(22) << helmetColor << " |" << endl;
        cout << "\t| QTY  : " << left << setw(22) << quantity << " |" << endl;
        cout << "\t|                               |" << endl;
        cout << "\t| TOTAL: Rp " << left << setw(19) << (long long)price << " |" << endl;
        cout << "\t| PAY  : " << left << setw(22) << paymentMethod << " |" << endl;
        cout << "\t| STATUS: PAID (VERIFIED)       |" << endl;
        cout << "\t|===============================|" << endl;
        cout << "\t|     THANK YOU FOR SHOPPING    |" << endl;
        cout << "\t\\===============================/" << endl;

        catalog.saveToFile(); 

    } else {
        cout << "\n[!] Transaction Failed / Cancelled." << endl;
    }

    cout << "\nPress Enter to return dashboard...";
    string pause; getline(cin, pause);
}