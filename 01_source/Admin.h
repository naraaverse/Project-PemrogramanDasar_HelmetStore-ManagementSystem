///////////////////////////////////////////////////////////
//  Admin.h
//  Implementation of the Class Admin
//  Created on:      30-Nov-2025 7:46:23 PM
//  Original author: moog
///////////////////////////////////////////////////////////

#if !defined(EA_D431C0A4_68A7_4d74_A330_0CF578144935__INCLUDED_)
#define EA_D431C0A4_68A7_4d74_A330_0CF578144935__INCLUDED_

#include "Catalog.h"

class Admin : public Catalog
{

public:
	Admin();
	virtual ~Admin();

	bool manageCatalog();

private:
	string adminEmail;
	string adminPass;

};
#endif // !defined(EA_D431C0A4_68A7_4d74_A330_0CF578144935__INCLUDED_)
