#include <iostream>
#include "Admin.h"
#include "User.h"
#include "Catalog.h"
#include "Order.h"
using namespace std;

void adminMenu(Catalog &catalog){
    Admin admin;
    int choice;
    do{
        cout << "\nAdmin Dashboard" << endl;
        cout << "1. Login" << endl;
        cout << "2. Back to Main Menu" << endl;
        cout << "Choose your option: ";
        cin >> choice;
        cin.ignore();

        switch(choice){
            case 1:{
                string nameAdmin, passAdmin;
                cout << "\nEnter Admin Name: ";
                getline(cin, nameAdmin);
                cout << "Enter Admin Password: ";
                getline(cin, passAdmin);
                if (admin.loginAdmin(nameAdmin, passAdmin)) {
                    int admOption;
                    do {
                        cout << "\nWelcome to Admin Panel!" << endl;
                        cout << "1. Manage Catalog" << endl;
                        cout << "2. Logout" << endl;
                        cout << "Choice: ";
                        cin >> admOption;
                        cin.ignore();

                        switch (admOption) {
                            case 1: {
                                admin.manageCatalog(catalog);
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
                    cout << "Incorrect Name or Password. Access Denied." << endl;
                }
            break;
            }
            case 2:
                cout << "Returning to Main Menu" << endl;
                break;
        }
    }while(choice != 2);
}

void userMenu(Catalog &catalog){
    User user;
    int choice;
    do{
        cout << "\nUser Dashboard" << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. View Catalog" << endl;
        cout << "4. Back to Main Menu" << endl;
        cout << "Choose your option: ";
        cin >> choice;
        cin.ignore();

        switch(choice){
            case 1:{
                if (user.loginAccount()) {
                    int userOption;
                    do {
                        cout << "\nHi " << user.getName() << "! What you gonna do?" << endl;
                        cout << "1. Update Profile" << endl;
                        cout << "2. View Profile" << endl;
                        cout << "3. Order Helmet" << endl;
                        cout << "0. Logout" << endl;
                        cout << "Choice: ";
                        cin >> userOption;
                        cin.ignore();

                        if (userOption == 1) {
                            user.editProfile();
                        } else if (userOption == 2) {
                            user.viewProfile();
                        } else if (userOption == 3) {
                            Order newOrder;
                            newOrder.helmetOrder(user, catalog);
                        } else if (userOption == 0) {
                            cout << "Logging out" << endl;
                        } else {
                            cout << "Invalid option." << endl;
                        }
                    } while (userOption != 3);
                }
                break; 
            }
            case 2:
                user.registerAccount();
                break;

            case 3:{
                user.viewCatalog(catalog);
                break;
            }
            case 4:
                cout << "Returning to Main Menu" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);
}

int main() {
    Catalog shopCatalog;
    int mainChoice;

    do {
        cout << "\n======================================\n";
        cout << "   HELMET STORE MANAGEMENT SYSTEM     " << endl;
        cout << "======================================\n";
        cout << "1. Login as Admin" << endl;
        cout << "2. Login as User" << endl;
        cout << "3. Exit" << endl;
        cout << "======================================\n";
        cout << "Choose Menu: ";
        cin >> mainChoice;
        cin.ignore(); 

        switch (mainChoice) {
            case 1:
                adminMenu(shopCatalog); 
                break;
            case 2:
                userMenu(shopCatalog);
                break;
            case 3:
                cout << "Thank you for visiting this site! Have a nice day ^_^" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (mainChoice != 3);

}