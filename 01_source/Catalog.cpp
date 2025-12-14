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
#include <windows.h>

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
        getline(ss, availability, ',');

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
        system("cls");
        cout << "+------------------------------------------+" << endl;
        cout << "|        HELMET INVENTORY MANAGER          |" << endl;
        cout << "+------------------------------------------+" << endl;
        cout << "| 1. Add New Helmet                        |" << endl;
        cout << "| 2. Edit Stock / Price                    |" << endl;
        cout << "| 0. Back to Admin Menu                    |" << endl;
        cout << "+------------------------------------------+" << endl;
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            if (totalHelm >= 50) {
                cout << "\n[!] STORAGE FULL: Capacity reached (50/50)." << endl;
                system("pause");
            } else {
                cout << "\n--- ADD NEW ITEM ENTRY ---" << endl;
                
                cout << "Brand Name : "; 
                getline(cin, helmetList[totalHelm].helmetBrand);
                
                cout << "Color      : "; 
                getline(cin, helmetList[totalHelm].helmetColor);
                
                cout << "Type       : "; 
                getline(cin, helmetList[totalHelm].helmetType);
                
                cout << "Price (Rp) : "; 
                cin >> helmetList[totalHelm].helmetPrice;
                
                cout << "Stock Qty  : "; 
                cin >> helmetList[totalHelm].availability;
                cin.ignore();

                totalHelm++;
                saveToFile();
                
                cout << "\n[SAVING]";
                for(int i = 0; i < 3; i++){ cout << "."; Sleep(200); }
                cout << "\n[SUCCESS] New helmet added to database!" << endl;
                Sleep(1000);
            }
        }
        else if (choice == 2) {
            showListCat(); 
            
            int editIndex;
            cout << "\nSelect Number to Edit (0 Cancel): ";
            cin >> editIndex;
            cin.ignore();

            if (editIndex > 0 && editIndex <= totalHelm) {
                int idx = editIndex - 1;
                
                system("cls");
                cout << "\nEDITING: " << helmetList[idx].helmetBrand << " (" << helmetList[idx].helmetColor << ")" << endl;
                cout << "---------------------------------" << endl;
                cout << "1. Update Stock Only" << endl;
                cout << "2. Update Price Only" << endl;
                cout << "Choice: ";
                int subChoice;
                cin >> subChoice;

                if (subChoice == 1) {
                    cout << "Current Stock: " << helmetList[idx].availability << endl;
                    cout << "New Stock    : ";
                    cin >> helmetList[idx].availability;
                    saveToFile();
                    cout << "[UPDATED] Stock updated successfully!" << endl;
                } 
                else if (subChoice == 2) {
                    cout << "Current Price: " << (long long)helmetList[idx].helmetPrice << endl;
                    cout << "New Price    : ";
                    cin >> helmetList[idx].helmetPrice;
                    saveToFile();
                    cout << "[UPDATED] Price updated successfully!" << endl;
                }
                cin.ignore();
                Sleep(1000);
            }
        }

    } while (choice != 0);
}

void Catalog::displayCatalog(){
    int option;

    do {
        system("cls");
        showListCat(); 
        
        cout << "\n[MENU OPTIONS]" << endl;
        cout << "Enter Number to View Details (0 Back): ";
        cin >> option;
        cin.ignore();

        if (option > 0 && option <= totalHelm) {
            int index = option - 1;
            
            system("cls");
            cout << "\n";
            cout << "\t+=======================================+" << endl;
            cout << "\t|         PRODUCT SPECIFICATION         |" << endl;
            cout << "\t+=======================================+" << endl;
            cout << "\t|                                       |" << endl;
            cout << "\t|  Brand   : " << left << setw(26) << helmetList[index].helmetBrand << "|" << endl;
            cout << "\t|  Type    : " << left << setw(26) << helmetList[index].helmetType << "|" << endl;
            cout << "\t|  Color   : " << left << setw(26) << helmetList[index].helmetColor << "|" << endl;
            cout << "\t|  Stock   : " << left << setw(26) << helmetList[index].availability << "|" << endl;
            cout << "\t|                                       |" << endl;
            cout << "\t|  PRICE   : Rp " << left << setw(21) << (long long)helmetList[index].helmetPrice << "|" << endl;
            cout << "\t|                                       |" << endl;
            cout << "\t+=======================================+" << endl;
            
            cout << "\n\t   [Press Enter to return to Catalog]";
            string pause; getline(cin, pause);
            
        } else if (option != 0) {
            cout << "\n[!] Invalid input number!" << endl;
            Sleep(800);
        }

    } while (option != 0);
}

void Catalog::showListCat(){
    cout << "\n=== HELMET CATALOG COLLECTION ===" << endl;
    
    cout << "+----+--------------------------+---------------+---------------+-------+" << endl;
    cout << "| No | Brand Name               | Color         | Price (Rp)    | Stock |" << endl;
    cout << "+----+--------------------------+---------------+---------------+-------+" << endl;

    for (int i = 0; i < totalHelm; i++) {
        string stockAlert = (helmetList[i].availability < 5) ? " (!)" : ""; 
        
        cout << "| " << left << setw(2) << (i + 1) 
             << " | " << left << setw(24) << helmetList[i].helmetBrand
             << " | " << left << setw(13) << helmetList[i].helmetColor
             << " | " << right << setw(11) << (long long)helmetList[i].helmetPrice << "   " // Harga rata kanan
             << " | " << left << setw(3) << helmetList[i].availability << stockAlert << " |" << endl;
    }
    cout << "+----+--------------------------+---------------+---------------+-------+" << endl;
}

void Catalog::saveToFile(){
    ofstream file("../02_data/data_helm.csv");
    if (!file.is_open()) {
        cout << "[ERROR] Unable to open database for writing!" << endl;
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
        empty.helmetPrice = 0; 
        return empty;
    }
}