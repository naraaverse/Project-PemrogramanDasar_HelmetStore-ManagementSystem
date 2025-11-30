///////////////////////////////////////////////////////////
//  Catalog.h
//  Implementation of the Class Catalog
//  Created on:      30-Nov-2025 7:46:25 PM
//  Original author: moog
///////////////////////////////////////////////////////////

#if !defined(EA_7A876C4C_BB5C_4386_B5E4_FB4B77F31B5F__INCLUDED_)
#define EA_7A876C4C_BB5C_4386_B5E4_FB4B77F31B5F__INCLUDED_

class Catalog
{

public:
	Catalog();
	virtual ~Catalog();

	void displayCatalog();
	void updateCatalog();

private:
	int availability;
	string helmetBrand;
	string helmetColor;
	double helmetPrice;
	string helmetType;

};
#endif // !defined(EA_7A876C4C_BB5C_4386_B5E4_FB4B77F31B5F__INCLUDED_)
