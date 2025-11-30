///////////////////////////////////////////////////////////
//  Admin.h
//  Implementation of the Class Admin
//  Created on:      30-Nov-2025 7:58:31 PM
//  Original author: moog
///////////////////////////////////////////////////////////

#if !defined(EA_2E32F519_B8EA_4117_9A34_72066B130EE6__INCLUDED_)
#define EA_2E32F519_B8EA_4117_9A34_72066B130EE6__INCLUDED_

#include "Catalog.h"

class Admin : public Catalog
{

public:
	Admin();
	virtual ~Admin();

	void updateCatalog();

private:
	string adminEmail;
	string adminPass;

};
#endif // !defined(EA_2E32F519_B8EA_4117_9A34_72066B130EE6__INCLUDED_)
