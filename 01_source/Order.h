///////////////////////////////////////////////////////////
//  Order.h
//  Implementation of the Class Order
//  Created on:      30-Nov-2025 7:58:31 PM
//  Original author: nara
///////////////////////////////////////////////////////////

#ifndef ORDER_H
#define ORDER_H

#include "Payment.h"
#include <string>
using namespace std;
class Order
{

public:
	Order();
	virtual ~Order();
	Payment *m_Payment;
	void helmetOrder();

private:
	string customerName;
	string helmetBrand;
	string helmetColor;
	string helmetType;
	string paymentMethod;
};
#endif // ORDER_H
