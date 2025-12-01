///////////////////////////////////////////////////////////
//  Catalog.cpp
//  Implementation of the Class Catalog
//  Created on:      30-Nov-2025 7:58:31 PM
//  Original author: nara
///////////////////////////////////////////////////////////

#include "Catalog.h"
#include <iostream>

Catalog::Catalog(){
    availability = 10;
    helmetBrand = "KYT Course";
    helmetColor = "Blue";
    helmetPrice = 150000;
    helmetType = "Full Face";
}

Catalog::~Catalog(){

}

void Catalog::updateCatalog(){
    cout << "Enter Helmet Brand: ";
    cin >> helmetBrand;
    cout << "Enter Helmet Color: ";
    cin >> helmetColor;
    cout << "Enter Helmet Price: ";
    cin >> helmetPrice;
    cout << "Enter Helmet Type: ";
    cin >> helmetType;
    cout << "Enter Availability (units): ";
    cin >> availability;
}

void Catalog::displayCatalog(){
    cout << "\nHelmet Details Information\n";
    cout << "Brand: " << helmetBrand << endl;
    cout << "Color: " << helmetColor << endl;
    cout << "Price: Rp. " << helmetPrice << endl;
    cout << "Type: " << helmetType << endl;
    cout << "Availability: " << availability << " units" << endl;
}