///////////////////////////////////////////////////////////
//  Admin.cpp
//  Implementation of the Class Admin
//  Created on:      30-Nov-2025 7:58:31 PM
//  Original author: nara
///////////////////////////////////////////////////////////

#include "Admin.h"
#include <iostream>
#include <string>
using namespace std;

Admin::Admin(){

}

Admin::~Admin(){

}

bool Admin::loginAdmin(string pass){
    if (pass == "HelmetStore Jaya") return true;
    return false;
}

void Admin::manageCatalog(Catalog  &updatecat){
    cout << "\nUpdate Helmet Catalog" << endl;
    updatecat.updateCatalog();
    cout << "Catalog updated successfully!" << endl;
}