///////////////////////////////////////////////////////////
//  Payment.cpp
//  Implementation of the Class Payment
//  Created on:      30-Nov-2025 7:58:32 PM
//  Original author: nara
///////////////////////////////////////////////////////////

#include "Payment.h"

Payment::Payment(){
	orderCost = 0.0;
	orderQuantity = 0;
}

Payment::~Payment(){

}

double Payment::totalCost(){
	return orderCost * orderQuantity;
}