///////////////////////////////////////////////////////////
//  Registration.h
//  Implementation of the Class Registration
//  Created on:      30-Nov-2025 7:58:29 PM
//  Original author: moog
///////////////////////////////////////////////////////////

#if !defined(EA_DA35F5F9_8576_48a3_9A81_7BBC51D8ECEE__INCLUDED_)
#define EA_DA35F5F9_8576_48a3_9A81_7BBC51D8ECEE__INCLUDED_

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
#endif // !defined(EA_DA35F5F9_8576_48a3_9A81_7BBC51D8ECEE__INCLUDED_)
