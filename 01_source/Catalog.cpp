///////////////////////////////////////////////////////////
//  Catalog.cpp
//  Implementation of the Class Catalog
//  Created on:      30-Nov-2025 7:58:31 PM
//  Original author: nara
///////////////////////////////////////////////////////////

#include "Catalog.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

Catalog::Catalog(){
    totalHelm = 0;
    ifstream file("../02_data/data_helm.csv");

    if (!file.is_open()) {
        cout << "[ERROR] Database file not found!" << endl;
        return;
    }

    string line;
    getline(file, line); // Skip header line
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string brand, color, type, price, availability;

        getline(ss, brand, ',');
        getline(ss, color, ',');
        getline(ss, price, ',');
        getline(ss, type, ',');
        getline(ss, availability, ',');\

        if(totalHelm < 50) {
            helmetList[totalHelm].helmetBrand = brand;
            helmetList[totalHelm].helmetColor = color;
            helmetList[totalHelm].helmetPrice = stod(price);
            helmetList[totalHelm].helmetType = type;
            helmetList[totalHelm].availability = stoi(availability);
            totalHelm++;
        }
    }
    file.close();
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
    int option;

    do {
        cout << "\n=== CATALOG LIST ===" << endl;
        for (int i = 0; i < totalHelm; i++) {
            cout << (i + 1) << ". " << helmetList[i].helmetBrand
                 << " [" << helmetList[i].helmetType << "] " 
                 << " - " << helmetList[i].helmetColor 
                 << " (Rp " << fixed << setprecision(0) << helmetList[i].helmetPrice << ") "
                 << "Stok: " << helmetList[i].availability << endl;
        }
        cout << "0. Back to Menu" << endl;
        cout << "Select number to view details: ";
        cin >> option;
        cin.ignore();
        if (option > 0 && option <= totalHelm) {
            int index = option - 1;
            cout << "\n--- HELM DETAILS SPECIFICATION ---" << endl;
            cout << "Brand        : " << helmetList[index].helmetBrand << endl;
            cout << "Color        : " << helmetList[index].helmetColor << endl;
            cout << "Price        : Rp " << fixed << setprecision(0) << helmetList[index].helmetPrice << endl;
            cout << "Type         : " << helmetList[index].helmetType << endl;
            cout << "Availability : " << helmetList[index].availability << " units" << endl;
            
            cout << "------------------------" << endl;
            cout << "Click Enter to return to Catalog";
            string enterKey;
            getline(cin, enterKey);
        } else if (option != 0) {
            cout << "Invalid number!" << endl;
        }

    } while (option != 0);
}