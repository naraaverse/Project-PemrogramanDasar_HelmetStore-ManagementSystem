#include <bits/stdc++.h>
#include "Admin.h"
#include "User.h"
#include "Catalog.h"
using namespace std;

void adminMenu(){
    Admin admin;
    int choice;
    do{
        cout << "Admin Dashboard" << endl;
        cout << "1. Login" << endl;
        cout << "2. Back to Main Menu" << endl;
        cout << "Choose your option:" << endl;
        cin >> choice;
        switch(choice){
            case 1:{
                string passAdmin;
                cout << "Enter Admin Password: ";
                getline(cin, passAdmin);
                if (admin.loginAdmin(passAdmin)) {
                    int admOption;
                    do {
                        cout << "Welcome to Admin Panel!" << endl;
                        cout << "1. Manage Catalog" << endl;
                        cout << "2. Logout" << endl;
                        cout << "Choice: ";
                        cin >> admOption;
                        switch (admOption) {
                            case 1: {
                                Catalog updatecat;
                                admin.manageCatalog(updatecat);
                                break; 
                            }
                            case 2: {
                                string answer;
                                cout << "Are you sure? (yes/no): ";
                                cin >> answer;
                                if (answer == "yes") {
                                    cout << "Logged out successfully!" << endl;
                                    admOption = 0;
                                } else {
                                    cout << "Returning to Admin Panel" << endl;
                                }
                                break;
                            }
                            default:
                                cout << "Invalid option. Please try again." << endl;
                        }
                    } while (admOption != 0);
                }
                else {
                    cout << "Incorrect Password. Access Denied." << endl;
                }
            break;
            }
            case 2:
                cout << "Returning to Main Menu" << endl;
                break;
        }
    }while(choice != 2);
}

void userMenu(){
    User user;
    int choice;
    do{
        cout << "User Dashboard" << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. View Catalog" << endl;
        cout << "4. Back to Main Menu" << endl;
        cout << "Choose your option:" << endl;
        cin >> choice;
        switch(choice){
        }
    } while (choice != 3);
}