///////////////////////////////////////////////////////////
//  Admin.h
//  Implementation of the Class Admin
//  Created on:      30-Nov-2025 7:58:31 PM
//  Original author: nara
///////////////////////////////////////////////////////////

#ifndef ADMIN_H
#define ADMIN_H

#include "Catalog.h"
class Admin : public Catalog
{

public:
	Admin();
	virtual ~Admin();
	bool loginAdmin(string pass);
	void manageCatalog(Catalog &updatecat);

private:
};
#endif // ADMIN_H
