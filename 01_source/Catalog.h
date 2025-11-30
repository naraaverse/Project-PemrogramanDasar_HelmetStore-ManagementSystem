///////////////////////////////////////////////////////////
//  Catalog.h
//  Implementation of the Class Catalog
//  Created on:      30-Nov-2025 7:58:31 PM
//  Original author: nara
///////////////////////////////////////////////////////////

#ifndef CATALOG_H
#define CATALOG_H

#include <string>
using namespace std;
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
#endif // CATALOG_H
