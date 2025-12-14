#include <iostream>
#include <windows.h>
#include <iomanip>
#include "Admin.h"
#include "User.h"
#include "Catalog.h"
#include "Order.h"

using namespace std;

void showHeader() {
    system("cls");
    cout << "================================================================" << endl;
    cout << "  _    _      _                  _     _____ _                  " << endl;
    cout << " | |  | |    | |                | |   / ____| |                 " << endl;
    cout << " | |__| | ___| | |_ __ ___   ___| |_ | (___ | |_ ___  _ __ ___  " << endl;
    cout << " |  __  |/ _ \\ | | '_ ` _ \\ / _ \\ __| \\___ \\| __/ _ \\| '__/ _ \\ " << endl;
    cout << " | |  | |  __/ | | | | | | |  __/ |_  ____) | || (_) | | |  __/ " << endl;
    cout << " |_|  |_|\\___|_|_|_| |_| |_|\\___|\\__|/_____/ \\__\\___/|_|  \\___| " << endl;
    cout << "                                                                " << endl;
    cout << "          PREMIUM HELMET STORE MANAGEMENT SYSTEM v1.0           " << endl;
    cout << "================================================================" << endl;
}

void adminMenu(Catalog &catalog){
    Admin admin;
    int choice;
    do{
        system("cls");
        cout << "\n";
        cout << "\t+=======================================+" << endl;
        cout << "\t|            ADMIN DASHBOARD            |" << endl;
        cout << "\t+=======================================+" << endl;
        cout << "\t| 1. Login to Panel                     |" << endl;
        cout << "\t| 2. Back to Main Menu                  |" << endl;
        cout << "\t+=======================================+" << endl;
        cout << "\t Choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice){
            case 1:{
                string nameAdmin, passAdmin;
                system("cls");
                cout << "\n\t--- ADMIN LOGIN REQUIRED ---" << endl;
                cout << "\tUsername: "; getline(cin, nameAdmin);
                cout << "\tPassword: "; getline(cin, passAdmin);
                
                cout << "\n\tVerifying Credentials..." << endl;
                Sleep(800);

                if (admin.loginAdmin(nameAdmin, passAdmin)) {
                    int admOption;
                    do {
                        system("cls");
                        cout << "\n+------------------------------------------+" << endl;
                        cout << "|            ADMIN CONTROL PANEL           |" << endl;
                        cout << "+------------------------------------------+" << endl;
                        cout << "| 1. Manage Catalog (Add/Edit/Stock)       |" << endl;
                        cout << "| 2. Manage Users (View/Delete)            |" << endl;
                        cout << "| 0. Logout                                |" << endl;
                        cout << "+------------------------------------------+" << endl;
                        cout << " Select Option: ";
                        cin >> admOption;
                        cin.ignore();

                        switch (admOption) {
                            case 1: 
                                admin.manageCatalog(catalog);
                                break; 
                            case 2: 
                                admin.manageUsers();
                                break; 
                            case 0: {
                                cout << "\nLogging out..." << endl;
                                Sleep(1000);
                                break;
                            }
                            default:
                                cout << "Invalid option." << endl;
                                Sleep(1000);
                        }
                    } while (admOption != 0);
                }
                else {
                    cout << "\n\t[ACCESS DENIED] Incorrect Credentials!" << endl;
                    Sleep(1500);
                }
                break;
            }
            case 2:
                // Return to Main
                break;
            default:
                cout << "Invalid choice." << endl;
                Sleep(800);
        }
    } while(choice != 2);
}

void userMenu(Catalog &catalog){
    User user;
    int choice;
    do{
        system("cls");
        cout << "\n";
        cout << "\t+=======================================+" << endl;
        cout << "\t|             USER DASHBOARD            |" << endl;
        cout << "\t+=======================================+" << endl;
        cout << "\t| 1. Login                              |" << endl;
        cout << "\t| 2. Register New Account               |" << endl;
        cout << "\t| 3. View Catalog (Guest)               |" << endl;
        cout << "\t| 4. Back to Main Menu                  |" << endl;
        cout << "\t+=======================================+" << endl;
        cout << "\t Choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice){
            case 1:{
                if (user.loginAccount()) {
                    int userOption;
                    do {
                        system("cls");
                        cout << "\n========================================" << endl;
                        cout << " Welcome, " << user.getName() << "!" << endl;
                        cout << "========================================" << endl;
                        cout << " 1. My Profile (View)" << endl;
                        cout << " 2. Edit Profile" << endl;
                        cout << " 3. Order Helmet (Shop)" << endl;
                        cout << " 0. Logout" << endl;
                        cout << "----------------------------------------" << endl;
                        cout << " What would you like to do? ";
                        cin >> userOption;
                        cin.ignore();

                        if (userOption == 1) {
                            user.viewProfile();
                        } else if (userOption == 2) {
                            user.editProfile();
                        } else if (userOption == 3) {
                            Order newOrder;
                            newOrder.helmetOrder(user, catalog);
                        } else if (userOption == 0) {
                            cout << "\nLogging out... See you soon!" << endl;
                            Sleep(1000);
                        } else {
                            cout << "[!] Invalid option." << endl;
                            Sleep(800);
                        }
                    } while (userOption != 0);
                }
                break; 
            }
            case 2:
                user.registerAccount();
                break;

            case 3:
                user.viewCatalog(catalog);
                break;

            case 4:
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                Sleep(800);
        }
    } while (choice != 4);
}

int main() {
    system("title Helmet Store Management System");
    
    Catalog shopCatalog;
    int mainChoice;

    do {
        showHeader();
        cout << "\t[1] Login as Admin" << endl;
        cout << "\t[2] Login as User / Guest" << endl;
        cout << "\t[0] Exit Application" << endl;
        cout << "\n\tSelect Role > ";
        cin >> mainChoice;
        cin.ignore(); 

        switch (mainChoice) {
            case 1:
                adminMenu(shopCatalog); 
                break;
            case 2:
                userMenu(shopCatalog);
                break;
            case 0:
                system("cls");
                cout << "\n\n\n";
                cout << "\t==============================================" << endl;
                cout << "\t   THANK YOU FOR USING OUR SYSTEM. BYE! ^_^   " << endl;
                cout << "\t==============================================" << endl;
                cout << "\n\n";
                Sleep(1000);
                break;
            default:
                cout << "\n\t[!] Invalid choice! Please try again." << endl;
                Sleep(1000);
        }
    } while (mainChoice != 0);

    return 0;
}