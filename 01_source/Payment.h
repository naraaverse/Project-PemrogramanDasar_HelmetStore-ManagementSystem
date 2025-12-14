///////////////////////////////////////////////////////////
//  Payment.h
//  Implementation of the Class Payment
//  Created on:      30-Nov-2025 7:58:32 PM
//  Original author: nara
///////////////////////////////////////////////////////////

#ifndef PAYMENT_H
#define PAYMENT_H
class Payment
{

public:
	Payment();
	virtual ~Payment();
	void setPayment(double price, int quantity);
	double totalCost();

private:
	double orderCost;
	int orderQuantity;
};
#endif // PAYMENT_H
