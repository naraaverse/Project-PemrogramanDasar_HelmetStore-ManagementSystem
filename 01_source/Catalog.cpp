///////////////////////////////////////////////////////////
//  Catalog.cpp
//  Implementation of the Class Catalog
//  Created on:      30-Nov-2025 7:58:31 PM
//  Original author: nara
///////////////////////////////////////////////////////////

#include "Catalog.h"
#include <iostream>

Catalog::Catalog(){
    helmetList[0].helmetBrand = "KYT Course";
    helmetList[0].helmetColor = "Blue";
    helmetList[0].helmetPrice = 150000;
    helmetList[0].helmetType = "Full Face";
    helmetList[0].availability = 10;
}

Catalog::~Catalog(){

}

void Catalog::updateCatalog(){
    /*cout << "Enter Helmet Brand: ";
    cin >> helmetBrand;
    cout << "Enter Helmet Color: ";
    cin >> helmetColor;
    cout << "Enter Helmet Price: ";
    cin >> helmetPrice;
    cout << "Enter Helmet Type: ";
    cin >> helmetType;
    cout << "Enter Availability (units): ";
    cin >> availability; */
}

void Catalog::displayCatalog(){
    /*cout << "\nHelmet Details Information\n";
    cout << "Brand: " << helmetBrand << endl;
    cout << "Color: " << helmetColor << endl;
    cout << "Price: Rp. " << helmetPrice << endl;
    cout << "Type: " << helmetType << endl;
    cout << "Availability: " << availability << " units" << endl;*/
}