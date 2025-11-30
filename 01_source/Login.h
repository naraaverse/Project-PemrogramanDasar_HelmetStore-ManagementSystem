///////////////////////////////////////////////////////////
//  Login.h
//  Implementation of the Class Login
//  Created on:      30-Nov-2025 7:58:30 PM
//  Original author: moog
///////////////////////////////////////////////////////////

#if !defined(EA_B4BC7310_9AE7_4798_BEE0_BFB3E3242D15__INCLUDED_)
#define EA_B4BC7310_9AE7_4798_BEE0_BFB3E3242D15__INCLUDED_

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
#endif // !defined(EA_B4BC7310_9AE7_4798_BEE0_BFB3E3242D15__INCLUDED_)
