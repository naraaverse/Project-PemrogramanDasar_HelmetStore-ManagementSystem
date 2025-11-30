///////////////////////////////////////////////////////////
//  User.h
//  Implementation of the Class User
//  Created on:      30-Nov-2025 7:58:30 PM
//  Original author: moog
///////////////////////////////////////////////////////////

#if !defined(EA_C958E64F_EDF3_43ce_8D68_850669CC0FEF__INCLUDED_)
#define EA_C958E64F_EDF3_43ce_8D68_850669CC0FEF__INCLUDED_

#include "Registration.h"
#include "Login.h"
#include "Order.h"
#include "Catalog.h"

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
#endif // !defined(EA_C958E64F_EDF3_43ce_8D68_850669CC0FEF__INCLUDED_)
