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
#include "Order.h"
#include "Catalog.h"
#include <string>
using namespace std;
class User : public Registration, public Login, public Catalog
{

public:
	User();
	virtual ~User();
	Order *m_Order;
	void editProfile();
	bool loginAccount();
	void registerAccount();
	void viewProfile();

private:
	string userAddress;
	string userBank;
	string userName;
	string userNumber;
};
#endif // USER_H
