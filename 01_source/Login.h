///////////////////////////////////////////////////////////
//  Login.h
//  Implementation of the Class Login
//  Created on:      30-Nov-2025 7:58:30 PM
//  Original author: nara
///////////////////////////////////////////////////////////

#ifndef LOGIN_H
#define LOGIN_H
#include <string>
using namespace std;
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
#endif // LOGIN_H
