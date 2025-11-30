///////////////////////////////////////////////////////////
//  Order.h
//  Implementation of the Class Order
//  Created on:      30-Nov-2025 7:58:31 PM
//  Original author: moog
///////////////////////////////////////////////////////////

#if !defined(EA_84692220_7AA5_45ef_8320_C664E3BC9174__INCLUDED_)
#define EA_84692220_7AA5_45ef_8320_C664E3BC9174__INCLUDED_

#include "OrderInfo.h"
#include "Payment.h"

class Order
{

public:
	Order();
	virtual ~Order();
	OrderInfo *m_OrderInfo;
	Payment *m_Payment;

	void helmetOrder();

private:
	string customerName;
	string helmetBrand;
	string helmetColor;
	string helmetType;
	string paymentMethod;

};
#endif // !defined(EA_84692220_7AA5_45ef_8320_C664E3BC9174__INCLUDED_)
