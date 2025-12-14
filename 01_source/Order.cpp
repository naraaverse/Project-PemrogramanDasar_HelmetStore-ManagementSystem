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

using namespace std;

Order::Order() {
}

Order::~Order() {
}

void Order::helmetOrder(User &user, Catalog &catalog) {
    catalog.showListCat();

    int helmetChoice;
    cout << "\nSelect your Helmet (Number): ";
    cin >> helmetChoice;
    cin.ignore();

    HelmetItem selectedHelmet = catalog.getHelmet(helmetChoice - 1);

    if (selectedHelmet.helmetPrice <= 0) {
        cout << "[ERROR] Invalid helmet selection." << endl;
        return;
    }

    int quantity;
    cout << "Purchase Amount: ";
    cin >> quantity;
    cin.ignore();

    if (quantity > selectedHelmet.availability) {
        cout << "[ERROR] Out of stock!" << endl;
        return;
    }

    customerName = user.getName();           
    helmetBrand  = selectedHelmet.helmetBrand;
    helmetColor  = selectedHelmet.helmetColor;
    helmetType   = selectedHelmet.helmetType;  

    double price = selectedHelmet.helmetPrice * quantity;

    cout << "\n===============================" << endl;
    cout << "      DETAIL HELMET ORDER      " << endl;
    cout << "===============================" << endl;
    cout << "Customer Name : " << customerName << endl;
    cout << "Helmet Brand  : " << helmetBrand << endl;
    cout << "Helmet Color  : " << helmetColor << endl;
    cout << "Helmet Type   : " << helmetType << endl;
    cout << "Quantity      : " << quantity << endl;
    cout << "Total Price   : Rp " << fixed << setprecision(0) << price << endl;
    cout << "===============================" << endl;

    cout << "Confirm purchase? (y/n): ";
    string confirm;
    getline(cin, confirm);

    if (confirm != "y" && confirm != "Y") {
        cout << "Order Cancelled." << endl;
        return;
    }

    if (myPayment.processPayment(price, paymentMethod)) {
        
        selectedHelmet.availability -= quantity; 
        
        cout << "\n###################################" << endl;
        cout << "         OFFICIAL RECEIPT          " << endl;
        cout << "###################################" << endl;
        cout << "Customer : " << customerName << endl;
        cout << "Item     : " << helmetBrand << " (" << helmetColor << ")" << endl;
        cout << "Qty      : " << quantity << endl;
        cout << "Total    : Rp " << fixed << setprecision(0) << price << endl;
        cout << "Payment  : " << paymentMethod << " [PAID]" << endl;
        cout << "###################################" << endl;
        cout << "        Thank You!                 " << endl;

        catalog.saveToFile(); 

    } else {
        cout << "[FAILED] Transaction Failed." << endl;
    }

    cout << "\nPress Enter to return...";
    string pause; getline(cin, pause);
}