///////////////////////////////////////////////////////////
//  Order.h
//  Implementation of the Class Order
//  Created on:      30-Nov-2025 7:46:24 PM
//  Original author: moog
///////////////////////////////////////////////////////////

#if !defined(EA_53548AA9_9310_41c9_A7E4_5135E54DCBC0__INCLUDED_)
#define EA_53548AA9_9310_41c9_A7E4_5135E54DCBC0__INCLUDED_

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
#endif // !defined(EA_53548AA9_9310_41c9_A7E4_5135E54DCBC0__INCLUDED_)
