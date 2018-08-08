// Definiton of class cashRegister

class cashRegister
{
public:
    int getCurrentBalance() const;
    // Function to show the current amount in the cash
    void acceptAmount(int amountIn);
    // Function to receive the amount deposited
    cashRegister(int cashIn = 500);

private:
    int cashOnHand; // variable to store the cash in the register
}; // end class cashRegister

// Definition of class dispenserType

class dispenserType
{
public:
    int getNoOfItems() const;
    // Functionn to show the number of items in the machine
    int getCost() const;
    // Function to show the cost of the item
    void makeSale();
    // Function to reduce the number of items by 1
    dispenserType(int setNoOfItems = 50, int setCost = 50);
    // Constructor

private:
    int numberOfItems; // variable to store the number of
                       // items in the dispenser
    int cost; // variable to store the cost of an ştem
}; // end class dispenserType
