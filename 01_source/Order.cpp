///////////////////////////////////////////////////////////
//  Order.cpp
//  Implementation of the Class Order
//  Created on:      30-Nov-2025 7:58:31 PM
//  Original author: nara
///////////////////////////////////////////////////////////

#include "Order.h"
#include <iostream>

Order::Order(){
    customerName = "";
    helmetBrand = "";
    helmetColor = "";
    helmetType = "";
    paymentMethod = "";
}

Order::~Order(){

}

void Order::helmetOrder(){
    cout << "Detail Helmet Order" << endl;
    cout << "Customer Name: ";
    getline(cin, customerName);
    cout << "Helmet Brand: ";
    getline(cin, helmetBrand);
    cout << "Helmet Color: ";
    cin >> helmetColor;
    cout << "Helmet Type: ";
    cin >> helmetType;
    cout << "Payment Method: ";
    cin >> paymentMethod;
}