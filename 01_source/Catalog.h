///////////////////////////////////////////////////////////
//  Catalog.h
//  Implementation of the Class Catalog
//  Created on:      30-Nov-2025 7:58:31 PM
//  Original author: moog
///////////////////////////////////////////////////////////

#if !defined(EA_E4304A35_4257_4ee9_9B16_94F5D6D63016__INCLUDED_)
#define EA_E4304A35_4257_4ee9_9B16_94F5D6D63016__INCLUDED_

class Catalog
{

public:
	Catalog();
	virtual ~Catalog();

	void displayCatalog();

private:
	int availability;
	string helmetBrand;
	string helmetColor;
	double helmetPrice;
	string helmetType;

};
#endif // !defined(EA_E4304A35_4257_4ee9_9B16_94F5D6D63016__INCLUDED_)
