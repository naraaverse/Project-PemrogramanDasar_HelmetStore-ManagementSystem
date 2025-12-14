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

void Order::helmetOrder(User &user, Catalog &catalog) {
    catalog.displayCatalog();
    int helmetChoice;
    cout << "Select your Helmet: ";
    cin >> helmetChoice;
    cin.ignore();

    HelmetItem selectedHelmet = catalog.getHelmet(helmetChoice - 1);
    if (selectedHelmet.helmetBrand == "Invalid") {
        cout << "Invalid helmet selection." << endl;
    }
    int quantity;
    cout << "Detail Helmet Order" << endl;
    cout << "Customer Name: ";
    getline(cin, customerName);
    cout << "Helmet Brand: ";
    getline(cin, helmetBrand);
    cout << "Helmet Color: ";
    cin >> helmetColor;
    cout << "Helmet Type: ";
    cin >> helmetType;
    cout << "Purchase Amount: ";
    cin >> quantity;

    myPayment.setPayment(selectedHelmet.helmetPrice, quantity);
    double price = myPayment.totalCost(); 
    cout << "Payment Method (Cash/Transfer/QRIS): ";
    getline(cin, paymentMethod);

    selectedHelmet.availability -= quantity;
    catalog.saveToFile();

    cout << "TOTAL    : Rp " << fixed << setprecision(0) << price << endl;
}