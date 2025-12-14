///////////////////////////////////////////////////////////
//  Payment.h
//  Implementation of the Class Payment
//  Created on:      30-Nov-2025 7:58:32 PM
//  Original author: nara
///////////////////////////////////////////////////////////

#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>
using namespace std;
class Payment
{

public:
	Payment();
	virtual ~Payment();
	bool processPayment(double totalCost, string &method);

private:
	bool verifyPayment();
};
#endif // PAYMENT_H
