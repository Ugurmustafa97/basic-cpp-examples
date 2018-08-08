#include <iostream>
#include "cashRegister.h"

int cashRegister::getCurrentBalance() const
{
    return cashOnHand;
} //end cashRegister::getCurrentBalance()

void cashRegister::acceptAmount(int amountIn)
{
    cashOnHand = cashOnHand + amountIn;
} // end cashRegister::acceptAmount()

cashRegister::cashRegister(int cashIn)
{
    if(cashIn >= 0)
        cashOnHand = cashIn;
    else
        cashOnHand = 500;
} // end cashRegister::cashRegister()

int dispenserType::getNoOfItems() const
{
    return numberOfItems;
} // end dispenserType::getNoOfItems

int dispenserType::getCost() const
{
    return cost;
} // end dispenserType::getCost()

void dispenserType::makeSale()
{
    numberOfItems--;
} // end dispenserType:.makeSale()

dispenserType::dispenserType(int setNoOfItems, int setCost)
{
    if(setNoOfItems >= 0)
        numberOfItems = setNoOfItems;
    else
        numberOfItems = 50;

    if(setCost >= 0)
        cost = setCost;
    else
        cost = 50;
} // end constructor
