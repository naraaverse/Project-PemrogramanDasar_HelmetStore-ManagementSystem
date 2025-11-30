///////////////////////////////////////////////////////////
//  User.h
//  Implementation of the Class User
//  Created on:      30-Nov-2025 7:46:22 PM
//  Original author: moog
///////////////////////////////////////////////////////////

#if !defined(EA_8EED6CC5_3AEA_4c95_BC72_832003C19157__INCLUDED_)
#define EA_8EED6CC5_3AEA_4c95_BC72_832003C19157__INCLUDED_

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
#endif // !defined(EA_8EED6CC5_3AEA_4c95_BC72_832003C19157__INCLUDED_)
