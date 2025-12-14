///////////////////////////////////////////////////////////
//  User.h
//  Implementation of the Class User
//  Created on:      30-Nov-2025 7:58:30 PM
//  Original author: nara
///////////////////////////////////////////////////////////

#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
using namespace std;

class Catalog;
class Order;
class User{

public:
	User();
	virtual ~User();
	Order *m_Order;

	bool loginAccount();
	void registerAccount();

	void editProfile();
	void viewProfile();
	void viewCatalog(Catalog &viewcat);

	string getName();

private:
	string userName;
	string userPass;
	string address;
	string fullName;
	string phoneNumber;
};
#endif // USER_H
