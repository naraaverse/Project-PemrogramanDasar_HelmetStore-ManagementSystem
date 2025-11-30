///////////////////////////////////////////////////////////
//  Payment.h
//  Implementation of the Class Payment
//  Created on:      30-Nov-2025 7:58:32 PM
//  Original author: moog
///////////////////////////////////////////////////////////

#if !defined(EA_9A238272_BAEB_410a_BE98_83C05703DA01__INCLUDED_)
#define EA_9A238272_BAEB_410a_BE98_83C05703DA01__INCLUDED_

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
#endif // !defined(EA_9A238272_BAEB_410a_BE98_83C05703DA01__INCLUDED_)
