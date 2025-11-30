///////////////////////////////////////////////////////////
//  Registration.h
//  Implementation of the Class Registration
//  Created on:      30-Nov-2025 7:46:17 PM
//  Original author: moog
///////////////////////////////////////////////////////////

#if !defined(EA_7F2AD5FC_1FC0_4d7b_80AF_FAE029C2BBB4__INCLUDED_)
#define EA_7F2AD5FC_1FC0_4d7b_80AF_FAE029C2BBB4__INCLUDED_

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
#endif // !defined(EA_7F2AD5FC_1FC0_4d7b_80AF_FAE029C2BBB4__INCLUDED_)
