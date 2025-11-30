///////////////////////////////////////////////////////////
//  Registration.h
//  Implementation of the Class Registration
//  Created on:      30-Nov-2025 7:58:29 PM
//  Original author: nara
///////////////////////////////////////////////////////////

#ifndef REGISTRATION_H
#define REGISTRATION_H
#include <string>
using namespace std;
class Registration
{

public:
	Registration();
	virtual ~Registration();
	void verifyData();

private:
	string emailUser;
	string passUser;
};
#endif // REGISTRATION_H
