///////////////////////////////////////////////////////////
//  Payment.h
//  Implementation of the Class Payment
//  Created on:      30-Nov-2025 7:46:27 PM
//  Original author: moog
///////////////////////////////////////////////////////////

#if !defined(EA_917AB0A9_3231_42de_956C_34D42D50963E__INCLUDED_)
#define EA_917AB0A9_3231_42de_956C_34D42D50963E__INCLUDED_

class Payment
{

public:
	Payment();
	virtual ~Payment();

	double totalCost();

private:
	double orderCost;
	int orderQuantity;

};
#endif // !defined(EA_917AB0A9_3231_42de_956C_34D42D50963E__INCLUDED_)
