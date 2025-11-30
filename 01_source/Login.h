///////////////////////////////////////////////////////////
//  Login.h
//  Implementation of the Class Login
//  Created on:      30-Nov-2025 7:46:20 PM
//  Original author: moog
///////////////////////////////////////////////////////////

#if !defined(EA_33E42764_28AC_4ce0_AD2E_C8AA5E3E0D4D__INCLUDED_)
#define EA_33E42764_28AC_4ce0_AD2E_C8AA5E3E0D4D__INCLUDED_

class Login
{

public:
	Login();
	virtual ~Login();

	bool verifyLogin();

private:
	string emailLogin;
	string passLogin;

};
#endif // !defined(EA_33E42764_28AC_4ce0_AD2E_C8AA5E3E0D4D__INCLUDED_)
