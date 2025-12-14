///////////////////////////////////////////////////////////
//  User.h
//  Implementation of the Class User
//  Created on:      30-Nov-2025 7:58:30 PM
//  Original author: nara
///////////////////////////////////////////////////////////

#ifndef USER_H
#define USER_H

#include "Registration.h"
#include "Login.h"
#include <string>
using namespace std;

class Catalog;
class Order;
class User{

public:
	User();
	virtual ~User();
	Order *m_Order;
	void editProfile();
	bool loginAccount();
	void registerAccount();
	void viewProfile();
	void viewCatalog(Catalog &viewcat);

private:
	string userAddress;
	string userBank;
	string userName;
	string userNumber;
	void verifyData();
};
#endif // USER_H
