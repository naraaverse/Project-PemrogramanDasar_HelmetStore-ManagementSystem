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

void Catalog::updateCatalog() {
    int choice;
    do {
        cout << "\n=== ADMIN: MANAGE CATALOG ===" << endl;
        cout << "1. Add New Helmet" << endl;
        cout << "2. Edit Existing Helmet (Stock/Price)" << endl;
        cout << "0. Back to Admin Menu" << endl;
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            if (totalHelm >= 50) {
                cout << "[FULL] Can't add any more helmets." << endl;
            } else {
                cout << "\n--- ADD NEW HELM ---" << endl;
                
                cout << "Enter Brand : "; 
                getline(cin, helmetList[totalHelm].helmetBrand);
                
                cout << "Enter Color : "; 
                getline(cin, helmetList[totalHelm].helmetColor);
                
                cout << "Enter Type  : "; 
                getline(cin, helmetList[totalHelm].helmetType);
                
                cout << "Enter Price : "; 
                cin >> helmetList[totalHelm].helmetPrice;
                
                cout << "Enter Stock : "; 
                cin >> helmetList[totalHelm].availability;
                cin.ignore();

                totalHelm++;
                saveToFile();
                
                cout << "[SUCCESS] New helmet successfully added!" << endl;
                string pause; getline(cin, pause);
            }
        }
        else if (choice == 2) {
            cout << "\n--- HELMET LIST ---" << endl;
            for (int i = 0; i < totalHelm; i++) {
                 cout << (i + 1) << ". " << helmetList[i].helmetBrand
                      << " - Rp " << fixed << setprecision(0) << helmetList[i].helmetPrice
                      << " (Stock: " << helmetList[i].availability << ")" << endl;
            }
            int editIndex;
            cout << "Select the helmet number you want to edit: ";
            cin >> editIndex;
            cin.ignore();

            if (editIndex > 0 && editIndex <= totalHelm) {
                int idx = editIndex - 1;
                
                cout << "\nEdit Data: " << helmetList[idx].helmetBrand << endl;
                cout << "1. Stock Update" << endl;
                cout << "2. Price Update" << endl;
                cout << "Choice: ";
                int subChoice;
                cin >> subChoice;

                if (subChoice == 1) {
                    cout << "New stock: ";
                    cin >> helmetList[idx].availability;
                    saveToFile();
                    cout << "[UPDATED] Stock changed successfully!" << endl;
                } 
                else if (subChoice == 2) {
                    cout << "New price: ";
                    cin >> helmetList[idx].helmetPrice;
                    saveToFile();
                    cout << "[UPDATED] Price changed sucessfully!" << endl;
                }
                cin.ignore();
                string pause; getline(cin, pause);
            }
        }

    } while (choice != 0);
}

void Catalog::displayCatalog(){
    int option;

    do {
        cout << "\n=== CATALOG LIST ===" << endl;
        for (int i = 0; i < totalHelm; i++) {
            cout << (i + 1) << ". " << helmetList[i].helmetBrand << endl;
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
            string pause; getline(cin, pause);
        } else if (option != 0) {
            cout << "Invalid number!" << endl;
        }

    } while (option != 0);
}

void Catalog::saveToFile(){
    ofstream file("../02_data/data_helm.csv");
    if (!file.is_open()) {
        cout << "[ERROR] Unable to open database!" << endl;
        return;
    }

    file << "Brand,Color,Price,Type,Availability" << endl;
    for (int i = 0; i < totalHelm; i++) {
        file << helmetList[i].helmetBrand << ","
             << helmetList[i].helmetColor << ","
             << helmetList[i].helmetPrice << ","
             << helmetList[i].helmetType << ","
             << helmetList[i].availability << endl;
    }
    file.close();
}

HelmetItem Catalog::getHelmet(int index) {
    if (index >= 0 && index < totalHelm) {
        return helmetList[index];
    } else {
        HelmetItem empty;
        empty.helmetBrand = "Invalid";
        return empty;
    }
}